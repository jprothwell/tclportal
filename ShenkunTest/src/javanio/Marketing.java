package javanio;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.ByteBuffer;
import java.nio.channels.GatheringByteChannel;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class Marketing {

	private static final String DEMOGRAPHIC = "d://test.txt";
	
	public static void main(String[] args) throws IOException {
		int reps = 10;
		if(args.length>0){
			reps = Integer.parseInt(args[0]);
		}
		FileOutputStream fos = new FileOutputStream(DEMOGRAPHIC);
		GatheringByteChannel gatherChannel = fos.getChannel();
		ByteBuffer[] bs = utterBS(reps);
		while(gatherChannel.write(bs)>0){
			//todo
		}
		fos.close();
	}
	
	private static String[] col1 = {
		"aaa","bbb","ccc"
	};
	private static String[] col2 = {
		"ddd","eee","fff"
	};
	private static String[] col3 = {
		"ggg","hhh","kkk"
	};
	private static ByteBuffer[] utterBS(int reps) throws UnsupportedEncodingException {
		List list = new LinkedList();
		for(int i=0;i<reps;i++){
			list.add(pickRandom(col1,""));
			list.add(pickRandom(col2,""));
			list.add(pickRandom(col3,""));
		}
		ByteBuffer[] bufs = new ByteBuffer[list.size()];
		list.toArray(bufs);
		return bufs;
	}
	private static Random rand = new Random();
	
	private static Object pickRandom(String[] col, String stuffix) throws UnsupportedEncodingException {
		String string = col[rand.nextInt(col.length)];
		int total = string.length() + stuffix.length();
		ByteBuffer buf = ByteBuffer.allocate(total);
		buf.put(string.getBytes("US-ASCII"));
		buf.put(stuffix.getBytes("US-ASCII"));
		buf.flip();
		return buf;
	}

}
