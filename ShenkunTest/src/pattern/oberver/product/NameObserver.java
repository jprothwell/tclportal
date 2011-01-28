package pattern.oberver.product;

import java.util.Observable;
import java.util.Observer;


public class NameObserver implements Observer{
	
	private String name = "";
	
	public void update(Observable ob, Object arg) {
		if(arg instanceof String){
			name = (String)arg;
			System.out.println("name has been changed to:"+name);
		}
		
	}
}
