package pattern.oberver.product;

public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Product p1 = new Product();
		NameObserver nameObserver = new NameObserver();
		PriceObserver priceObserver = new PriceObserver();
		p1.addObserver(nameObserver);
		p1.addObserver(priceObserver);
		p1.setName("Æ»¹û");
		p1.setPrice(8);
		p1.setName("éÙ×Ó");
	}

}
