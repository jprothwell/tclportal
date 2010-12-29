package Structures;
/*
 * 选择排序程序,由小到大排序。总是寻找最小的值，找到后再换位置。
 * 
 */
public class SelectionSort {
	public static void main(String[] args) {
		int[] a = {2,4,1,8,5,3,9};
		for(int i=0;i<a.length;i++)
		{
			int max = i;
			for(int j=i+1;j<a.length;j++)
			{
				if(a[max]>a[j]) max = j;
			}
			int temp = a[i];
			a[i]= a[max];
			a[max] = temp;
		}
		
		for(int i=0;i<a.length;i++)
		{
			System.out.print(a[i]);
		}
	}
}
