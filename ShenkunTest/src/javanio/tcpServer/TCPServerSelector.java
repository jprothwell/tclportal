package javanio.tcpServer;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.util.Iterator;

public class TCPServerSelector {

	private static final int BUFFSIZE = 1024;
	
	private static final int TIMEOUT = 3000;
	
	public static void main(String[] args) throws IOException {
		
		if(args.length<1){
			System.out.println("error");
		}
		Selector selector = Selector.open();
		
		ServerSocketChannel listChannel = ServerSocketChannel.open();
		listChannel.socket().bind(new InetSocketAddress(12345));
		listChannel.configureBlocking(false);
		listChannel.register(selector, SelectionKey.OP_ACCEPT);
		
		TCPProtocol protocol = new EchoSelectorProtocol(BUFFSIZE);
		while(true){
			if(selector.select(TIMEOUT)==0){
				System.out.println(".");
				continue;
			}
			Iterator<SelectionKey> keys = selector.selectedKeys().iterator();
			while(keys.hasNext()){
				SelectionKey key = keys.next();
				if(key.isAcceptable()){
					protocol.handleAccept(key);
				}
				if(key.isReadable()){
					protocol.handleRead(key);
				}
				if(key.isValid()&&key.isWritable()){
					protocol.handleWrite(key);
				}
			}
		}
		
		}

}
