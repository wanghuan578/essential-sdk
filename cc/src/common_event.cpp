
#include "common_event.h"

#include <iostream>
#include <memory>
#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

#include "protocol/thrift/common_types.h"

#include "stage_handler.h"
#include "app_context.h"
#include "libtba/tba_rpc_message.h"

using namespace essential;


void read_cb(struct bufferevent *bev, void *user_data);
void write_cb(struct bufferevent *bev, void *user_data);
void event_cb(struct bufferevent *bev, short events, void *user_data);



CommonEvent::CommonEvent(string ip, int port)
{
	this->server_ip = ip;
	this->port = port;
}

CommonEvent::~CommonEvent()
{
}

int CommonEvent::Init()
{ 
#ifdef WIN32
    WSAData wsaData;
    WSAStartup(MAKEWORD(2, 0), &wsaData);
#endif
    struct sockaddr_in srv;
    memset(&srv, 0, sizeof(srv));
    cout << "server ip: " << server_ip.c_str() << ", port: " << port << endl;
    srv.sin_addr.s_addr = inet_addr(server_ip.c_str());
    srv.sin_family = AF_INET;
    srv.sin_port = htons(port);
 
    struct event_base *base = event_base_new();
    if (!base)
    {
		throw std::logic_error("Could not initialize libevent");
    }
 
    struct bufferevent *bev = bufferevent_socket_new(base, -1, BEV_OPT_CLOSE_ON_FREE);
    bufferevent_setcb(bev, read_cb, write_cb, event_cb, NULL);
    int flag = bufferevent_socket_connect(bev, (struct sockaddr *)&srv,sizeof(srv));
    bufferevent_enable(bev, EV_READ | EV_WRITE);
	
    if(-1 == flag)
    {
		throw std::logic_error("connect failed");
    }
 
    event_base_dispatch(base);
    event_base_free(base);

    return 0;
}

void read_cb(struct bufferevent *bev, void *user_data)
{
    char head_buff[4] = {0};  
	size_t len = bufferevent_read(bev, head_buff, 4);//get msg len
	int offset = 0;
	int msg_len = ((head_buff[offset++] & 0xff) << 24) |
					((head_buff[offset++] & 0xff) << 16) |
					((head_buff[offset++] & 0xff) <<  8) |
					(head_buff[offset++] & 0xff);
					
	
	char *message = new char[msg_len];
	
	memcpy(message, head_buff, 4);
	len = bufferevent_read(bev, message + 4, msg_len - 4);
	
	SL_Rpc_MessageParser::parse_head_ex<SL_Rpc_MessageHeadEx>((char*)message, sizeof(SL_Rpc_MessageHeadEx));//header parser
	SL_Rpc_MessageHeadEx *msg_head = (SL_Rpc_MessageHeadEx*)message;
	
	cout << "message type: " << msg_head->type << endl;
	int rtn = -1;	
	SL_Seda_RpcMessageEvent rpc_event;
	switch (msg_head->type)
	{
	case common::MessageType::MT_HELLO_NOTIFY:
		rtn = SL_Rpc_MessageParser::message_to_event<MsgHelloNotify>((char*)message, msg_len, (void*)bev, MainStageHandler::HelloNotify, &rpc_event);
		break;
	
	case login::MessageType::MT_CLIENT_LOGIN_RES:
		rtn = SL_Rpc_MessageParser::message_to_event<MsgClientLoginRes>((char*)message, msg_len, (void*)bev, MainStageHandler::ClientLoginRes, &rpc_event);
		break;
	
	case provider::MessageType::MT_SERVICE_REGISTER_RES:
		rtn = SL_Rpc_MessageParser::message_to_event<MsgServiceRegisterRes>((char*)message, msg_len, (void*)bev, MainStageHandler::ServiceRegisterRes, &rpc_event);
		break;
	
	case consumer::MessageType::MT_SERVICE_LIST_RES:
		rtn = SL_Rpc_MessageParser::message_to_event<MsgGetServiceListRes>((char*)message, msg_len, (void*)bev, MainStageHandler::GetServiceListRes, &rpc_event);
		break;
	
	case service::MessageType::MT_SERVICE_STATEY_RES:
		rtn = SL_Rpc_MessageParser::message_to_event<MsgServiceInfoSyncRes>((char*)message, msg_len, (void*)bev, MainStageHandler::GetServiceInfoSyncRes, &rpc_event);
		break;

	case consumer::MessageType::MT_SERVICE_LIST_SYNC_NOTIFY:
		rtn = SL_Rpc_MessageParser::message_to_event<MsgServiceListSyncNotify>((char*)message, msg_len, (void*)bev, MainStageHandler::ServiceListSyncNotify, &rpc_event);
		break;
	
	default:
		break;
	}

	if (rtn >= 0) 
	{
		ApplicationContext::Instance()->push(rpc_event);
	}

}

void write_cb(struct bufferevent *bev, void *user_data)
{
}

void event_cb(struct bufferevent *bev, short events, void *user_data)
{
    if (events & BEV_EVENT_EOF)
    {
        cout << "connection closed" << endl;
		
		bufferevent_free(bev);
    }
    else if (events & BEV_EVENT_ERROR)
    {
        cout << "server disconnection: " << strerror(errno) << endl;
		
        ApplicationContext::Instance()->shutdown_gracefully();

		bufferevent_free(bev);

		ApplicationContext::Instance()->on_close(strerror(errno));
    }
    else if(events & BEV_EVENT_CONNECTED)
    {
        //cout << "connect succeed" << endl;
    }
   
    
}

