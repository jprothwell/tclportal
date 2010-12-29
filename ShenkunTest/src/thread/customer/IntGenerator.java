package thread.customer;

public abstract class IntGenerator {
	
	private volatile boolean canceled = false;
	
	public void cancel(){
		canceled = true;
	}
	
	public boolean isCancel(){
		return canceled;
	}
	
	public abstract int next();
}
