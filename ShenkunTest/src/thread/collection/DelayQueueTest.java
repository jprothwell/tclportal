package thread.collection;

import java.util.Random;
import java.util.concurrent.DelayQueue;
import java.util.concurrent.Delayed;
import java.util.concurrent.TimeUnit;

public class DelayQueueTest {

	/**
	 * @param args
	 * @throws InterruptedException 
	 */
	public static void main(String[] args) throws InterruptedException {
		Random random = new Random();
		DelayQueue queue = new DelayQueue();
		for(int i=0;i<5;i++){
			queue.add(new DanoDelay(random.nextInt(1000)));
		}
		long last = 0;
		for(int i=0;i<5;i++){
			DanoDelay delay = (DanoDelay)(queue.take());
			long t = delay.getTime();
			System.out.println("time:"+t);
			if(i!=0){
				System.out.println("last:"+last);
				System.out.println("delta:"+(t-last));
			}
			last = t;
		}
	}
	
}
class DanoDelay implements Delayed{
	
	long trigger;
	DanoDelay(long i){
		System.out.println("point time:"+i);
		this.trigger = System.nanoTime()+i;
	}
	public long getTime() {
		return trigger;
	}
	public long getDelay(TimeUnit unit) {
		long n = trigger - System.nanoTime();
		return TimeUnit.NANOSECONDS.convert(n, unit);
	}

	public int compareTo(Delayed delay) {
		long i = trigger;
		long j = ((DanoDelay)delay).trigger;
		if(i<j){
			return -1;
		}else if(i>j){
			return 1;
		}
		return 0;
	}
	
}
