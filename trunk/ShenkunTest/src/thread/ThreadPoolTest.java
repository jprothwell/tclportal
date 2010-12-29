package thread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class ThreadPoolTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ExecutorService execut =  Executors.newFixedThreadPool(10);
		for(int i=0;i<1000;i++){
			execut.execute(new RunnableDemo(i));
		}
		execut.shutdown();
	}

}
class RunnableDemo implements Runnable{
	
	int index = 0;
	public RunnableDemo(int i) {
		this.index = i;
	}

	public void run() {
		System.out.println(Thread.currentThread().getName()+":"+index+":"+System.currentTimeMillis());
	}
	
}