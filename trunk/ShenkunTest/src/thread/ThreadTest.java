package thread;

public class ThreadTest extends Thread{
	
	public int code;
	public ThreadTest(int code){
		this.code = code;
	}
	private static int TYPE = 1;
	
	private static synchronized void changeType(){
		if(TYPE==3){
			TYPE=1;
		}else{
			TYPE = TYPE+1;
		}
	}
	
	private static synchronized int getType(){
		return TYPE;
	}
	
	public static void main(String[] args) {
		ThreadTest t1 = new ThreadTest(1);
		ThreadTest t2 = new ThreadTest(2);
		ThreadTest t3 = new ThreadTest(3);
		t1.start();
		t2.start();
		t3.start();
	}
	
	@Override
	public void run() {
		while(true){
			if(this.code==getType()){
				System.out.println(this.code);
				changeType();
			}
		}
	}

}
