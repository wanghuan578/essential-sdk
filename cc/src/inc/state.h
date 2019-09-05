
#ifndef __SERVICE_ACTION_H__
#define __SERVICE_ACTION_H__

#include <string>
#include "protocol/thrift/service_types.h"
#include "protocol/thrift/common_types.h"

using namespace std;

typedef int (*on_update_func)(std::shared_ptr<essential::service::ServiceInfo> ptr);
typedef int (*on_get_service_list_func)(std::vector<essential::common::RouteInfo> service_list);
typedef int (*on_service_list_change_notify_func)(essential::common::RouteInfo info, string mode);
typedef int (*on_close_func)(string error);

#endif
