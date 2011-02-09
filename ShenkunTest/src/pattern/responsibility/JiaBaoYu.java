package pattern.responsibility;

public class JiaBaoYu extends Player{
	
	public JiaBaoYu(Player aSuccessor){
		this.setSuccessor(aSuccessor);
	}
	@Override
	public void handle(int i) {
		// TODO Auto-generated method stub
		if(i==4){
			System.out.println("jia bao drink");
		}else{
			System.out.println("jia bao passed");
			next(i);
		}
	}

}
