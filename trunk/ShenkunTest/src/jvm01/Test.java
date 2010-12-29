package jvm01;

public class Test {
	
	public static void main(String[] args){
		
		Dog dog = new NomalDog();
		dog.sayGoodbye();
		Friendly f = (Friendly)dog;
		f = new Cat();
		f.sayGoodbye();
	}
}
