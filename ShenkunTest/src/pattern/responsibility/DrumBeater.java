package pattern.responsibility;

public class DrumBeater {
	
	private static Player player;
	
	public static void main(String[] args) {
		player = new JiaMu(new JiaZheng(new JiaBaoYu(new JiaHua(null))));
		//规定由第四处理者处理请求
		player.handle(4);
	}

}
