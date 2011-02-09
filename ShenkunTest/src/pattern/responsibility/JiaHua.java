package pattern.responsibility;

public class JiaHua extends Player{
	
	public JiaHua(Player aSuccessor){
		this.setSuccessor(aSuccessor);
	}
	@Override
	public void handle(int i) {
		// TODO Auto-generated method stub
		if(i==5){
			System.out.println("jia bao drink");
		}else{
			System.out.println("jia bao passed");
			next(i);
		}
	}

}
