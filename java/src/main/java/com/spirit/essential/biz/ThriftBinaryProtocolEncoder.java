package com.spirit.essential.biz;


import com.spirit.tba.exception.TbaException;
import com.spirit.tba.core.TbaEvent;
import com.spirit.tba.core.TbaRpcHead;
import com.spirit.tba.core.TbaRpcProtocolFactory;
import io.netty.buffer.ByteBuf;
import io.netty.channel.ChannelHandlerContext;
import io.netty.handler.codec.MessageToByteEncoder;
import org.apache.thrift.TBase;


public class ThriftBinaryProtocolEncoder extends MessageToByteEncoder<Object> {

	@Override
	protected void encode(ChannelHandlerContext ctx, Object msg, ByteBuf out) throws Exception {

		TbaEvent ev = (TbaEvent) msg;

		try {
			TbaRpcHead head = ev.getHead();
			TbaRpcProtocolFactory protocol = new TbaRpcProtocolFactory<TBase>((TBase)ev.getBody(), head, ev.getLength());
			byte[] buf = protocol.Encode().OutStream().toBytes();
			out.writeBytes(buf, 0, buf.length);
		}
		catch (TbaException e) {
			//log.error(e.getLocalizedMessage(), e);
		}
	}

}
