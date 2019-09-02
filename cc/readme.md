

## essential 框架SDK



### 一键安装

- make


### 调试

- ./sbin/test




### 参考代码


- src/test/test.cpp


```
#include "essential.h"

int on_state_update(std::shared_ptr<essential::service::ServiceInfo> ptr)
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


int main(int argc, char *const *argv)
{
	essential_client client;
	client.set_app_name("translate");
	client.set_host("192.168.131.42", 9999);
	client.set_state_hook(on_state_update);
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

