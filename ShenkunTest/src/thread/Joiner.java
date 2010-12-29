package thread;

public class Joiner extends Thread{
	private Sleeper sleeper;
	
	public Joiner(String name ,Sleeper sleeper){
		super(name);
		this.sleeper = sleeper;
		start();
	}
	public void run(){
		try {
			System.out.println(getName()+"Joiner����joinִ��ǰ");
			sleeper.join();
		} catch (InterruptedException e) {
			System.out.println("join interrupt");
		}
		System.out.println(getName()+"Joiner����joinִ�����");
	}
	public static void main(String[] args) {
		Sleeper sleeper1 = new Sleeper(1000,"sleepOne, ");
		Sleeper sleeper2 = new Sleeper(1000,"sleepTwo, ");
		Joiner joiner1 = new Joiner("joinerOne ",sleeper1);
		Joiner joiner2 = new Joiner("joinerTwo ",sleeper2);
		sleeper2.interrupt();
	}

}

class Sleeper extends Thread{
	private int sleepTime;
	public Sleeper(int time,String threadName){
		super(threadName);
		this.sleepTime = time;
		start();
	}
	public void run(){
		try {
			System.out.println(getName()+"��ʼ����Sleeper��");
			sleep(sleepTime);
		} catch (InterruptedException e) {
			System.out.println(getName()+"���߱����");
		}
		System.out.println(getName()+"���߽���Sleeper��");
	}
}