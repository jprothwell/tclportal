package pattern.oberver.javautil;

import java.util.Observer;

public class Tester {
	
	static private Watched watched;
	static private Observer watcher;
	
	public static void main(String[] args){
		//�������۲��߶���
		watched =  new Watched();
		//�����۲��߶��󣬲����۲��ߵǼ�
		watcher = new Watcher(watched);
		//���۲��߸���4��
		watched.changeData("c");
		watched.changeData("java");
		watched.changeData("java");
		watched.changeData("python");
	}
}
