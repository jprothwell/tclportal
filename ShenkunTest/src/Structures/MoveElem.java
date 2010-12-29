package Structures;

public class MoveElem {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		char[] chars = {'a','b','c'};
		char temp = chars[0];
		int size = chars.length;
		for(int i=1;i<size;i++){
			moveRight(chars, i,size,chars[i-1]);
		}
	}

	private static void moveRight(char[] chars, int position,int size,char move) {
		for(int i=1;i<=position;i++){
			chars[i-1] = chars[i];
		}
		chars[position] = move;
		sort(chars);
		System.out.println();
	}

	private static void sort(char[] chars) {
		for(char c:chars){
			System.out.print(c);
		}
	}

}
