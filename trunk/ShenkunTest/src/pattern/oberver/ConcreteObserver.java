package pattern.oberver;

public class ConcreteObserver implements Observer{

	public void update() {
		System.out.println("I am notified");
	}

}
