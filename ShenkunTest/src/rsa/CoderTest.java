package rsa;

import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;

import java.math.BigInteger;

import org.junit.Test;

public class CoderTest {
	@Test
	public void test() throws Exception{
		String inputStr = "����";
		System.err.println("ԭ�ģ�"+inputStr);
		
		byte[] inputData = inputStr.getBytes();
		String code = Coder.encryptBASE64(inputData);
		System.err.println("BASE64���ܺ�"+code);
		
		byte[] output = Coder.decryptBASE64(code);
		String outputStr = new String(output);
		System.err.println("BASE64���ܺ�"+outputStr);
		
		assertEquals(inputStr,outputStr);
		
		assertArrayEquals(Coder.encryptMD5(inputData),Coder.encryptMD5(inputData));
		
		BigInteger md5 = new BigInteger(Coder.encryptMD5(inputData));
		System.err.println("MD5:"+md5.toString(16));
		
		BigInteger mac = new BigInteger(Coder.encryptHMAC(inputData, inputStr));
		System.err.println("HMAC:"+mac.toString(16));
	}
}
