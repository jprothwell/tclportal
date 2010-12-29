package Structures;
/*
 * 栈，只允许对最后进栈的元素进行操作
 */
public class StackLearn {
	public static void main(String[] args) {
		Stack s = new Stack(10);
		s.push(1);
		s.push(2);
		s.push(3);
		System.out.println(s.peek());
		s.pop();
		System.out.println("删除原来的栈顶元素后" + s.peek());
	}

}
class Stack
{	
	private int maxSize; //栈的长度
	
	private long[] stackArray;
	
	private int top; //栈顶元素
	
	public Stack(int s)
	{
		maxSize = s;
		stackArray = new long[maxSize];
		top = -1;
	}
	//压栈
	public void push(long j)
	{	
		stackArray[++top] = j;
	}
	//从栈中取数据
	public long pop()
	{	
		if(top != -1){
			return stackArray[top--];
		}else{
			return -1;
		}	
	}
	//查看栈顶元素
	public long peek()
	{
		return stackArray[top];
	}
	//栈为空
	public boolean isEmpty()
	{
		return (top == -1);
	}
	//栈满
	public boolean ifFull()
	{
		return (top == maxSize -1);
	}
}
