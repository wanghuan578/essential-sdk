
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
	essential_client *set_host(string ip, int port);
	essential_client *set_state_hook(on_service_fn cb);
	void start();

private:
	string ip;
	int port;
	on_service_fn hook;

};

#endif
