package thread.toast;

public class Jammer implements Runnable{
	
	private ToastQueue butteredQueue,finishedQueue;
	public Jammer(ToastQueue buttered,ToastQueue finished){
		butteredQueue = buttered;
		finishedQueue = finished;
	}
	public void run() {
		try {
			while(!Thread.interrupted()){
					Toast t = butteredQueue.take();
					t.jam();
					System.out.println(t);
					finishedQueue.put(t);
			}
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		System.out.println("jammer off");
	}

}
