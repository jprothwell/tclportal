package Structures;
/*
 * 队列是通过移动对头和队尾指针来确定数据，而保持所有数据项的位置保持不变。
 * 而这样为避免队列不满，又不能插入的情况。采用可以让队头队尾指针绕回到数组的开始位置
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
	private int maxSize;	//队列的大小
	private Long[] queueArray;
	private int top;	//队头指针	
	private int last;	//队尾指针
	private int nItem;	//队列中存在的元素
	
	public Queue(int size)
	{
		maxSize = size;
		queueArray = new Long[maxSize];
		top = 0;
		last = -1;
		nItem = 0;
	}
	
	//插入元素进队列
	public void insert(long l)
	{
		if(last == maxSize-1) last = -1;//队尾指针回到数组的开始位置
		if(nItem<maxSize){
			queueArray[++last] = l;
		}else
		{
			System.out.println("队列已满，元素" + l + "不能插入队列" );
		}
		
		nItem++;
	}
	
	//从队列中移除元素
	public long remove()
	{	
		long topItem = queueArray[top];
		top++;	//队头指针向后移一位
		if(top == maxSize) top = 0;//队头指针回到数组的开始位置
		nItem--;
		return topItem;
	}
	
	//获取队列首元素
	public long peek()
	{
		return queueArray[top];
	}
	
	//队列为空判断
	public boolean isEmpty()
	{
		return nItem == 0;
	}
	
	//队列是否已满
	public boolean isFull()
	{
		return nItem == maxSize;
	}
}