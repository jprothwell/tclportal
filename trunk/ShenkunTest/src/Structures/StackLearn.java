package Structures;
/*
 * ջ��ֻ���������ջ��Ԫ�ؽ��в���
 */
public class StackLearn {
	public static void main(String[] args) {
		Stack s = new Stack(10);
		s.push(1);
		s.push(2);
		s.push(3);
		System.out.println(s.peek());
		s.pop();
		System.out.println("ɾ��ԭ����ջ��Ԫ�غ�" + s.peek());
	}

}
class Stack
{	
	private int maxSize; //ջ�ĳ���
	
	private long[] stackArray;
	
	private int top; //ջ��Ԫ��
	
	public Stack(int s)
	{
		maxSize = s;
		stackArray = new long[maxSize];
		top = -1;
	}
	//ѹջ
	public void push(long j)
	{	
		stackArray[++top] = j;
	}
	//��ջ��ȡ����
	public long pop()
	{	
		if(top != -1){
			return stackArray[top--];
		}else{
			return -1;
		}	
	}
	//�鿴ջ��Ԫ��
	public long peek()
	{
		return stackArray[top];
	}
	//ջΪ��
	public boolean isEmpty()
	{
		return (top == -1);
	}
	//ջ��
	public boolean ifFull()
	{
		return (top == maxSize -1);
	}
}
