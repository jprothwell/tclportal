package thread.customer;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
public class EvenChecker implements Runnable{
	
	private IntGenerator intGenerator;
	
	private int id;
	public EvenChecker(IntGenerator intGenerator,int id){
		this.intGenerator = intGenerator;
		this.id = id;
	}
	
	public void run() {
		while(!intGenerator.isCancel()){
			int val = intGenerator.next();
			if(val%2!=0){
				System.out.println(val+",not even");
				intGenerator.cancel();
			}
		}
	}
	
	public static void  test(IntGenerator intGenerator,int count){
		ExecutorService es = Executors.newCachedThreadPool();
		for(int i=0;i<count;i++){
			es.execute(new EvenChecker(intGenerator,i));
		}
		es.shutdown();
	}

	public static void test(EvenGenerator evenGenerator) {
		test(evenGenerator,10);
	}
}
