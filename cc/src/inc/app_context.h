
#ifndef __APPLICATION_CONTEXT_H__
#define __APPLICATION_CONTEXT_H__

#include <queue>
#include "libtba/tba_event.h"
#include "state.h"
#include <string>

using namespace std;

class ApplicationContext
{
public:
    static ApplicationContext *Instance()
    {
		if(NULL == Instance_)
		{
			Instance_ = new ApplicationContext();
		}

		return Instance_;
    }

    void Destroy()
    {
		delete Instance_;
		Instance_ = NULL;
    }

    void push(SL_Seda_RpcMessageEvent ev);
    bool init();
	void sync(void *handle);   
	void set_app_name(string name);
	void set_weight(int weight);
	string get_app_name();
	int get_weight();
	void set_register_ip(string name);
	void set_register_port(int weight);
	string get_register_ip();
	int get_register_port();
	bool shutdown_gracefully();
	bool on_close(string error);
public:
	on_update_func on_update_service;
	on_get_service_list_func on_service_list;
	on_service_list_change_notify_func on_service_change_notify;
	on_close_func on_close_notify;

	void set_server_update_cb(on_update_func cb);
	void set_server_list_cb(on_get_service_list_func cb);
	void set_server_list_change_notify_cb(on_service_list_change_notify_func cb);
	void set_close_cb(on_service_list_change_notify_func cb);


private:
    ApplicationContext();
    ~ApplicationContext();

    std::queue<SL_Seda_RpcMessageEvent> msg_queue;
    volatile bool running;
    static ApplicationContext *Instance_;
	string app_name;
	int weight;
	string register_ip;
	int register_port;
};
#endif

