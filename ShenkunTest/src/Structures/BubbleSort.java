package Structures;
/*
 * √∞≈›≈≈–Ú≥Ã–Ú
 */
public class BubbleSort {

	public static void main(String[] args) {
		
		int[] a = {2,4,1,8,5,3,9};
		for(int i=0;i<a.length;i++)
		{
			for(int j =0;j<a.length;j++)
			{
				if(a[i]<a[j]) 
				{
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
				
			}
		}
		
		for(int j=0;j<a.length;j++)
		{
			System.out.print(a[j]);
		}
	}
}
