package pattern.oberver;

public interface Subject {
	/**
	 * �Ǽ�һ���µĹ۲��߶���
	 * @param observer
	 */
	public void attache(Observer observer);
	/**
	 * ɾ��һ���Ǽǹ��Ĺ۲��߶���
	 */
	public void datach(Observer observer);
	/**
	 * �����������֪ͨ���еǼǹ��Ĺ۲���
	 */
	void notifyObservers();
}
