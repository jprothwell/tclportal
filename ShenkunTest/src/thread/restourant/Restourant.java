package thread.restourant;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Restourant {
	
	public Meal meal;
	
	ExecutorService executor = Executors.newCachedThreadPool();
	Chef chef = new Chef(this);
	WaitPerson waitPerson = new WaitPerson(this);
	public Restourant(){
		executor.execute(chef);
		executor.execute(waitPerson);
	}
	public static void main(String[] args){
		new Restourant();
	}
}
