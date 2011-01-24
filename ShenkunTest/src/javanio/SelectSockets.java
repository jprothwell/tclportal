package javanio;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;

public class SelectSockets {

	public static int PORT_NUMBER = 1234;
	
	private ByteBuffer buffer = ByteBuffer.allocateDirect(1024);
	
	public static void main(String[] args) throws IOException {
		
		new SelectSockets().go(args);
	}

	private void go(String[] args) throws IOException {
		
		int port = PORT_NUMBER;
		if(args.length>0){
			port = Integer.parseInt(args[0]);
		}
		System.out.println("Listening on port:"+port);
		ServerSocketChannel serverChannel = ServerSocketChannel.open();
		ServerSocket serverSocket = serverChannel.socket();
		Selector selector = Selector.open();
		serverSocket.bind(new InetSocketAddress(port));
		serverChannel.configureBlocking(false);
		serverChannel.register(selector, SelectionKey.OP_ACCEPT);
		while(true){
			int n = selector.select();
			if(n == 0){
				continue;
			}
			Iterator it = selector.selectedKeys().iterator();
			while(it.hasNext()){
				SelectionKey key = (SelectionKey)it.next();
				if(key.isAcceptable()){
					ServerSocketChannel server = (ServerSocketChannel)key.channel();
					SocketChannel channel = server.accept();
					if(channel!=null){
						channel.configureBlocking(false);
						channel.register(selector, SelectionKey.OP_READ);
					}
//					sayHello(channel);
					buffer.clear();
					buffer.put("Hi there!".getBytes());
					buffer.flip();
					channel.write(buffer);
				}
				if(key.isReadable()){
//					readDataFromSocket(key);
					SocketChannel socketChannel = (SocketChannel)key.channel();
					int count;
					buffer.clear();
					while((count=socketChannel.read(buffer))>0){
						buffer.flip();
						while(buffer.hasRemaining()){
							socketChannel.write(buffer);
						}
						buffer.clear();
					}
					if(count<0){
						socketChannel.close();
					}
				}
				it.remove();
			}
		}
	}
	
	
	
//	private void readDataFromSocket(SelectionKey key) throws IOException {
//		SocketChannel socketChannel = (SocketChannel)key.channel();
//		int count;
//		buffer.clear();
//		while((count=socketChannel.read(buffer))>0){
//			buffer.flip();
//			while(buffer.hasRemaining()){
//				socketChannel.write(buffer);
//			}
//			buffer.clear();
//		}
//		if(count<0){
//			socketChannel.close();
//		}
//	}
//
//	private void sayHello(SocketChannel channel) throws IOException {
//		buffer.clear();
//		buffer.put("Hi there!".getBytes());
//		buffer.flip();
//		channel.write(buffer);
//	}

//	private void registerChannel(Selector selector, SocketChannel channel,
//			int opRead) throws IOException {
//		if(channel==null){
//			return;
//		}
//		channel.configureBlocking(false);
//		channel.register(selector, opRead);
//	}

}
