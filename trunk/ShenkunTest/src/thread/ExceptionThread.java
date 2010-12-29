package thread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ThreadFactory;

public class ExceptionThread implements Runnable{

	public void run(){
		throw new RuntimeException();
	}
	public static void main(String[] args) {
//		try{
			ExecutorService exec = Executors.newCachedThreadPool(new HandleThreadFactory());
			exec.submit(new ThreadException());
//			exec.shutdown();
//		}catch(Exception ex ){
//			System.out.println("catch exception");
//		}
	}

}

class ThreadException implements Runnable{

	public void run() {
		Thread thread = Thread.currentThread();
		System.out.println("run by"+thread.getName());
		System.out.println("<><>"+thread.getUncaughtExceptionHandler());
		throw new RuntimeException();
		
	}
	
}

class MyUnHandleThreadException implements Thread.UncaughtExceptionHandler{

	public void uncaughtException(Thread t, Throwable e) {
		System.out.println("my thread"+e);
		
	}
	
}

class HandleThreadFactory implements ThreadFactory{

	public Thread newThread(Runnable r) {
		Thread t = new Thread(r);
		t.setUncaughtExceptionHandler(new MyUnHandleThreadException());
		System.out.println("factoryHandle:"+t.getUncaughtExceptionHandler());
		return t;
	}

}