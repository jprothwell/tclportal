package security;

import static org.junit.Assert.assertEquals;

import java.util.Map;

import org.junit.Test;

public class DHCoderTest {
	
	@Test
	 public void test() throws Exception{
		 //���ɼ׷���Կ��
		Map<String,Object> aKeyMap = DHCoder.initKey();
		String aPublicKey = DHCoder.getPublicKey(aKeyMap);
		String aPrivateKey = DHCoder.getPublicKey(aKeyMap);
		
		System.out.println("�׷���Կ��"+aPublicKey);
		System.out.println("�׷�˽Կ��"+aPrivateKey);
		
		//�ɼ׷���Կ����������Կ
		Map<String,Object> bKeyMap = DHCoder.initKey(aPublicKey);
		String bPublicKey = DHCoder.getPublicKey(bKeyMap);
		String bPrivateKey = DHCoder.getPrivateKey(bKeyMap);
		
		System.out.println("�ҷ���Կ��"+bPublicKey);
		System.out.println("�ҷ�˽Կ��"+bPrivateKey);
		
		String aInput = "abc";
		System.out.println("ԭ�ģ�"+aInput);
//		//�ɼ׷���Կ���ҷ�˽Կ��������
//		byte[] aCode = DHCoder.encrypt(aInput.getBytes(), aPublicKey, bPrivateKey);
//		
//		//�ҷ���Կ���׷�˽Կ����
//		byte[] aDecode = DHCoder.decrypt(aCode, bPublicKey,aPrivateKey);
//		String aOutput = new String(aDecode);
//		System.out.println("���ܣ�"+aOutput);
//		assertEquals(aInput,aOutput);
		
		String bInput = "def";
		//�ҷ���Կ���׷�˽Կ��������
		byte[] bCode = DHCoder.encrypt(bInput.getBytes(), bPublicKey,aPrivateKey);
		
		//�ҷ�˽Կ���׷���Կ����
		byte[] bDecode = DHCoder.decrypt(bCode, aPublicKey, bPrivateKey);
		String bOutput = new String(bDecode);
		System.out.println("���ܺ�"+bOutput);
		assertEquals(bInput,bOutput);
	 }
}
