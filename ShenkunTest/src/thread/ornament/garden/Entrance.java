package thread.ornament.garden;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.TimeUnit;

public class Entrance implements Runnable{

	private static Count count = new Count();
	private static List<Entrance> list = new ArrayList<Entrance>();
	private int number = 0;
	private int id;
	private static volatile boolean canceled = false;
	public static void cancel(){
		canceled = true;
	}
	public Entrance(int id){
		this.id = id;
		list.add(this);
	}
	public void run() {
		while(!canceled){
			synchronized(this){
				++number;
			}
			System.out.println(this+":Total:"+count.increment());
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				System.out.println("sleep interrupted");
			}
		}
	}
	
	public synchronized int getValue(){
		return number;
	}
	public String toString(){
		return "Entrance"+id+":"+getValue();
	}
	public static int getTotalCount(){
		return count.value();
	}
	public static int sumEntrances(){
		int sum = 0;
		for(Entrance entrance:list){
			sum += entrance.getValue();
		}
		return sum;
	}
}
