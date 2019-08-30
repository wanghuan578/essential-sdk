
#ifndef __MESSAGE_MAPPING_H__
#define __MESSAGE_MAPPING_H__

#include "libtba/tba_rpc_message.h"
#include "protocol/thrift/common_types.h"
#include "protocol/thrift/login_types.h"
#include "protocol/thrift/provider_types.h"
#include "protocol/thrift/comsumer_types.h"
#include "protocol/thrift/service_types.h"

using namespace essential;

typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, common::HelloNotify, common::MessageType::MT_HELLO_NOTIFY> MsgHelloNotify;
typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, common::CommonRes, common::MessageType::MT_HELLO_RES> MsgHelloRes;

typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, login::ClientPasswordLoginReq, login::MessageType::MT_CLIENT_PASSWORD_LOGIN_REQ> MsgClientLoginReq;
typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, login::ClientLoginRes, login::MessageType::MT_CLIENT_LOGIN_RES> MsgClientLoginRes;

typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, provider::ServiceRegisterReq, provider::MessageType::MT_SERVICE_REGISTER_REQ> MsgServiceRegisterReq;
typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, provider::ServiceRegisterRes, provider::MessageType::MT_SERVICE_REGISTER_RES> MsgServiceRegisterRes;

typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, consumer::ServiceListReq, consumer::MessageType::MT_SERVICE_LIST_REQ> MsgGetServiceListReq;
typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, consumer::ServiceListRes, consumer::MessageType::MT_SERVICE_LIST_RES> MsgGetServiceListRes;

typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, service::ServiceInfo, service::MessageType::MT_SERVICE_STATE_SYNC> MsgServiceInfoSyncReq;
typedef SL_Rpc_Message<SL_Rpc_MessageHeadEx, common::CommonRes, service::MessageType::MT_SERVICE_STATEY_RES> MsgServiceInfoSyncRes;


#endif
