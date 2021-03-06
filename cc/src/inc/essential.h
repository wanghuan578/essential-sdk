
#ifndef __ESSENTIAL_H__
#define __ESSENTIAL_H__

#include <string>
#include "state.h"

using namespace std;



class essential_client
{
public:
	essential_client();
	~essential_client();
	void set_essential_host(string ip, int port);
	void set_register_host(string ip, int port);
	void set_fetch_update_cb(on_update_func cb);
	void set_service_list_cb(on_get_service_list_func cb);
	void set_service_list_change_notify_cb(on_service_list_change_notify_func cb);
	void set_close_cb(on_close_func cb);
	void set_app_name(string name);
	void set_weight(int weight);
	void start();

private:
	string ip;
	int port;
	string register_ip;
	int register_port;
	int weight;
	string app_name;
	on_update_func server_update_func;
	on_get_service_list_func get_service_list_func;
	on_service_list_change_notify_func service_list_change_notify_func;
	on_close_func on_close_notify_func;

};

#endif
