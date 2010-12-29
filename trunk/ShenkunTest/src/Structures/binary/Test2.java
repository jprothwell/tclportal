package Structures.binary;
/*
 * 递归的二分查找法，属于分治算法。
 * 分治算法 常常是一个方法，这个方法中包含两个对自身的递归调用，但是只有一个真的执行了
 */
public class Test2 {
	
	static int[] binary = {1,2,3,4,5,6,7,8,9};
	
	public static void main(String[] args) {
		
		int lower = 0;
		int upper =  binary.length;
		
		int searchNum = 6;
		
		binarySearch(searchNum,lower,upper);
	}

	private static void binarySearch(int searchNum, int lower, int upper) {
		int curItem = (lower + upper)/2;
		if(binary[curItem] == searchNum)
		{
			System.out.println(searchNum + "在数组的" + curItem + "位置上");
		}else if(lower>upper)
		{
			System.out.println("不存在该值");
		}
		else 
		{
			if(binary[curItem]>searchNum)
			{
				binarySearch(searchNum,lower,curItem-1);
				System.out.println(">>");
			}
			if(binary[curItem]<searchNum)
			{
				binarySearch(searchNum,curItem+1,upper);
				System.out.println("<<");
			}
		}
	}

}
