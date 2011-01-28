package pattern.oberver.product;

import java.util.Observable;
import java.util.Observer;

public class PriceObserver implements Observer{
	
	private float price;
	
	public void update(Observable ob, Object arg) {
		if(arg instanceof Float){
			price = (Float)arg;
			System.out.println("name has been changed to:"+price);
		}
		
	}
}
