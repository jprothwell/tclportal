package Structures;
/*
 * 无序数组查找低效，有序数组插入低效，删除对于数组都低效
 * 链表是数组之后第二个使用最广泛的存储结构
 * 链表为了确定下个节点的位置，再存贮节点值的时候，还要存贮下个节点的地址
 * 单链表，头指针是唯一确定的。
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
	
	//链表为空判断
	public boolean isEmpty()
	{
		return first == null;
	}
	
	//向链表中插入元素
	public void insertFirst(int id, double dd)
	{
		Link newLink = new Link(id,dd);
		newLink.next = first;
		first = newLink;
	}
	
	//删除链表的头元素
	public Link deleteFirst()
	{
		Link temp = first;
		first = first.next;
		return temp;
	}
	
	//显示所有链表的元素
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