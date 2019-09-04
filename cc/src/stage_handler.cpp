
#include "stage_handler.h"
#include "libtba/tba_rpc_message.h"
#include "protocol/thrift/common_types.h"
#include <iostream>
#include <cstdlib>
#include <event2/bufferevent.h>  
#include "app_context.h"

using namespace std;
using namespace essential;

MainStageHandler::MainStageHandler()
{

}

MainStageHandler::~MainStageHandler()
{

}

int MainStageHandler::HelloNotify(void *socket_handler, void *rpc_message, void *seda_stagehandler)
{
	MsgHelloNotify *notify = (MsgHelloNotify*)rpc_message;

	cout<<"MsgHelloNotify - server_random: " << notify->body_.server_random << endl;
	
   
	MsgClientLoginReq login_req;
	login_req.head_.source = 100;
	login_req.body_.user_id = 88888888;
	login_req.body_.client_random = notify->body_.server_random;
	
	tba_byte_buffer buff(512);
	login_req.serialize_ex<tba_byte_buffer>(&buff);

	bufferevent_write((bufferevent*)socket_handler, buff.buffer(), buff.data_size());
	
	delete notify;

	return 0;
}

int MainStageHandler::ClientLoginRes(void *socket_handler,  void *rpc_message, void *seda_stagehandler)
{
	MsgClientLoginRes *res = (MsgClientLoginRes*)rpc_message;

	//cout<<"MsgClientLoginRes - error_code: " << res->body_.error_code << endl;
	cout<<"MsgClientLoginRes: " << res->body_.error_text << endl;
	
   
	MsgServiceRegisterReq req;

	common::AddressInfo address;
	address.ip = ApplicationContext::Instance()->get_register_ip();
	address.port = ApplicationContext::Instance()->get_register_port();

	common::RouteInfo route;
	route.address = address;
	route.weight = ApplicationContext::Instance()->get_weight();
	route.name = ApplicationContext::Instance()->get_app_name();
	req.body_.route = route;
	
	tba_byte_buffer buff(512);
	req.serialize_ex<tba_byte_buffer>(&buff);

	bufferevent_write((bufferevent*)socket_handler, buff.buffer(), buff.data_size());
	
	delete res;

	return 0;
}

int MainStageHandler::ServiceRegisterRes(void *socket_handler,  void *rpc_message, void *seda_stagehandler)
{
	MsgServiceRegisterRes *res = (MsgServiceRegisterRes*)rpc_message;
	
	//cout<<"MsgServiceRegisterRes - error_code: " << res->body_.error_code << endl;
	cout<<"MsgServiceRegisterRes: " << res->body_.error_text << endl;

	if(common::ErrorCode::OK != res->body_.error_code)
	{
		delete res;
		return -1;
	}	

	ApplicationContext::Instance()->sync(socket_handler);

	MsgGetServiceListReq req;
	req.body_.service_name = ApplicationContext::Instance()->get_app_name();
	tba_byte_buffer buff(512);
	req.serialize_ex<tba_byte_buffer>(&buff);
	bufferevent_write((bufferevent*)socket_handler, buff.buffer(), buff.data_size());
	
	delete res;

	return 0;
}

int MainStageHandler::GetServiceListRes(void *socket_handler,	void *rpc_message, void *seda_stagehandler)
{
	MsgGetServiceListRes *res = (MsgGetServiceListRes*)rpc_message;

	//cout<<"MsgGetServiceListRes - error_code: " << res->body_.error_code << endl;
	cout<<"MsgGetServiceListRes: " << res->body_.error_text << endl;

	on_get_service_list_func func = ApplicationContext::Instance()->on_service_list;
	if (NULL != func)
	{
		func(res->body_.route_list);
	}

	delete res;

	return 0;
}

int MainStageHandler::GetServiceInfoSyncRes(void *socket_handler,  void *rpc_message, void *seda_stagehandler)
{
	MsgServiceInfoSyncRes *res = (MsgServiceInfoSyncRes*)rpc_message;
	
	//cout<<"MsgServiceInfoSyncRes - error_code: " << res->body_.error_code << endl;
	cout<<"MsgServiceInfoSyncRes: " << res->body_.error_text << endl;
	
	
	delete res;

	return 0;
}

int MainStageHandler::ServiceListSyncNotify(void *socket_handler,  void *rpc_message, void *seda_stagehandler)
{
	MsgServiceListSyncNotify *notify = (MsgServiceListSyncNotify*)rpc_message;

    cout<<"MsgServiceListSyncNotify - mode: " << notify->body_.mode << endl;

	on_service_list_change_notify_func func = ApplicationContext::Instance()->on_service_change_notify;
	if (NULL != func)
	{
		func(notify->body_.route, notify->body_.mode);
	}

	delete notify;

	return 0;
}




