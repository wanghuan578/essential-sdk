package com.spirit.essential.task;

import com.alibaba.fastjson.JSON;
import com.spirit.essential.biz.RpcEventType;
import com.spirit.essential.rpc.protocol.thrift.*;
import com.spirit.essential.session.session;
import com.spirit.tba.core.TbaEncryptType;
import com.spirit.tba.core.TbaEvent;
import com.spirit.tba.core.TbaRpcHead;

import java.util.Random;
import java.util.concurrent.ScheduledThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

import static com.spirit.essential.rpc.protocol.thrift.QualityMessageType.MT_SERVICE_QUALITY_SYNC;

public class Task {

    private static final Task _instance = new Task();
    private Task(){}
    public static Task getInstance(){
        return _instance;
    }

    private ScheduledThreadPoolExecutor scheduled;

    public void observation() {
        scheduled = new ScheduledThreadPoolExecutor(1);
        scheduled.scheduleAtFixedRate(new Runnable() {
            @Override
            public void run() {
                //RouteInfo route = new RouteInfo();
                AddressInfo addr =  new AddressInfo();
                addr.ip = "localhost";
                addr.port = 8080;
                RouteInfo route = new RouteInfo();
                route.name = "translate";
                route.weight = 99;
                route.address = addr;

                SystemInfo system = new SystemInfo();
                cpuInfo(system);
                memoryInfo(system);

                ServiceInfo req = new ServiceInfo();
                req.route = route;
                req.system = system;

                TbaRpcHead head = new TbaRpcHead(MT_SERVICE_QUALITY_SYNC.getValue());
                session.getInstance().getCtx().write(new TbaEvent(head, req, 1024, TbaEncryptType.DISABLE));
                session.getInstance().getCtx().flush();
                System.out.println("ServiceInfo: " + JSON.toJSONString(req, true));
            }
        }, 0, 10000, TimeUnit.MILLISECONDS);
    }

    public void stop() {
        if (scheduled != null) {
            scheduled.shutdownNow();
        }
    }

    public void cpuInfo(SystemInfo info) {
        Random r = new Random();
        info.task_num = r.nextInt(100);
        info.cpu_num = 4;
    }

    public void memoryInfo(SystemInfo info) {
        Random r = new Random();
        info.mem_total = 456343434;
        info.mem_used = 12345 + r.nextInt(500);
        info.mem_avail = info.mem_total - info.mem_used;
    }
}
