package pattern.oberver.javautil;

import java.util.Observer;

public class Tester {
	
	static private Watched watched;
	static private Observer watcher;
	
	public static void main(String[] args){
		//创建被观察者对象
		watched =  new Watched();
		//创建观察者对象，并被观察者登记
		watcher = new Watcher(watched);
		//被观察者复制4次
		watched.changeData("c");
		watched.changeData("java");
		watched.changeData("java");
		watched.changeData("python");
	}
}
