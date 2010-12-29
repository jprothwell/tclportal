package thread.syncOtherObject;

public class DualSynch {
	
	private Object sync = new Object();
	public synchronized void f(){
		for(int i=0;i<5;i++){
			System.out.println("f()");
			//Thread.yield();
		}
	}
	public void g(){
		synchronized(sync){
			for(int i=0;i<5;i++){
				System.out.println("g()");
				//Thread.yield();
			}
		}
	}
}
