package pattern.responsibility;

public class JiaZheng extends Player{
	
	public JiaZheng(Player aSuccessor){
		this.setSuccessor(aSuccessor);
	}
	@Override
	public void handle(int i) {
		if(i==3){
			System.out.println("jia zheng drink");
		}else{
			System.out.println("jia zheng passed!");
			next(i);
		}
		
	}

}
