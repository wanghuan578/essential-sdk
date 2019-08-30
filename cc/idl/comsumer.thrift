
include "common.thrift"
//namespace java com.spirit.essential.rpc.protocol.thrift
namespace cpp essential.consumer

//enum ConsumerMessageType
enum MessageType
{   
    MT_SERVICE_LIST_REQ = 1100,
    MT_SERVICE_LIST_RES,
    MT_SERVICE_LIST_SYNC_NOTIFY,
    MT_SERVICE_LIST_SYNC_RES,
}

struct ServiceListReq
{
	1:i32       service_id,
    2:string    service_name,
}

struct ServiceListRes
{
    1:i32    					error_code,
    2:string    				error_text,
	3:list<common.RouteInfo> 	route_list,
}

struct ServiceListSyncNotify
{
    1:i32       					service_id,
    2:string    					service_name,
	3:string						mode, //append, drop
	4:common.RouteInfo 			route,
}

struct ServiceListSyncRes
{
    1:i32    	error_code,
    2:string    error_text,
}