package javanio;

import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class SystemTimer {
	
	private final static ScheduledExecutorService executor = Executors.newSingleThreadScheduledExecutor();
	
	private static final long tickUnit = Long.parseLong(System.getProperty("notify.systimer.tick", "50"));
	
	private static volatile long time = System.currentTimeMillis();
	
	static{
		executor.scheduleAtFixedRate(new TimerTicker(), tickUnit, tickUnit, TimeUnit.MICROSECONDS);
		Runtime.getRuntime().addShutdownHook(new Thread() {
				@Override
				public void run() {
				executor.shutdown();
				}
			});
	}
	
	private static class TimerTicker implements Runnable{

		@Override
		public void run() {
			time  = System.currentTimeMillis();
		}
		
	}
	

}
