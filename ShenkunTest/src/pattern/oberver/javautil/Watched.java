package pattern.oberver.javautil;

import java.util.Observable;
/**
 * ���۲����
 * @author kun.shen
 *
 */
public class Watched extends Observable{
	
	private String data = "";
	/**
	 * ȡֵ
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
