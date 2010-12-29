package thread.restourant;

public class Chef implements Runnable {
	
	private Restourant res;
	private int count;
	public Chef(Restourant res){
		this.res = res;
	}

	public void run() {
		try {
			while(!Thread.interrupted()){
				synchronized(this){
					while(res.meal!=null){
						wait();
					}
				}//synchronized
				if(++count==10){
					System.out.println("Big Number");
					res.executor.shutdown();
				}
				System.out.println("chef ...");
				synchronized(res.waitPerson){
					res.meal = new Meal(count);
					res.waitPerson.notifyAll();
				}
			}		
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
}
