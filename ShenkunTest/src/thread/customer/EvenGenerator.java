package thread.customer;

public class EvenGenerator extends IntGenerator{
	
	private int currentValue = 0;
	public static void main(String[] args) {
		EvenChecker.test(new EvenGenerator());

	}

	@Override
	public int next() {
		++currentValue;
		++currentValue;
		return currentValue;
	}

}
