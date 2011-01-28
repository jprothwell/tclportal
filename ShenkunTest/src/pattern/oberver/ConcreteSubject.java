package pattern.oberver;

import java.util.Enumeration;
import java.util.Vector;

public class ConcreteSubject implements Subject{

	private Vector observersVector = new Vector();
	
	public void attache(Observer observer) {
		observersVector.addElement(observer);
	}

	public void datach(Observer observer) {
		observersVector.remove(observer);
	}

	public void notifyObservers() {
		Enumeration enumeration = obervers();
		while(enumeration.hasMoreElements()){
			((Observer)enumeration.nextElement()).update();
		}
	}

	private Enumeration obervers() {
		return ((Vector)observersVector.clone()).elements();
	}

}
