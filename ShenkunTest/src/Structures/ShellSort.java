package Structures;
/**
 * ϣ������
 * @author Administrator
 *
 */
public class ShellSort {

	public static void main(String[] args) {
		int[] a = {2,4,1,8,5,3,9};
		System.out.println("����ǰ��");
		for(int i:a)
		{
			System.out.print(i);
		}
		System.out.println();
		
		int h = 1; //ϣ��������Ԫ�صļ��
		while(h<=a.length/3)
		{
			h = h*3 + 1; //kunth���У��������Ĳ������з�ʽ��1��4��13��40.......��
		}
		
		while(h>0)
		{	
			//�������򲿷�
			int out;//��Ҫ�����Ԫ���±�
			int in;
			for(out=1;out<a.length;out++)
			{
				int temp = a[out];
				in = out;
				//�𲽱Ƚϣ����������Ԫ�ش�����Ҫ�����Ԫ���������ƶ�������Ԫ�ز��뵽��λ�á����Ϊh
				while(in>h-1&&a[in-h]>=temp)
				{
					a[in] = a[in-h];
					in-=h;
				}
				a[in] = temp;
			} 
			h = (h-1)/3;	//�𲽼�С���м�ľ���
		}
		System.out.println("ϣ�������");
		for(int i : a)
		{
			System.out.print(i);
		}
	}
}
