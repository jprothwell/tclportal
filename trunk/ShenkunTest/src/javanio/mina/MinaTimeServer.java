package javanio.mina;

import java.nio.ByteBuffer;



public class MinaTimeServer {

	private static final int PORT = 9132;
	
	public static void main(String[] args) {
		
		ByteBuffer.setUseDirectBuffers(false);
	}

}
