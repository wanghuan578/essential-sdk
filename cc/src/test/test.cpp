
#include <iostream>
//#include <stdio.h>
//#include <unistd.h>
#include "essential.h"


using namespace std;

int times = 0;

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
	client.set_host("192.168.131.42", 9999);
	client.set_state_hook(on_state_update);
	client.start();

	while(1)
	{
		sleep(10);
	}
}
