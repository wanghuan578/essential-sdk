
#include "message_mapping.h"

using namespace std;



class MainStageHandler
{
public:
	MainStageHandler();
	~MainStageHandler();

	static int HelloNotify(void *socket_handler,  void *rpc_message, void *seda_stagehandler);
	static int ClientLoginRes(void *socket_handler,  void *rpc_message, void *seda_stagehandler);
	static int ServiceRegisterRes(void *socket_handler,  void *rpc_message, void *seda_stagehandler);
	static int GetServiceListRes(void *socket_handler,  void *rpc_message, void *seda_stagehandler);
	static int GetServiceInfoSyncRes(void *socket_handler,  void *rpc_message, void *seda_stagehandler);



	
};
