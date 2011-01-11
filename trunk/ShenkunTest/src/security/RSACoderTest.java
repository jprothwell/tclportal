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
		System.err.println("公钥："+publicKey);
		System.err.println("私钥："+privateKey);
	}
	@Test
	public void test() {
		System.out.println("公钥加密&私钥解密");
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
		System.err.println("加密前："+inputStr);
		System.err.println("解密后："+outputStr);
		assertEquals(inputStr,outputStr);
	}
	
	@Test
	public void testSign() throws Exception{
		System.out.println("私钥加密&公钥解密");
		String input  = "sign";
		byte[] data = input.getBytes();
		
		byte[] encodeData = RSACoder.encryptByPrivateKey(data, privateKey);
		
		byte[] decodeData = RSACoder.decryptByPublicKey(encodeData, publicKey);
		
		String output = new String(decodeData);
		
		System.err.println("加密前："+input);
		
		System.err.println("解密后："+output);
		
		assertEquals(input,output);
		
		System.err.println("私钥签名&公钥验证签名");
		//产生签名
		String sign = RSACoder.sign(encodeData, privateKey);
		System.out.println("签名："+sign);
		
		//验证签名
		boolean status = RSACoder.verify(encodeData, publicKey, sign);
		System.out.println("验证结果："+status);
		assertTrue(status);
	}
}
