
#ifndef __COMMON_EVENT_H__
#define __COMMON_EVENT_H__

#include <string>

using namespace std;

class CommonEvent
{
public:
	CommonEvent(string server_ip, int port);
	~CommonEvent();
	int Init();
private:
	string server_ip;
	int port;
};

#endif
