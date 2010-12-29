package thread.car;

public class WaxOn implements Runnable{
	
	private Car car;
	
	public WaxOn(Car car){
		this.car = car;
	}
	
	public void run() {
			try {
				while(!Thread.interrupted()){
					System.out.println("wait on");
					car.waxed();
					car.waitForPolishing();
				}
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
	}

}
