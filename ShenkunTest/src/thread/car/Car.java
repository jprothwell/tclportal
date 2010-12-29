package thread.car;
/**
 * 完成汽车打蜡和擦光的过程
 * @author kun.shen
 *
 */
public class Car {
	
	private boolean onWax = false;
	
	public synchronized void waxed(){
		onWax = true;
		notifyAll();
	}
	
	public synchronized void polish(){
		onWax = false;
		notifyAll();
	}
	
	public synchronized void waitForWaxing() throws InterruptedException{
		while(onWax == false){
			wait();
		}
	}
	
	public synchronized void waitForPolishing() throws InterruptedException{
		while(onWax == true){
			wait();
		}
	}
}
