package Structures.mergeApp;
/**
 * 通过归并 递归进行排序
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
	//递归调用，分割数组
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
	
	//对数组用归并算法进行排序
	private static void merge(int[] merge, int lower, int curr, int upper) {
		int index=0; //数组merge的位置
		int length = upper-lower+1;//排序元素个数
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
