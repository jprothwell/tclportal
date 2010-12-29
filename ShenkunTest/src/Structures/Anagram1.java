package Structures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*	
 * 递归实现字符串的全排列
 */
public class Anagram1 {
	
	static int size;
	static int count;
	static char[] arrchar;
	
	public static void main(String[] args) {
		System.out.println("输入需要全排列的字符"); 
		String s = insertString();	//获取输入字符串
		arrchar = s.toCharArray();
		count = 0;
		doAnagram(arrchar.length);
	}

	private static void doAnagram(int newSize) {
		if(newSize ==1)
		{
			return;
		}
		for(int i=0;i<newSize;i++)
		{
			doAnagram(newSize-1);
			if(newSize==2) displayWord();
			rotate(newSize);
		}
		
	}

	private static void displayWord() {
		
		
	}
	
	private static void rotate(int newSize) {
		
		int i;
		int postion;
	}
	
	private static String insertString() { 
		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader buffer = new BufferedReader(in);
		String s = null;
		try {
			s = buffer.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return s;
	}

}
