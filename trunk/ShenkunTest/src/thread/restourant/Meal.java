package thread.restourant;

public class Meal {
	
	private int orderNum;
	public Meal(int orderNum){
		this.orderNum = orderNum;
	}
	public String toString(){
		return "meal:"+orderNum;
	}
}
