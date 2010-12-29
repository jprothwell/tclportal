package thread;
import java.util.concurrent.*;
/**
 * �ػ��̣߳������ػ��߳���ɣ��ػ��߳̽�����ִ��
 * @author kun.shen
 *
 */
public class DaemonDemo implements Runnable{
	
	private int i;
	public DaemonDemo(int i){
		this.i = i;
	}
	public static void main(String[] args) throws InterruptedException {
		for(int i=0;i<10;i++){
			Thread thread = new Thread(new DaemonDemo(i));
			thread.setDaemon(true);
			thread.start();
		}
		System.out.println("all thread start");
		TimeUnit.MILLISECONDS.sleep(100);
	}

	public void run() {
		try {
			while(true){
				TimeUnit.MILLISECONDS.sleep(50);
				System.out.println("daemon thread"+Thread.currentThread());
			}
			
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
	}

}
