package Structures.binary;
/**
 * ���ֲ��ҷ���
 * @author Administrator
 *
 */
public class Test1 {

	public static void main(String[] args) {
		
		int[] binary = {1,2,3,4,5,6,7,8,9};
		int lower = 0;
		int upper = binary.length-1;
		int curIn;
		
		int searchNum = 10;
		while(true)
		{
			curIn = (upper + lower)/2;
			if(binary[curIn] == searchNum)
			{
				System.out.println(searchNum + "�����������" + curIn + "λ��");
				return;
			}else if(upper < lower)
			{
				System.out.println(searchNum + "�������в�����");
				return;
			}else{
				if(binary[curIn]>searchNum)
				{
					upper = curIn - 1;
				}else if(binary[curIn]<searchNum)
				{
					lower = curIn + 1;
				}
			}
		}
	}
}
