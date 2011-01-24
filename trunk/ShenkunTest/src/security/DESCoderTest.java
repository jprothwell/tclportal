package security;

import static org.junit.Assert.*;

import org.junit.Test;

public class DESCoderTest {
	@Test
	public void test() throws Exception{
		String inputStr = "DES";
		
		String key = DESCoder.initKey();
		
		System.out.println("ԭ�ģ�"+inputStr);
		System.out.println("��Կ��"+key);
		
		byte[] inputData = inputStr.getBytes();
		inputData = DESCoder.encrypt(inputData, key);
		System.out.println("���ܺ�"+DESCoder.encryptBASE64(inputData));
		
		byte[] outputData = DESCoder.decrypt(inputData, key);
		String outputStr = new String(outputData);
		System.out.println("���ܺ�"+outputStr);
		
		assertEquals(inputStr,outputStr);
	}
}
