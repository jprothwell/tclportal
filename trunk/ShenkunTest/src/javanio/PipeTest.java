package javanio;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.Channels;
import java.nio.channels.Pipe;
import java.nio.channels.ReadableByteChannel;
import java.nio.channels.WritableByteChannel;
import java.nio.channels.Pipe.SinkChannel;
import java.util.Random;

public class PipeTest {

	public static void main(String[] args) throws IOException {
		WritableByteChannel out = Channels.newChannel(System.out);
		ReadableByteChannel workerChannel = startWorker(10);
		ByteBuffer buffer = ByteBuffer.allocate(100);
		while(workerChannel.read(buffer)>=0){
			buffer.flip();
			out.write(buffer);
			buffer.clear();
		}
	}

	private static ReadableByteChannel startWorker(int reps) throws IOException {
		Pipe pipe = Pipe.open();
		Worker worker = new Worker(pipe.sink(),reps);
		worker.start();
		return pipe.source();
	}
	
	private static class Worker extends Thread{
		
		WritableByteChannel channel;
		private int reps;
		
		public Worker(SinkChannel sink, int reps) {
			this.channel = sink;
			this.reps = reps;
		}
		
		public void run(){
			ByteBuffer buffer = ByteBuffer.allocate(100);
			try {
				for(int i=0;i<this.reps;i++){
					doSomeWork(buffer);
					while(channel.write(buffer)>0){
							
					}
				}
				this.channel.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		private String[] products = {"aaa","bbb"};
		
		private Random rand = new Random();
		
		private void doSomeWork(ByteBuffer buffer) {
			int product = rand.nextInt(products.length);
			buffer.clear();
			buffer.put(products[product].getBytes());
			buffer.put("\r\n".getBytes());
			buffer.flip();
		}
	}
}
