package jvm02;

public class Greet {
	
	public static void main(String[] args){
		
		if(args.length<1){
			System.out.println("enter some parameters!");
			return;
		}
		
		GreetClassLoader gcl = new GreetClassLoader(args[0]);
		
		for(int i=0;i<args.length;++i){
			Class c = gcl
		}
	}
}
