package pattern.oberver.javautil;

import java.util.Observable;
/**
 * 被观察对象
 * @author kun.shen
 *
 */
public class Watched extends Observable{
	
	private String data = "";
	/**
	 * 取值
	 * @return
	 */
	public String retrieveData(){
		return data;
	}
	public void changeData(String data){
		if(!this.data.equals(data)){
			this.data = data;
			setChanged();
		}
			notifyObservers();
	}
}
