package pattern.responsibility;

public class DrumBeater {
	
	private static Player player;
	
	public static void main(String[] args) {
		player = new JiaMu(new JiaZheng(new JiaBaoYu(new JiaHua(null))));
		//�涨�ɵ��Ĵ����ߴ�������
		player.handle(4);
	}

}
