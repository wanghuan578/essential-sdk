
#include "rpc_queue.h"
#include <unistd.h>
#include <iostream>
#include <thread>
#include "message_mapping.h"
#include <event2/bufferevent.h> 

RpcEvent *RpcEvent::Instance_ = NULL;

void biz_loop(volatile bool &state, std::queue<SL_Seda_RpcMessageEvent> &queue);
void task(RpcEvent *rpc, bufferevent *handle);

RpcEvent::RpcEvent() 
:running(true)
{
}

RpcEvent::~RpcEvent()
{
}

bool RpcEvent::init()
{
    std::thread t(biz_loop, std::ref(running), std::ref(msg_queue));
    t.detach();
    return true;
}

void RpcEvent::push(SL_Seda_RpcMessageEvent ev)
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
		
		//std::cout << "wait..." << std::endl;

		usleep(100000);
    }

}

void RpcEvent::set_stat_observer(on_service_fn fn)
{
	this->on_service = fn;
}

void RpcEvent::sync(void *handle)
{
	std::thread t(on_service_loop, this, (bufferevent*)handle);
	t.detach();
}

void on_service_loop(RpcEvent *rpc, bufferevent *handle) 
{
	while(1)
	{
		std::shared_ptr<essential::service::ServiceInfo> ptr(new essential::service::ServiceInfo());
		
		int rtn = rpc->on_service(ptr);
		
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
        bufferevent_write((bufferevent*)handle, buff.buffer(), buff.data_size());
		
		sleep(1);
	}
}
