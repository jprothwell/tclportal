package thread;

public class SimpleThread extends Thread{
	
	private int count = 5;
	private static int threadCount = 0;
	public SimpleThread(){
		super(Integer.toString(threadCount++));
		this.start();
	}
	public String toString(){
		return "count number:"+count;
	}
	public void run(){
		while(true){
			System.out.println(this);
			if(--count==0){
				return;
			}
		}
	}
	public static void main(String[] args) {
		for(int i=0;i<5;i++){
			new SimpleThread();
		}
		
	}

}
