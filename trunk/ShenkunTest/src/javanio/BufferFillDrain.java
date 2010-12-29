package javanio;

import java.nio.CharBuffer;

public class BufferFillDrain {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		CharBuffer buffer = CharBuffer.allocate(100);
		while(fillBuffer(buffer)){
			buffer.flip();
			drainBuffer(buffer);
			buffer.clear();
		}

	}

	private static void drainBuffer(CharBuffer buffer) {
		while(buffer.hasRemaining()){
			System.out.print(buffer.get());
		}
		System.out.println("");
	}
	
	
	private static boolean fillBuffer(CharBuffer buffer) {
		if(index>=strings.length){
			return false;
		}
		String string = strings[index++];
		for(int i=0;i<string.length();i++){
			buffer.put(string.charAt(i));
		}
		return true;
	}
	
	private static int index = 0;
	
	private static String[] strings = {
		"a","b","c","d","e"
	};
};
