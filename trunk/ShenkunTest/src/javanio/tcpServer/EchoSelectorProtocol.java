package javanio.tcpServer;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.SocketChannel;

public class EchoSelectorProtocol implements TCPProtocol{
	
	private int bufferSize;
	public EchoSelectorProtocol(int bufferSize) {
		this.bufferSize = bufferSize;
	}

	public void handleAccept(SelectionKey key) throws IOException {
		SocketChannel channel = (SocketChannel)key.channel();
		channel.configureBlocking(false);
		channel.register(key.selector(), SelectionKey.OP_READ,ByteBuffer.allocate(bufferSize));
	}

	public void handleRead(SelectionKey key) throws IOException {
		SocketChannel channel = (SocketChannel)key.channel();
		ByteBuffer buffer = (ByteBuffer)key.attachment();
		long bytesRead = channel.read(buffer);
		if(bytesRead == -1){
			channel.close();
		}else if(bytesRead>0){
			key.interestOps(SelectionKey.OP_READ);
		}
		
	}

	public void handleWrite(SelectionKey key) throws IOException {
		ByteBuffer buffer = (ByteBuffer)key.attachment();
		buffer.flip();
		SocketChannel channel = (SocketChannel)key.channel();
		channel.write(buffer);
		if(!buffer.hasRemaining()){
			key.interestOps(SelectionKey.OP_READ);
		}
		buffer.compact();
	}

}
