
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

essential_client *essential_client::set_host(string ip, int port)
{
	this->ip = ip;
	this->port = port;
	return this;
}

essential_client *essential_client::set_state_hook(on_service_fn cb)
{
	hook = cb;
	return this;
}

void essential_client::set_app_name(string name) 
{
	app_name = name;
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
	ApplicationContext::Instance()->set_stat_observer(hook);
	ApplicationContext::Instance()->set_app_name(app_name);

	CommonEvent *event = new CommonEvent(ip, port);

	std::thread t(asynchronous, event);
	t.detach();
}
