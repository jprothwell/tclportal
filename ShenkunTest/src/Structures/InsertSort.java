package Structures;
/**
 * 插入排序
 * @author Administrator
 *
 */
public class InsertSort {

	public static void main(String[] args) {
		
		int[] a = {2,4,1,8,5,3,9};
		System.out.println("排序前：");
		for(int i:a)
		{
			System.out.print(i);
		}
		System.out.println();
		
		int out;//需要插入的元素下标
		int in;
		for(out=1;out<a.length;out++)
		{
			int temp = a[out];
			in = out;
			//逐步比较，若是数组的元素大于需要插入的元素则向左移动。否则将元素插入到该位置。
			while(in>0&&a[in-1]>=temp)
			{
				a[in] = a[in-1];
				--in;
			}
			a[in] = temp;
		}
		System.out.println("排序后：");
		for(int i:a)
		{
			System.out.print(i);
		}
	}
}
