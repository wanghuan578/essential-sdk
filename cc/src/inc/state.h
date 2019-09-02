
#ifndef __SERVICE_ACTION_H__
#define __SERVICE_ACTION_H__

#include "protocol/thrift/service_types.h"
#include "protocol/thrift/common_types.h"

typedef int (*on_update_func)(std::shared_ptr<essential::service::ServiceInfo> ptr);
typedef int (*on_get_service_list_func)(std::list<essential::common::RouteInfo> service_list);
typedef int (*on_service_list_change_notify_func)(essential::common::RouteInfo info, string mode);

#endif
