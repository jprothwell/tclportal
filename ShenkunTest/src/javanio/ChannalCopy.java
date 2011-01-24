package javanio;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.nio.channels.WritableByteChannel;

public class ChannalCopy {
		
		public static void main(String[] args) throws IOException{
			ReadableByteChannel rc = Channels.newChannel(System.in);
			WritableByteChannel wc = Channels.newChannel(System.out);
			copy(rc,wc);
			rc.close();
			wc.close();
		}

		private static void copy(ReadableByteChannel rc, WritableByteChannel wc) throws IOException {
			ByteBuffer buffer = ByteBuffer.allocate(1024);
			while(rc.read(buffer)!=-1){
				buffer.flip();
				while(buffer.hasRemaining()){
					wc.write(buffer);
				}
				buffer.clear();
			}
			
		}
}
