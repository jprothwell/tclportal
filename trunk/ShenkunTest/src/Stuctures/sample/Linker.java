package Stuctures.sample;

public class Linker {

	public Link tempLink=null;
	
	public boolean emptyBoolean(){
		return tempLink==null;
	}
	
	public void insertVlaue(int key,double value){
		 Link link = new Link(key,value);
		 if(tempLink==null){
			 tempLink = link;
		 }else{
			 tempLink.setNext(link);
		 }
	}
}
class Link{
	private int key;
	private double value;
	private Link next;
	
	public Link(int key,double value){
		this.key = key;
		this.value = value;
	}

	public int getKey() {
		return key;
	}

	public void setKey(int key) {
		this.key = key;
	}

	public double getValue() {
		return value;
	}

	public void setValue(double value) {
		this.value = value;
	}

	public Link getNext() {
		return next;
	}

	public void setNext(Link next) {
		this.next = next;
	}
	
}
