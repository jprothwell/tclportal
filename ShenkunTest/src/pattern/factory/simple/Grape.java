package pattern.factory.simple;

public class Grape implements Fruit{
	
	private boolean seedless;
	
	@Override
	public void grow() {
		log("grape grow");
		
	}

	@Override
	public void harvest() {
		log("grape harvest");
	}

	@Override
	public void plan() {
		log("grape plan");
		
	}
	
	public boolean isSeedless() {
		return seedless;
	}

	public void setSeedless(boolean seedless) {
		this.seedless = seedless;
	}

	public static void log(String s){
		System.out.println(s);
	}
	
}
