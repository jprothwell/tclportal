package thread;

import java.util.concurrent.atomic.AtomicLong;

public class AtomicDemo extends Thread{
	static CountBank countBank;
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		countBank = new CountBank(100);
		AtomicDemo atomicDemo3 = new AtomicDemo();
		AtomicDemo atomicDemo2 = new AtomicDemo();
//		for(int i=0;i<10;i++){
			atomicDemo3.start();
			atomicDemo2.start();
//		}
	
	}
	
	public void run(){
		this.countBank.withDraw(10);
	}
}

class  CountBank{
	
	AtomicLong al;
	public CountBank(long num){
		al = new AtomicLong(num);
	}
	
	public void deposit(long num){
		al.addAndGet(num);
	}
	
	public void withDraw(long num) {
		long oldValue = al.get();//Ô­Ê¼Ç®Êý
		System.out.println("oldValue::"+oldValue);
		if(oldValue>num){
			try {
				Thread.sleep(3000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			if(al.compareAndSet(oldValue, oldValue-num)){
				System.out.println("success::"+al.get());
			}
			
		}else{
			System.out.println("fail");
		}
	}
}
