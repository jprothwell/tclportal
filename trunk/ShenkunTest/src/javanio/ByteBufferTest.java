package javanio;

import java.nio.ByteBuffer;

public class ByteBufferTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ByteBuffer bb = ByteBuffer.allocate(10);
		bb.put((byte)'h');
		bb.put((byte)'e');
		bb.put((byte)'l');
		bb.put((byte)'l');
		bb.put((byte)'o');
		
		bb.put(0,(byte)'c');
		bb.put((byte)'w').put((byte)'o').put((byte)'r').put((byte)'l').put((byte)'d');
		System.out.println("original():"+bb.toString());
		while(bb.hasRemaining()){
			System.out.print((char)bb.get());
		}
		bb.flip();
		System.out.println("flip():"+bb.toString());
		while(bb.hasRemaining()){
			System.out.print((char)bb.get());
		}
		System.out.println("");
		bb.clear();
		System.out.println("clear():"+bb.toString());
		System.out.println("");
		while(bb.hasRemaining()){
			
			System.out.print((char)bb.get());
		}
		System.out.println("");
		bb.rewind();
		System.out.println("rewind():"+bb.toString());
//		for(int i=0;i<bb.remaining();i++){
//			System.out.print((char)bb.get());
//		}
		
		while(bb.hasRemaining()){
			System.out.print((char)bb.get());
		}
		//positionÉèÖÃÎª0, limit=capacity
		//System.out.println(bb.remaining());
	}

}
