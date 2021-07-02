package com.spirit.essential.biz;

import java.util.List;
import com.spirit.essential.rpc.protocol.thrift.*;
import com.spirit.tba.exception.TbaException;
import com.spirit.tba.core.TbaRpcByteBuffer;
import com.spirit.tba.core.TbaRpcEventParser;
import com.spirit.tba.core.TbaRpcHead;
import com.spirit.tba.core.TbaRpcProtocolFactory;
import io.netty.buffer.ByteBuf;
import io.netty.channel.ChannelHandlerContext;
import io.netty.handler.codec.ByteToMessageDecoder;

public class ThriftBinaryProtocolDecoder extends ByteToMessageDecoder {

    @Override
    protected void decode(ChannelHandlerContext ctx, ByteBuf in, List<Object> out) throws Exception {
        // TODO Auto-generated method stub

        while (in.readableBytes() > 4) {
            
        	//in.markReaderIndex();

            int msg_len = in.readInt();
            TbaRpcByteBuffer msg = new TbaRpcByteBuffer(msg_len);
            msg.writeI32(msg_len);

            for (int i = 0; i < msg_len - 4; i++) {
                msg.writeByte(in.readByte());
            }

            TbaRpcEventParser parser = new TbaRpcEventParser(msg);
            TbaRpcHead header = parser.Head();

            //log.info("Msg Type: {}", header.getType());

            try {
                switch (header.getType()) {

                    case RpcEventType.MT_COMMON_HELLO_NOTIFY: {
                        TbaRpcProtocolFactory<HelloNotify> protocol = new TbaRpcProtocolFactory<HelloNotify>(msg);
                        out.add(protocol.Decode(HelloNotify.class));
                    }
                    break;

                    case RpcEventType.MT_CLIENT_LOGIN_RES: {
                        TbaRpcProtocolFactory<ClientLoginRes> protocol = new TbaRpcProtocolFactory<ClientLoginRes>(msg);
                        out.add(protocol.Decode(ClientLoginRes.class));
                    }
                    break;

                    case RpcEventType.MT_SERVICE_REGISTER_RES: {
                        TbaRpcProtocolFactory<ServiceRegisterRes> protocol = new TbaRpcProtocolFactory<ServiceRegisterRes>(msg);
                        out.add(protocol.Decode(ServiceRegisterRes.class));
                    }
                    break;

                    case RpcEventType.MT_SERVICE_LIST_RES: {
                        TbaRpcProtocolFactory<ServiceListRes> protocol = new TbaRpcProtocolFactory<ServiceListRes>(msg);
                        out.add(protocol.Decode(ServiceListRes.class));
                    }
                    break;

                    case RpcEventType.MT_SERVICE_LIST_CHANGE_NOTIFY: {
                        TbaRpcProtocolFactory<ServiceListSyncNotify> protocol = new TbaRpcProtocolFactory<ServiceListSyncNotify>(msg);
                        out.add(protocol.Decode(ServiceListSyncNotify.class));
                    }
                    break;

                    default:
                        break;
                }
            }
            catch(TbaException e){
                //log.error(e.getLocalizedMessage(), e);
            }
            catch(InstantiationException e){
                //log.error(e.getLocalizedMessage(), e);
            }
            catch(IllegalAccessException e){
                //log.error(e.getLocalizedMessage(), e);
            }



        }
        
      

        
    }

}
