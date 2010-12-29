package thread.toast;

public class Eater implements Runnable{
	private ToastQueue finishedQueue;
	private int counter = 0;
	public Eater(ToastQueue finished){
		finishedQueue = finished;
	}
	public void run() {
		try {
			while(!Thread.interrupted()){
				Toast t = finishedQueue.take();
				if(t.getId()!=counter++||t.getStatus()!=Toast.Status.JAMMED){
					System.out.println(">>>Error:"+t);
					System.exit(1);
				}else{
					System.out.println("Chomp"+t);
				}
			}
			Toast t = finishedQueue.take();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		System.out.println("Eater off");
	}
	
}
