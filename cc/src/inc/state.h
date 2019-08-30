
#ifndef __STATE_H__
#define __STATE_H__

#include "protocol/thrift/service_types.h"

typedef int (*on_service_fn)(std::shared_ptr<essential::service::ServiceInfo> ptr);
typedef int (*state_fn)(int code);
#endif
