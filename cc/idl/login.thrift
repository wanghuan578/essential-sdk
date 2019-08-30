
include "common.thrift"
namespace cpp essential.login
//namespace java com.spirit.essential.rpc.protocol.thrift

//enum LoginMessageType
enum MessageType
{   
    MT_CLIENT_PASSWORD_LOGIN_REQ = 500,
    MT_CLIENT_LOGIN_RES,
    MT_CLIENT_LOGOUT_REQ,
    MT_CLIENT_LOGOUT_RES,
}

struct ClientPasswordLoginReq
{
    1:i64    	user_id,                        //登录名
    2:i64       client_random,                  //客户端随机数
    3:string    client_mac,                     //客户端mac
    4:string    client_version,                 //客户端版本号
    5:string    check_sum,                       //检验和( hex(md5(ClientPasswordLoginReqChecksum序列化)) )
}

struct ClientPasswordLoginReqChecksum
{
    1:i64    	user_id,                        //登录名
    2:string    password,                       //hex(md5(用户密码明文))
    3:i64       client_random,                  //客户端随机数
    4:i64       server_random,                  //服务端随机数
}

struct ClientLoginRes
{
    1:i32       error_code,
    2:string    error_text,
    3:string    session_ticket,                 //会话票据
}

struct LogoutReq
{
    1:i64       user_id,                        //用户id
    2:string    session_ticket,                 //会话票据
}

struct LogoutRes
{
    1:i32       error_code,
    2:i64       user_id,
}