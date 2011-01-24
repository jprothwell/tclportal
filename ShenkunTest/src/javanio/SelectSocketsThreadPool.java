package javanio;

import com.sun.corba.se.spi.orbutil.threadpool.ThreadPool;

public class SelectSocketsThreadPool extends SelectSockets{
	
	private static final int MAX_THREADS = 5;
	
	private ThreadPool pool = new ThreadPool(MAX_THREADS);
	
	public static void main(String[] args) {
		
		
	}

}
