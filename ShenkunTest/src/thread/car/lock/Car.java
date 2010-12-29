package thread.car.lock;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Car {
	
	private Lock lock = new ReentrantLock();
	
	private Condition condition = lock.newCondition(); 
	
	private boolean waxOn = false;
	
	public void waxed(){
		lock.lock();
		try{
			waxOn = true;
			System.out.println("wax");
			condition.signalAll();
		}finally{
			lock.unlock();
		}
		
	}
	
	public  void polish(){
		lock.lock();
		try{
			waxOn = false;
			System.out.println();
			condition.signalAll();
		}finally{
			lock.unlock();
		}
		
	}
	
	public  void waitForWaxing() throws InterruptedException{
		lock.lock();
		try{
			while(waxOn == false){
				condition.await();
			}
		}finally{
			lock.unlock();
		}
		
	}
	
	public  void waitForPolishing() throws InterruptedException{
		lock.lock();
		try{
			while(waxOn == true){
				condition.await();
			}
		}finally{
			lock.unlock();
		}
		
	}
}
