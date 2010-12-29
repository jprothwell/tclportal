package pattern.factory.simple;

public class FruitGardener {
	
	public static Fruit factory(String which) throws BadFruitException{
		if(which.equalsIgnoreCase("apple")){
			return new Apple();
		}
		else if(which.equalsIgnoreCase("grape")){
			return new Grape();
		}
		else{
			throw new BadFruitException("Bad fruit request");
		}
		
	}
}
