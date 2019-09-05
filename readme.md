

## essential 框架SDK



### 一键安装

- make


### 调试

- ./sbin/test




### 参考代码


- src/test/test.cpp


#### 服务状态刷新
```
#include "essential.h"

int on_server_state_update(std::shared_ptr<essential::service::ServiceInfo> ptr)
{
	cout << "state update..." <<endl;
	
	ptr->app.ppid = 1;
	ptr->app.pid = 2288;
	ptr->app.upstream_flow_total = 56347812 + times * rand()%1000;
	ptr->app.upstream_flow_bytes = 1000 + rand()%1000;
	ptr->app.downstream_flow_total = 11223344 + times * rand()%2000;;
	ptr->app.downstream_flow_bytes = 2000 + rand()%2000;
	ptr->app.current_connections = 800 + rand()%1500;

	ptr->system.cpu_num = 4;
	ptr->system.mem_total = 99999999;
	ptr->system.mem_avail = 50000000 + rand()%50000000;

	ptr->route.name = "translate";
	ptr->route.address.ip = "127.0.0.1";
	ptr->route.address.port = 9999;

	times++;

	return 0;
}
```

#### 获取服务列表

```
int on_get_service_list(std::vector<essential::common::RouteInfo> service_list)
{
	cout << "<------------------------------------------------------>" << endl;
	cout << "on_get_service_list" << endl;
	for (auto &service : service_list)
	{
		cout << "name: " << service.name << endl;
		cout << "weight: " << service.weight << endl;
		cout << "ip: " << service.address.ip << ", port: " << service.address.port << endl;
	}
	cout << "<------------------------------------------------------->" << endl;
	return 0;
}
```

#### 服务变更通知

```
int on_service_list_change_notify(essential::common::RouteInfo route, string mode)
{
	cout << "<------------------------------------------------------>" << endl;
	cout << "on_service_list_change_notify" << endl;
	cout<<"mode: " << mode << endl;
	cout<<"route - name: " << route.name << endl;
	cout<<"route - weight: " << route.weight << endl;
	cout<<"route - address.ip: " << route.address.ip << endl;
	cout<<"route - address.port: " << route.address.port << endl;

	cout << "<------------------------------------------------------>" << endl;
	return 0;
}
```

#### 异常通知

```
int on_close_notify(string error)
{
	cout << "on_close_notify: " << error << endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	exit(0);
	return 0;
}
```


#### 主函数调用


```
int main(int argc, char *const *argv)
{
	essential_client client;
	client.set_app_name("transcode");
	client.set_weight(100);
	client.set_essential_host("192.168.131.42", 9999);
	client.set_register_host("10.0.0.1", 9999);
	client.set_fetch_update_cb(on_server_state_update);
	client.set_service_list_cb(on_get_service_list);
	client.set_service_list_change_notify_cb(on_service_list_change_notify);
	client.set_close_cb(on_close_notify);
	
	client.start();


	while(1)
	{
		sleep(10);
	}
}
```



### 相关资源

- [essential](https://github.com/wanghuan578/essential)(essential 服务端)
- [libtba](https://github.com/wanghuan578/libtba-cc)(序列化\反序列化方案)


### 作者和贡献者信息


- spirit(57810140@qq.com)

