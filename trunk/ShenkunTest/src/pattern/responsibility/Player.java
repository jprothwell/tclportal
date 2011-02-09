package pattern.responsibility;

public abstract class Player {
	
	abstract public void handle(int i);
	
	private Player successsor;
	
	public Player(){
		successsor = null;
	}
	
	public void setSuccessor(Player aSuccessor){
		successsor = aSuccessor;
	}
	
	public void next(int index){
		if(successsor!=null){
			successsor.handle(index);
		}else{
			System.out.println("program terminated:");
			System.exit(0);
		}
	}
}
