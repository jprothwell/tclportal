package Structures.binary;
/*
 * �ݹ�Ķ��ֲ��ҷ������ڷ����㷨��
 * �����㷨 ������һ����������������а�������������ĵݹ���ã�����ֻ��һ�����ִ����
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
			System.out.println(searchNum + "�������" + curItem + "λ����");
		}else if(lower>upper)
		{
			System.out.println("�����ڸ�ֵ");
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
