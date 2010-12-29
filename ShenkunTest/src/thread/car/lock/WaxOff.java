package thread.car.lock;

public class WaxOff implements Runnable{
	
	private Car car;
	
	public WaxOff(Car car){
		this.car = car;
	}
	
	public void run() {
			try {
				while(!Thread.interrupted()){
					car.waitForWaxing();
					System.out.println("waitForWaxing");
					car.polish();
				}
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
	}
}
