package Structures;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * �ݹ�ʵ�ֳ˷�
 * ��x��y��
 */
public class Power {
	
	static int xNum = 1;
	public static void main(String[] args) throws IOException {
		
		int x,y;
		int count = 1;
		x = insert();
		y = insert();
		power(x,y,count);
	}

	private static void power(int x, int y, int count) {
		
		System.out.println("xֵΪ��"+x+" yֵΪ��"+y);
		xNum = xNum*count;
		System.out.println("xNum:"+xNum);
		if(y==1)
		{	
//			System.out.println(count);
//			if(count>0){
//				for(int i=1;i<=count;i++){
//					x = x*xNum;
//				}
//			}
			System.out.println("x��y�η���ֵΪ��"+x*xNum);
			return;
			
		}
		if(y>1)
		{ 
			
			//yΪż����ʱ��
			if(y%2==0)
			{	System.out.println(">>>>");
				power(x*x,y/2,1);
			}
			//yΪ������ʱ��
			if(y%2==1)
			{System.out.println("<<<<");
				power(x*x,(y-1)/2,x);
			}
		}
	}

	private static int insert() throws IOException {
		InputStreamReader in = new InputStreamReader(System.in);
		BufferedReader buffer = new BufferedReader(in);
		String s = buffer.readLine();
		return Integer.parseInt(s);
	}

}
