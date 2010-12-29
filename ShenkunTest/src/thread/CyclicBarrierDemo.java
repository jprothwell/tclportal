package thread;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class CyclicBarrierDemo {

	private static int[] foots = {10,20,30};
	private static int[] bikes = {6,10,15};
	private static int[] cars = {2,3,4};
	
	public static void main(String[] args) {
		Runnable run = new Runnable(){

			public void run() {
				System.out.println("all arrive");
			}
			
		};
		CyclicBarrier cyclicBarrier = new CyclicBarrier(3,run);
		ExecutorService executor = Executors.newFixedThreadPool(3);
		executor.submit(new Tour(cyclicBarrier,foots,"foot"));
		executor.submit(new Tour(cyclicBarrier,bikes,"bike"));
		executor.submit(new Tour(cyclicBarrier,cars,"car"));
		executor.shutdown();
	}
	
}
class Tour implements Runnable{
	
	CyclicBarrier cyclicBarrier;
	int is[];
	String name;
	Tour(CyclicBarrier cyclicBarrier,int[] tours,String name){
		this.cyclicBarrier = cyclicBarrier;
		this.is = tours;
		this.name = name;
	}

	public void run() {
		System.out.println(name+"....reache one statin");
		try {
			cyclicBarrier.await();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (BrokenBarrierException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println(name+"....reache two statin");
		try {
			cyclicBarrier.await();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (BrokenBarrierException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println(name+"....reache three statin");
		try {
			cyclicBarrier.await();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (BrokenBarrierException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}