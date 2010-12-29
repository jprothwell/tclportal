package Structures.mergeApp;
/*
 * �鲢�㷨 ������A������B��Ԫ�طֱ�Ƚϣ�Ȼ�󿽵�����C��
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
		
		//��a,b����Ϊ�յ�ʱ��
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
		//��b����Ϊ��ʱ,��bDex��С��bSize
		while(aDex<aSize)
		{
			c[cDex++] = a[aDex++];
		}
		//��a����Ϊ��ʱ,��aDex��С��aSize
		while(bDex<bSize)
		{
			c[cDex++] = a[aDex++];
		}
	}

}
