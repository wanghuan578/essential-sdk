
#ifndef __RPC_EVENT_QUEUE_H__
#define __RPC_EVENT_QUEUE_H__

#include <queue>
#include "libtba/tba_event.h"
#include "state.h"

class RpcEvent
{
public:
    static RpcEvent *Instance()
    {
		if(NULL == Instance_)
		{
			Instance_ = new RpcEvent();
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
    void set_stat_observer(on_service_fn fn);
	void sync(void *handle);   
	on_service_fn on_service;
	
private:
    RpcEvent();
    ~RpcEvent();

    std::queue<SL_Seda_RpcMessageEvent> msg_queue;
    volatile bool running;
    static RpcEvent *Instance_;
};
#endif

