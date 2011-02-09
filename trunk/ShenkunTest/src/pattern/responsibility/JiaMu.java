package pattern.responsibility;

public class JiaMu extends Player{
	
	public JiaMu(Player aSuccessor){
		this.setSuccessor(aSuccessor);
	}
	@Override
	public void handle(int i) {
		if(i==1){
			System.out.println("jia mu drink!");
		}else{
			System.out.println("jia mu passed");
			next(i);
		}
		
	}

}
