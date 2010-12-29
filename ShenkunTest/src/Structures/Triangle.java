package Structures;
/* 
 * 递归程序一
 * 数列 1 3 6 10 15 21 ........
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Triangle {
	
	static int insertNum;
	
	public static void main(String[] args) throws IOException {
		
		System.out.println("insert number:");
		insertNum = getInt();
		long l = getResult(insertNum);
		System.out.println("the result:" + l);
	}

	private static long getResult(int insertNum) {
		
			if(insertNum == 1)
			{
				return 1;
			}
			if(insertNum >1)
			{
				return getResult(insertNum-1) + insertNum; 
			}
			return 0;
	}

	private static int getInt() throws IOException {
		String s = insertString();
		return Integer.parseInt(s);
	}

	private static String insertString() throws IOException {
		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader buff = new BufferedReader(in);
		String s = buff.readLine();
		return s;
	}

}
