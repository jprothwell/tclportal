package thread;

import java.util.Random;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.FutureTask;

/**
 * futureTask主线程可以或许其他线程的计算结果
 * @author kun.shen
 *
 */
public class FutureTestDemo {

	public static void main(String[] args) {
		Callable ce = new PrivateAccount();
		FutureTask ft = new FutureTask(ce);
		Thread td = new Thread(ft);
		td.start();
		int total = 1000;
		System.out.println("total:"+total);
//		if(!ft.isDone()){
//			try {
//				Thread.sleep(1000);
//			} catch (InterruptedException e) {
//				// TODO Auto-generated catch block
//				e.printStackTrace();
//			}
//		}
		System.out.println("futureTask end.......");
		int privaetCount = 0;
		try {
			privaetCount = (Integer) ft.get();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ExecutionException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("all::::"+(total+privaetCount));
	}
}

class PrivateAccount implements Callable{
	
	int totalMoney;
	
	public Object call() throws Exception {
		totalMoney = new Integer(new Random().nextInt(10000));
		System.out.println("privateAccount:::::"+totalMoney);
		return totalMoney;
	}
	
}