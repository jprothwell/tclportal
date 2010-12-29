package thread.ornament.garden;

import java.util.concurrent.*;
public class OrnametalGarden {

	/**
	 * @param args
	 * @throws InterruptedException 
	 */
	public static void main(String[] args) throws InterruptedException {
		ExecutorService exec = Executors.newCachedThreadPool();
		for(int i=0;i<5;i++){
			exec.execute(new Entrance(i));
		}
		TimeUnit.SECONDS.sleep(2000);
		Entrance.cancel();
		exec.shutdown();
		if(!exec.awaitTermination(250, TimeUnit.MICROSECONDS)){
			System.out.println("some tasks were not terminated");
		}
		System.out.println(" Total:"+Entrance.getTotalCount());
		System.out.println("sum of Entrances:"+Entrance.sumEntrances());
	}

}
