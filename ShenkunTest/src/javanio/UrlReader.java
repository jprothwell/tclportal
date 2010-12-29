package javanio;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;

public class UrlReader {

	private Charset charset = Charset.forName("GBK");
	
	private SocketChannel channel;
	
	public void readHtmlContent(){
		
		try {
			InetSocketAddress socketAddress = new InetSocketAddress("http://58.61.156.221/tclPaypal",80);
			channel = SocketChannel.open(socketAddress);
			channel.write(charset.encode("GET /HTTP/1.1\r\n\r\n"));
			ByteBuffer buffer = ByteBuffer.allocate(1024);
			while(channel.read(buffer)!=-1){
				buffer.flip();
				System.out.println(charset.decode(buffer));
				buffer.clear();
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally{
			if(channel!=null){
				try {
					channel.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}
	public static void main(String[] args) {
		new UrlReader().readHtmlContent();
		
	}

}
