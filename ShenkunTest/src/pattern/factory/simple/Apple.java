package pattern.factory.simple;

public class Apple implements Fruit{
	
	private int treeAge;
	
	@Override
	public void grow() {
		log("apple grow");
		
	}

	@Override
	public void harvest() {
		log("apple harvest");
		
	}

	@Override
	public void plan() {
		log("apple plan");
		
	}
	
	
	public int getTreeAge() {
		return treeAge;
	}

	public void setTreeAge(int treeAge) {
		this.treeAge = treeAge;
	}

	public static void log(String s){
		System.out.println(s);
	}
}
