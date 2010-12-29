package Structures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * �ݹ���� ʵ���ַ�����ȫ����
 */
public class Anagram {
	/*
	 * �����ַ����ĳ��� 
	 */
	static int size;
	static int count;
	static char[] arrChar = new char[100];
	
	public static void main(String[] args) throws IOException 
	{
		System.out.print("Enter a word: ");
		//��ȡ�����ַ���
		String input = getString();
		size = input.length();
		count = 0;
		for(int i=0;i<size;i++)
		{
			arrChar[i] = input.charAt(i);
		}
		doAnagram(size);
	}

	private static void doAnagram(int newSize) 
	{
		if(newSize==1)
		{
			return;
		}
		for(int j=0;j<newSize;j++)
		{	
			
			doAnagram(newSize-1);
			if(newSize==2)
				{
					display();
				}
			rotate(newSize);
		}
	}

	private static void rotate(int newSize) 
	{
		int j;
		int position = size - newSize;
		char temp = arrChar[position];
		for(j=position+1;j<size;j++)
		{	
			//�������е�Ԫ����������
			arrChar[j-1] = arrChar[j];
		}
		arrChar[j-1] = temp;
	}

	private static void display()
	{
		System.out.print(++count + " ");
		for(int j=0;j<size;j++)
		{
			System.out.print(arrChar[j]);
		}
		System.out.print(" ");
		//System.out.flush();
		if(count%6 == 0)System.out.println();
	}

	private static String getString() throws IOException {
		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader buffer = new BufferedReader(in);
		String s = buffer.readLine();
		return s;
	}
}
