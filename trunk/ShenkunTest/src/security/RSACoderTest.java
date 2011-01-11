package security;

import static org.junit.Assert.*;

import java.util.Map;

import org.junit.Before;
import org.junit.Test;

public class RSACoderTest {
	
	private String publicKey;
	
	private String privateKey;
	
	@Before
	public void setUp() throws Exception{
		Map<String,Object> keyMap = RSACoder.initKey();
		publicKey = RSACoder.getPublicKey(keyMap);
		privateKey = RSACoder.getPrivateKey(keyMap);
		System.err.println("��Կ��"+publicKey);
		System.err.println("˽Կ��"+privateKey);
	}
	@Test
	public void test() {
		System.out.println("��Կ����&˽Կ����");
		String inputStr = "abc";
		
		byte[] data = inputStr.getBytes();
		
		byte[] encodedData = null;
		
		byte[] decodedData = null;
		try {
			encodedData = RSACoder.encryptByPublicKey(data,publicKey);
			
			decodedData = RSACoder.decryptByPrivateKey(encodedData, privateKey);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		String outputStr = new String(decodedData);
		System.err.println("����ǰ��"+inputStr);
		System.err.println("���ܺ�"+outputStr);
		assertEquals(inputStr,outputStr);
	}
	
	@Test
	public void testSign() throws Exception{
		System.out.println("˽Կ����&��Կ����");
		String input  = "sign";
		byte[] data = input.getBytes();
		
		byte[] encodeData = RSACoder.encryptByPrivateKey(data, privateKey);
		
		byte[] decodeData = RSACoder.decryptByPublicKey(encodeData, publicKey);
		
		String output = new String(decodeData);
		
		System.err.println("����ǰ��"+input);
		
		System.err.println("���ܺ�"+output);
		
		assertEquals(input,output);
		
		System.err.println("˽Կǩ��&��Կ��֤ǩ��");
		//����ǩ��
		String sign = RSACoder.sign(encodeData, privateKey);
		System.out.println("ǩ����"+sign);
		
		//��֤ǩ��
		boolean status = RSACoder.verify(encodeData, publicKey, sign);
		System.out.println("��֤�����"+status);
		assertTrue(status);
	}
}
