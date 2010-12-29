package thread.restourant;

public class WaitPerson implements Runnable {
	
	Restourant restourant;
	public WaitPerson(Restourant restourant) {
		this.restourant = restourant;
	}
	public void run() {
		try{
			while(!Thread.interrupted()){
				synchronized(this){
					while(restourant.meal==null){
						wait();
					}
				}
				System.out.println("WaitPerson ...");
				synchronized(restourant.chef){
					restourant.meal=null;
					restourant.chef.notifyAll();
				}
			}
		}catch(Exception ex){
		
		}
	}
}
