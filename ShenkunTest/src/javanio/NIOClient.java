package javanio;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.nio.charset.CharsetEncoder;
import java.util.Iterator;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class NIOClient {

	static int size = 100;
	static InetSocketAddress ip = new InetSocketAddress("localhost",12345);
	static CharsetEncoder encoder = Charset.forName("GB2312").newEncoder();
	
	public static void main(String[] args) {
		ExecutorService exec = Executors.newFixedThreadPool(size);
		for(int index=0;index<size;index++){
			exec.execute(new Download(index));
		}
		exec.shutdown();
	}
	
	static class Download implements Runnable{
	
		private int index;
		
		public Download(int index){
			this.index = index;
		}
		
		public void run() {
			long start = System.currentTimeMillis();
			SocketChannel client;
			try {
				client = SocketChannel.open();
				client.configureBlocking(false);
				Selector selector = Selector.open();
				client.register(selector, SelectionKey.OP_CONNECT);
				client.connect(ip);
				ByteBuffer buffer = ByteBuffer.allocate(1024*8);
				int total = 0;
				FOR: for(;;){
					selector.select();
					Iterator<SelectionKey> iter =  selector.selectedKeys().iterator();
					while(iter.hasNext()){
						SelectionKey key = iter.next();
						iter.remove();
						if(key.isConnectable()){
							SocketChannel channel = (SocketChannel)key.channel();
							if(channel.isConnectionPending()){
								channel.finishConnect();
							}
							channel.write(encoder.encode(CharBuffer.wrap("hello.."+index)));
							channel.register(selector, SelectionKey.OP_READ);
						}else if(key.isReadable()){
								SocketChannel channel = (SocketChannel)key.channel();
								int count = channel.read(buffer);
								if(count>0){
									total += count;
									buffer.clear();
								}else{
									client.close();
									break FOR;
								}
							}
						}
					}
				double time = (System.currentTimeMillis() - start)*1.0/1000;
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			
		}
		
	}
}
