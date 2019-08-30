
include "common.thrift"
//namespace java com.spirit.essential.rpc.protocol.thrift
namespace cpp essential.service

//enum QualityMessageType
enum MessageType
{   
	MT_SERVICE_STATE_SYNC 		= 1500,
	MT_SERVICE_STATEY_RES,
}

struct ApplicationInfo
{
	1:i32						pid,
	2:i32						ppid,
	3:i32						upstream_flow_total,
	4:i32						upstream_flow_bytes,
	5:i32						downstream_flow_total,
	6:i32						downstream_flow_bytes,
	7:i32						current_connections,
	8:i32						max_connections,
}

struct SystemInfo
{
	1:i32				task_num,
	2:i16				cpu_num,
	3:double			cpu_percent,
	4:i32 				mem_total,
	5:i32 				mem_used,
	6:i64				mem_avail,
	7:double			mem_percent,
	8:i32				swap_total,
	9:i32				swap_used,
	10:i32				swap_avail,
	11:double			swap_percent,
	12:double 			load_average,
}

struct ServiceInfo
{
	1:ApplicationInfo 			app,
	2:SystemInfo 				system,
	3:common.RouteInfo      	route,
}