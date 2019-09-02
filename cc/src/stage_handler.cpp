
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
	address.ip = "127.0.0.1";
	address.port = 9999;
	common::RouteInfo route;
	route.address = address;
	route.weight = 99;
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

	MsgGetServiceListReq req;

	req.body_.service_name = "translate";
	
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
#if 0	
	MsgServiceInfoSyncReq req;
	
	common::RouteInfo route;
	common::AddressInfo address;
	address.ip = "192.168.189.130";
	address.port = 9990;
	route.address = address;
	route.weight = 99;
	route.name = "translate";

	service::ApplicationInfo app;
	app.ppid = 1;
	app.pid = 1199;
	app.current_connections = 1000 + rand()%1000;

	service::SystemInfo system;
	system.cpu_num = 4;
	system.mem_total = 99999999;
	system.mem_avail = 50000000 + rand()%50000000;

	req.body_.app = app;
	req.body_.system = system;
	req.body_.route = route;
	
	tba_byte_buffer buff(512);
	req.serialize_ex<tba_byte_buffer>(&buff);

	bufferevent_write((bufferevent*)socket_handler, buff.buffer(), buff.data_size());
#endif

	ApplicationContext::Instance()->sync(socket_handler);

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
	cout<<"route - name: " << notify->body_.route.name << endl;
	cout<<"route - weight: " << notify->body_.route.weight << endl;
	cout<<"route - address.ip: " << notify->body_.route.address.ip << endl;
	cout<<"route - address.port: " << notify->body_.route.address.port << endl;



        delete notify;

        return 0;
}




