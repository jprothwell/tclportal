package thread;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class CallableDemo {

	/**
	 * @param args
	 * @throws ExecutionException 
	 * @throws InterruptedException 
	 */
	public static void main(String[] args) throws InterruptedException, ExecutionException {
		ExecutorService executor = Executors.newFixedThreadPool(5);
		for(int i =0;i<5;i++){
			Future<String> ft = executor.submit(new CallableTest(5-i));
			System.out.println(ft.get());
			if(ft.get().equals("2")){
				
				executor.shutdown();
				return;
			}
		}
		
		executor.shutdown();
	}

}

class CallableTest implements Callable<String>{
	
	private int tastCount=0;
	private int id = tastCount++;
	private int number;
	public CallableTest(int num){
		this.number = num;
	}
	
	public String call() throws Exception {
		Thread.sleep(2000);
		return Integer.toString(number);
	}
	
}