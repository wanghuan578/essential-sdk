
#include "essential.h"
#include <iostream>
#include "common_event.h"
#include <stdio.h>
#include <unistd.h>
#include "app_context.h"
#include <thread>


essential_client::essential_client()
{

}

essential_client::~essential_client()
{

}

void essential_client::set_essential_host(string ip, int port)
{
	this->ip = ip;
	this->port = port;
}

void essential_client::set_register_host(string ip, int port)
{
	this->register_ip = ip;
	this->register_port = port;
}

void essential_client::set_fetch_update_cb(on_update_func cb)
{
	server_update_func = cb;
}

void essential_client::set_service_list_cb(on_get_service_list_func cb)
{
	get_service_list_func = cb;
}

void essential_client::set_close_cb(on_close_func cb)
{
	on_close_notify_func = cb;
}
void essential_client::set_service_list_change_notify_cb(on_service_list_change_notify_func cb)
{
	service_list_change_notify_func = cb;
}

void essential_client::set_app_name(string name) 
{
	app_name = name;
}

void essential_client::set_weight(int weight)
{
	this->weight = weight;
}

void asynchronous(CommonEvent *event)
{
	try
	{
		event->Init();
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void essential_client::start()
{
	ApplicationContext::Instance()->init();
	ApplicationContext::Instance()->set_app_name(app_name);
	ApplicationContext::Instance()->set_register_ip(register_ip);
	ApplicationContext::Instance()->set_register_port(register_port);
	ApplicationContext::Instance()->set_weight(weight);
	ApplicationContext::Instance()->set_server_update_cb(server_update_func);
	ApplicationContext::Instance()->set_server_list_cb(get_service_list_func);
	ApplicationContext::Instance()->set_server_list_change_notify_cb(service_list_change_notify_func);
	ApplicationContext::Instance()->set_close_cb(on_close_notify_func);

	CommonEvent *event = new CommonEvent(ip, port);

	std::thread t(asynchronous, event);
	t.detach();
}
