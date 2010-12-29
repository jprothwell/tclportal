package Structures.mergeApp;
/*
 * 归并算法 将数组A和数组B的元素分别比较，然后拷到数组C里
 */
public class MergeApp {

	public static void main(String[] args) {
		
		int[] a = {2,3,6,9};
		int[] b = {1,4,5,7,8};
		int[] c = new int[9];
		
		merge(a,b,c);
		
		for(int i = 0;i<c.length;i++)
		{
			System.out.print(c[i] + "  ");
		}
	}

	private static void merge(int[] a, int[] b, int[] c) {
		int aSize = a.length;
		int bSize = b.length;
		int aDex=0,bDex=0,cDex=0;
		
		//当a,b都不为空的时候
		while(aDex<aSize&&bDex<bSize)
		{
			if(a[aDex]<b[bDex])
			{
				c[cDex++] = a[aDex++];
			}else
			{
				c[cDex++] = b[bDex++];
			}
		}
		//当b数组为空时,即bDex不小于bSize
		while(aDex<aSize)
		{
			c[cDex++] = a[aDex++];
		}
		//当a数组为空时,即aDex不小于aSize
		while(bDex<bSize)
		{
			c[cDex++] = a[aDex++];
		}
	}

}
