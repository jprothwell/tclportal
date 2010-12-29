package Structures.mergeApp;
/**
 * ͨ���鲢 �ݹ��������
 * @author Administrator
 *
 */
public class MergeAppRecursion {
	
	static int[] a = {2,4,1,3,6};
	public static void main(String[] args) {
		int[] merge = new int[20];
		int lower = 0;
		int upper = a.length-1;
		disjoin(merge,lower,upper);
		
		for(int i=0;i<a.length;i++)
		{
			System.out.print(a[i] + " ");
		}
	}
	//�ݹ���ã��ָ�����
	private static void disjoin(int[] merge, int lower, int upper) {

		if(lower==upper){
			return;
		}else{
			int curr = (lower+upper)/2;
			disjoin(merge,lower,curr);
			disjoin(merge,curr+1,upper);
			merge(merge,lower,curr+1,upper);
		}
		
	}
	
	//�������ù鲢�㷨��������
	private static void merge(int[] merge, int lower, int curr, int upper) {
		int index=0; //����merge��λ��
		int length = upper-lower+1;//����Ԫ�ظ���
		int lowerBound = lower;
		while(lower<=curr-1&&curr<=upper)
		{
			if(a[lower]<a[curr])
			{
				merge[index++] = a[lower++];
			}else
			{
				merge[index++] = a[curr++];
			}
		}
		while(lower<=curr-1)
		{	
			merge[index++] = a[lower++];
		}
		while(curr<=upper)
		{	
			merge[index++] = a[curr++];
		}
		for(int i=0;i<length;i++)
		{
			a[lowerBound+i] = merge[i];
		}
	}
}
