package thread.car.lock;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class WaxOMatic {

	public static void main(String[] args) {
		Car car = new Car();
		ExecutorService executor = Executors.newCachedThreadPool();
		executor.execute(new WaxOff(car));
		executor.execute(new WaxOn(car));
		executor.shutdown();
	}

}
