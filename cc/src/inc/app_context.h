
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
    void set_stat_observer(on_service_fn fn);
	void sync(void *handle);   
	on_service_fn on_service;
	void set_app_name(string name);
	string get_app_name();	
private:
    ApplicationContext();
    ~ApplicationContext();

    std::queue<SL_Seda_RpcMessageEvent> msg_queue;
    volatile bool running;
    static ApplicationContext *Instance_;
	string app_name;
};
#endif

