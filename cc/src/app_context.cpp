
#include "app_context.h"
#include <unistd.h>
#include <iostream>
#include <thread>
#include "message_mapping.h"
#include <event2/bufferevent.h> 
#include <chrono>

ApplicationContext *ApplicationContext::Instance_ = NULL;

void biz_loop(volatile bool &state, std::queue<SL_Seda_RpcMessageEvent> &queue);
void service_update_loop(ApplicationContext *context, bufferevent *handle);

ApplicationContext::ApplicationContext() 
:running(true)
{
}

ApplicationContext::~ApplicationContext()
{
}

bool ApplicationContext::init()
{
    std::thread t(biz_loop, std::ref(running), std::ref(msg_queue));
    t.detach();
    return true;
}

void ApplicationContext::push(SL_Seda_RpcMessageEvent ev)
{
    msg_queue.push(ev);
}

void biz_loop(volatile bool &state, std::queue<SL_Seda_RpcMessageEvent> &queue)
{
    std::cout << "rpc thread queue start" << std::endl;

    while (state) 
    {
		while (!queue.empty())
		{
		    SL_Seda_RpcMessageEvent ev = queue.front();
		    ev.rpc_proc(ev.socket_handler, ev.rpc_message, NULL);
		    queue.pop();
		}
		

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}

void ApplicationContext::set_server_update_cb(on_update_func cb)
{
	this->on_update_service = cb;
}

void ApplicationContext::set_server_list_cb(on_get_service_list_func cb)
{
	on_service_list = cb;
}

void ApplicationContext::set_server_list_change_notify_cb(on_service_list_change_notify_func cb)
{
	on_service_change_notify = cb;
}

void ApplicationContext::set_app_name(string name)
{
	app_name = name;
}

void ApplicationContext::set_weight(int weight)
{
	this->weight = weight;
}

int ApplicationContext::get_weight()
{
	return weight;
}

void ApplicationContext::set_register_ip(string ip)
{
	register_ip = ip;
}
void ApplicationContext::set_register_port(int port)
{
	register_port = port;
}
string ApplicationContext::get_register_ip()
{
	return register_ip;
}
int ApplicationContext::get_register_port()
{
	return register_port;
}

string ApplicationContext::get_app_name()
{
	return app_name;
}

void ApplicationContext::sync(void *handle)
{
	std::thread t(service_update_loop, this, (bufferevent*)handle);
	t.detach();
}

void service_update_loop(ApplicationContext *context, bufferevent *handle)
{
	while(context->running)
	{
		std::shared_ptr<essential::service::ServiceInfo> ptr(new essential::service::ServiceInfo());
		on_update_func func = context->on_update_service;
		if (NULL == func)
		{
			break;
		}

		int rtn = func(ptr);
		
		if (1000 == rtn) 
		{
			break;
		}

        MsgServiceInfoSyncReq req;

        req.body_.app = ptr->app;
        req.body_.system = ptr->system;
        req.body_.route = ptr->route;

        tba_byte_buffer buff(512);
        req.serialize_ex<tba_byte_buffer>(&buff);
        //if (context->running)
        {
        	bufferevent_write((bufferevent*)handle, buff.buffer(), buff.data_size());
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        //std::this_thread::sleep_for(std::chrono::seconds(10));
	}
}

bool ApplicationContext::shutdown_gracefully()
{
	running = false;

	while(1)
	{

	}
}
