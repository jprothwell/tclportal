package pattern.oberver;

public interface Subject {
	/**
	 * 登记一个新的观察者对象
	 * @param observer
	 */
	public void attache(Observer observer);
	/**
	 * 删除一个登记过的观察者对象
	 */
	public void datach(Observer observer);
	/**
	 * 调用这个方法通知所有登记过的观察者
	 */
	void notifyObservers();
}
