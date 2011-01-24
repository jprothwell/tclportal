package security;

import static org.junit.Assert.*;

import org.junit.Test;

public class PBECoderTest {
	@Test
	public void test() throws Exception{
		String inputStr = "abc";
		System.out.println("ԭ�ģ�"+inputStr);
		
		String pwd = "def";
		System.out.println("���룺"+pwd);
		
		byte[] input = inputStr.getBytes();
		byte[] salt = PBECoder.initSalt();
		byte[] data = PBECoder.encrypt(input, pwd, salt);
		System.out.println("���ܺ�"+PBECoder.encryptBASE64(data));
		
		byte[] output = PBECoder.decrypt(data, pwd, salt);
		String outputStr = new String(output);
		
		System.out.println("���ܺ�"+outputStr);
		assertEquals(inputStr,outputStr);
	}
}
