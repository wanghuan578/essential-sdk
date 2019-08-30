
namespace cpp essential.common
//namespace java com.spirit.essential.rpc.protocol.thrift

//enum CommonMessageType
enum MessageType
{
    MT_HELLO_NOTIFY		= 100,
	MT_HELLO_RES,
    MT_KEEPALIVE_REQ,
    MT_KEEPALIVE_RES,
}

enum ErrorCode
{
    OK = 0,                              	//成功
    
    LOGIN_FAILED  = 100,              	 	//登录失败
    LOGNAME_EXIST,                       	//用户名已存在
    LOGNAME_NOT_EXIST,                   	//用户名不存在
    PASSWORD_ERROR,                      	//密码错误
	SERVICE_REGISTER_FAILED,      			//服务注册失败

}

struct AddressInfo
{
    1:string    ip,
    2:i16       port,
}

struct RouteInfo
{
	1:i32       			id,
    2:string       			name,
	3:i16					weight,
	4:AddressInfo			address,
}

struct HelloNotify
{
    1:i32       error_code,
    2:string    error_text,
    3:string    service_name,
    4:i32       service_id,
    5:i64       server_random,
    6:i64       server_time,
}

struct SessionTicket
{
    1:i32       user_id,                        
    2:string    user_name,                     
    3:string    email,                          
    4:string    nick_name,                     
    5:string    client_ip,                      
    6:string    client_mac,                    
    7:string    client_version,                
    8:i32       app_id,                         
    9:string    session_id,                    
    10:string   session_key,  
    11:i64      create_time, 
    12:i64      end_time,
}

struct CommonNull
{
}

struct CommonRes
{
    1:i32       error_code,
    2:string    error_text,
}

struct KeepAliveReq
{
    1:i32       id,
    2:i64       timestamp_begin,
    3:string    serivce_quality,
}

struct KeepAliveRes
{
    1:i32       error_code,
    2:string    error_text,
    3:i32       id,
    4:i64       timestamp_begin,
    5:i64       timestamp_end,
}