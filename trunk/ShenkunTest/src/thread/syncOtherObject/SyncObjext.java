package thread.syncOtherObject;

public class SyncObjext {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		final DualSynch dual = new DualSynch();
		new Thread(){
			public void run(){
				dual.f();
			}
		}.start();
		dual.g();
	}

}
