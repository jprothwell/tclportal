package javanio;

import java.io.FileInputStream;
import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.nio.charset.CharsetDecoder;
import java.util.Iterator;

public class NIOServer {
	protected int block = 4096;
	protected Selector selector;
	protected String filename = "E:/tcl/datasql.pdb";
	protected ByteBuffer clientBuffer = ByteBuffer.allocate(4096);
	protected CharsetDecoder decoder;
	
	public NIOServer(int port) throws IOException{
		selector = this.getSelector(port);
		Charset charset = Charset.forName("GB2312");
	}
	private Selector getSelector(int port) throws IOException {
		ServerSocketChannel server = ServerSocketChannel.open();
		Selector sel = Selector.open();
		server.socket().bind(new InetSocketAddress(port));
		server.configureBlocking(false);
		server.register(sel, SelectionKey.OP_ACCEPT);
		return sel;
	}
	
	public void listen(){
		
			try {
				for(;;){
					selector.select();
					Iterator<SelectionKey> iter = selector.selectedKeys().iterator();
					while(iter.hasNext()){
						SelectionKey key = iter.next();
						iter.remove();
						handleKey(key);
					}
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		
	}
	private void handleKey(SelectionKey key) throws IOException {
		if(key.isAcceptable()){
			ServerSocketChannel server = (ServerSocketChannel)key.channel();
			SocketChannel channel = server.accept();
			channel.configureBlocking(false);
			channel.register(selector, SelectionKey.OP_READ);
		}else if(key.isReadable()){
			 SocketChannel channel = (SocketChannel) key.channel();
			 int count = channel.read(clientBuffer);
			 if(count>0){
				 clientBuffer.flip();
				 CharBuffer charBuffer = decoder.decode(clientBuffer);
				 SelectionKey wkey = channel.register(selector, SelectionKey.OP_WRITE);
				 wkey.attach(new HandleClient());
			 }else{
				 channel.close();
			 }
			 clientBuffer.clear();
		}else if(key.isWritable()){
			SocketChannel channel = (SocketChannel)key.channel();
			HandleClient handle = (HandleClient)key.attachment();
			ByteBuffer block = handle.readBlock();
			if(block!=null){
				channel.write(block);
			}else{
				handle.close();
				channel.close();
			}
		}
		
	}
	
	public static void main(String[] args){
		int port = 12345;
		try {
			NIOServer server = new NIOServer(port);
			while(true){
				server.listen();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	public class HandleClient{
		protected FileChannel channel;
		protected ByteBuffer buffer;
		public HandleClient() throws IOException{
			this.channel = new FileInputStream(filename).getChannel();
			this.buffer = ByteBuffer.allocate(4096);
		}
		public ByteBuffer readBlock(){
			try {
				buffer.clear();
				int count = channel.read(buffer);
				buffer.flip();
				if(count<=0){
					return null;
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			return buffer;
		}
		
		public void close(){
			try {
				channel.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
