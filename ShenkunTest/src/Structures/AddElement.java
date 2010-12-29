package Structures;

public class AddElement {
	
	static char[] arrayChar = new char[50]; 
	public static void main(String[] args) {
		
		String s = "12345";
		arrayChar = s.toCharArray();
		asserts(arrayChar,'6',s.toCharArray().length);
	}

	private static void asserts(char[] a, char c,int size) {
		
		int position = 0;
		arrayChar[position] = c;
		for(int j=position+1;j<size;j++){
			arrayChar[j-1] = a[j];
		}
	}
}
