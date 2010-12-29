package Structures;
/**
 * 希尔排序
 * @author Administrator
 *
 */
public class ShellSort {

	public static void main(String[] args) {
		int[] a = {2,4,1,8,5,3,9};
		System.out.println("排序前：");
		for(int i:a)
		{
			System.out.print(i);
		}
		System.out.println();
		
		int h = 1; //希尔排序中元素的间隔
		while(h<=a.length/3)
		{
			h = h*3 + 1; //kunth序列，有其他的产生序列方式（1，4，13，40.......）
		}
		
		while(h>0)
		{	
			//插入排序部分
			int out;//需要插入的元素下标
			int in;
			for(out=1;out<a.length;out++)
			{
				int temp = a[out];
				in = out;
				//逐步比较，若是数组的元素大于需要插入的元素则向左移动。否则将元素插入到该位置。间隔为h
				while(in>h-1&&a[in-h]>=temp)
				{
					a[in] = a[in-h];
					in-=h;
				}
				a[in] = temp;
			} 
			h = (h-1)/3;	//逐步减小序列间的距离
		}
		System.out.println("希尔排序后");
		for(int i : a)
		{
			System.out.print(i);
		}
	}
}
