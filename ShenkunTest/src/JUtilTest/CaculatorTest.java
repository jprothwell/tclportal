package JUtilTest;

import junit.framework.TestCase;

import org.junit.Before;
import org.junit.Test;

public class CaculatorTest extends TestCase {
	
	private static Caculator caculator = new Caculator();
	
	/*
	 * ���κ�һ������ִ��֮ǰ�����ģ����ڶ��������ղ���
	 * �����ڲ������ʱ���ÿ��Ǽӷ��Ĳ���
	 */
	@Before
	protected void setUp() throws Exception {
		caculator.clear();
	}
	
	public void testAdd()
	{
		caculator.add(2);
		caculator.add(3);
		assertEquals(5,caculator.getResult());
	}
	
	public void testSubstract()
	{
		caculator.add(10);
		caculator.substract(2);
		assertEquals(8,caculator.getResult());
	}
	
	public void testDivide()
	{
		caculator.add(10);
		caculator.divide(2);
		assertEquals(5,caculator.getResult());
	}
	
	@Test(timeout = 1000)
	public void testSquareRoot()
	{
		caculator.squareRoot(4);
		assertEquals(2,caculator.getResult());
	}
}
