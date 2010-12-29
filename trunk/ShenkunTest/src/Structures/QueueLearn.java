package Structures;
/*
 * ������ͨ���ƶ���ͷ�Ͷ�βָ����ȷ�����ݣ������������������λ�ñ��ֲ��䡣
 * ������Ϊ������в������ֲ��ܲ������������ÿ����ö�ͷ��βָ���ƻص�����Ŀ�ʼλ��
 */
public class QueueLearn {

	public static void main(String[] args) {
		Queue q = new Queue(3);
		q.insert(1);
		q.insert(2);
		q.insert(3);
		q.insert(4);
		
		q.remove();
		System.out.println(q.peek());
	}
}

class Queue
{
	private int maxSize;	//���еĴ�С
	private Long[] queueArray;
	private int top;	//��ͷָ��	
	private int last;	//��βָ��
	private int nItem;	//�����д��ڵ�Ԫ��
	
	public Queue(int size)
	{
		maxSize = size;
		queueArray = new Long[maxSize];
		top = 0;
		last = -1;
		nItem = 0;
	}
	
	//����Ԫ�ؽ�����
	public void insert(long l)
	{
		if(last == maxSize-1) last = -1;//��βָ��ص�����Ŀ�ʼλ��
		if(nItem<maxSize){
			queueArray[++last] = l;
		}else
		{
			System.out.println("����������Ԫ��" + l + "���ܲ������" );
		}
		
		nItem++;
	}
	
	//�Ӷ������Ƴ�Ԫ��
	public long remove()
	{	
		long topItem = queueArray[top];
		top++;	//��ͷָ�������һλ
		if(top == maxSize) top = 0;//��ͷָ��ص�����Ŀ�ʼλ��
		nItem--;
		return topItem;
	}
	
	//��ȡ������Ԫ��
	public long peek()
	{
		return queueArray[top];
	}
	
	//����Ϊ���ж�
	public boolean isEmpty()
	{
		return nItem == 0;
	}
	
	//�����Ƿ�����
	public boolean isFull()
	{
		return nItem == maxSize;
	}
}