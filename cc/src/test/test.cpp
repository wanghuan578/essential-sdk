
#include <iostream>
#include "essential.h"


using namespace std;

int times = 0;

int on_server_state_update(std::shared_ptr<essential::service::ServiceInfo> ptr)
{
	
	cout << "on_server_state_update: " << endl;
	
	ptr->app.ppid = 1;
	ptr->app.pid = 2288;
	ptr->app.upstream_flow_total = 7812 + times * rand()%1000;
	ptr->app.upstream_flow_bytes = 1000 + rand()%1000;
	ptr->app.downstream_flow_total = 3344 + times * rand()%1000;
	ptr->app.downstream_flow_bytes = 2000 + rand()%2000;
	ptr->app.current_connections = 800 + rand()%1500;

	ptr->system.cpu_num = 4;
	ptr->system.mem_total = 981690417;
	ptr->system.mem_avail = 50000000 + rand()%50000000;

	ptr->route.name = "translate";
	ptr->route.weight = 70; 
	ptr->route.address.ip = "10.0.0.1";
	ptr->route.address.port = 9999;

	times++;

	return 0;
}

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

int main(int argc, char *const *argv)
{
	essential_client client;
	client.set_app_name("translate");
	client.set_weight(70);
	client.set_essential_host("192.168.131.42", 9999);
	client.set_register_host("10.0.0.1", 9999);
	client.set_fetch_update_cb(on_server_state_update);
	client.set_service_list_cb(on_get_service_list);
	client.set_service_list_change_notify_cb(on_service_list_change_notify);
	client.start();


	while(1)
	{
		sleep(10);
	}
}
