package Structures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*	
 * �ݹ�ʵ���ַ�����ȫ����
 */
public class Anagram1 {
	
	static int size;
	static int count;
	static char[] arrchar;
	
	public static void main(String[] args) {
		System.out.println("������Ҫȫ���е��ַ�"); 
		String s = insertString();	//��ȡ�����ַ���
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
