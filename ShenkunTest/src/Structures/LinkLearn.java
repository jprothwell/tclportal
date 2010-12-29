package Structures;
/*
 * ����������ҵ�Ч��������������Ч��ɾ���������鶼��Ч
 * ����������֮��ڶ���ʹ����㷺�Ĵ洢�ṹ
 * ����Ϊ��ȷ���¸��ڵ��λ�ã��ٴ����ڵ�ֵ��ʱ�򣬻�Ҫ�����¸��ڵ�ĵ�ַ
 * ������ͷָ����Ψһȷ���ġ�
 */
public class LinkLearn {
	public static void main(String[] args) {
		
	}

}

class Link
{
	public int iData;
	public double dData;
	public Link next;
	
	public Link(int id,double dd)
	{
		iData = id;
		dData = dd;
	}
	
	public void diplayLink()
	{
		System.out.println("{" + iData + "," + dData + "}");
	}
}

class LinkList
{
	private Link first;
	
	public LinkList()
	{
		first = null;
	}
	
	//����Ϊ���ж�
	public boolean isEmpty()
	{
		return first == null;
	}
	
	//�������в���Ԫ��
	public void insertFirst(int id, double dd)
	{
		Link newLink = new Link(id,dd);
		newLink.next = first;
		first = newLink;
	}
	
	//ɾ�������ͷԪ��
	public Link deleteFirst()
	{
		Link temp = first;
		first = first.next;
		return temp;
	}
	
	//��ʾ���������Ԫ��
	public void displayList()
	{
		Link current = first;
		while(current != null)
		{
			current.diplayLink();
			current = current.next;
		}
	}
}