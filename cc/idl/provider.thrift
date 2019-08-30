
include "common.thrift"
//namespace java com.spirit.essential.rpc.protocol.thrift
namespace cpp essential.provider

//enum ProviderMessageType
enum MessageType
{   
    MT_SERVICE_REGISTER_REQ = 1200,
    MT_SERVICE_REGISTER_RES,
}

struct ServiceRegisterReq
{
	1:common.RouteInfo route,
}

struct ServiceRegisterRes
{
    1:i32    	error_code,
    2:string    error_text,
}