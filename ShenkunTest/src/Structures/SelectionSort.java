package Structures;
/*
 * ѡ���������,��С������������Ѱ����С��ֵ���ҵ����ٻ�λ�á�
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
