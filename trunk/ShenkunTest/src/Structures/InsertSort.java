package Structures;
/**
 * ��������
 * @author Administrator
 *
 */
public class InsertSort {

	public static void main(String[] args) {
		
		int[] a = {2,4,1,8,5,3,9};
		System.out.println("����ǰ��");
		for(int i:a)
		{
			System.out.print(i);
		}
		System.out.println();
		
		int out;//��Ҫ�����Ԫ���±�
		int in;
		for(out=1;out<a.length;out++)
		{
			int temp = a[out];
			in = out;
			//�𲽱Ƚϣ����������Ԫ�ش�����Ҫ�����Ԫ���������ƶ�������Ԫ�ز��뵽��λ�á�
			while(in>0&&a[in-1]>=temp)
			{
				a[in] = a[in-1];
				--in;
			}
			a[in] = temp;
		}
		System.out.println("�����");
		for(int i:a)
		{
			System.out.print(i);
		}
	}
}
