package security;

import java.security.Key;
import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.security.interfaces.RSAPrivateKey;
import java.security.interfaces.RSAPublicKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.HashMap;
import java.util.Map;

import javax.crypto.Cipher;



public class RSACoder extends Coder{
	
	public static final String KEY_ALGORITHM = "RSA";
	
	public static final String SINGATHRE_ALGORITHM = "MD5withRSA";
	
	private static final String PUBLIC_KEY = "RSAPublicKey";  
	
	private static final String PRIVATE_KEY = "RSAPrivateKey"; 
	/**
	 * ��˽Կ��������ǩ��
	 * @param data
	 * @param privateKey
	 * @return
	 * @throws Exception
	 */
	public static String sign(byte[] data,String privateKey) throws Exception{
		//������base4�����˽Կ
		byte[] keyBytes = decryptBASE64(privateKey);
		//����PKCS8EncodedkeySpec����
		PKCS8EncodedKeySpec pkcs8KeySpec = new PKCS8EncodedKeySpec(keyBytes);
		//KEY_ALGORITHM ָ�������㷨
		KeyFactory keyFactory = KeyFactory.getInstance(KEY_ALGORITHM);
		//˽Կ����
		PrivateKey pk = keyFactory.generatePrivate(pkcs8KeySpec);
		//����˽Կ����Ϣ��������ǩ��
		Signature signature = Signature.getInstance(SINGATHRE_ALGORITHM);
		signature.initSign(pk);
		signature.update(data);
		return encryptBASE64(signature.sign());
	}
	/**
	 * У������ǩ��
	 * @param data
	 * @param publicKey
	 * @param sign
	 * @return
	 * @throws Exception
	 */
	public static boolean verify(byte[] data,String publicKey,String sign) throws Exception{
		
		//����base64����Ĺ�Կ
		byte[] keyBytes = decryptBASE64(publicKey);
		//����X509EncodedKeySpec����
		X509EncodedKeySpec keySpec = new X509EncodedKeySpec(keyBytes);
		//KEY_ALGORTHMָ�������㷨
		KeyFactory keyFactory = KeyFactory.getInstance(KEY_ALGORITHM);
		//��Կ����
		PublicKey pk = keyFactory.generatePublic(keySpec);
		Signature signature = Signature.getInstance(SINGATHRE_ALGORITHM);
		signature.initVerify(pk);
		signature.update(data);
		return signature.verify(decryptBASE64(sign));
	}
	/**
	 * ��˽Կ����
	 * @param data
	 * @param key
	 * @return
	 * @throws Exception
	 */
	public static byte[] decryptByPrivateKey(byte[] data,String key) throws Exception{
		//����Կ����
		byte[] keyBytes = decryptBASE64(key);
		//��ȡ˽Կ
		PKCS8EncodedKeySpec pkcs8KeySpec = new PKCS8EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(KEY_ALGORITHM);
		Key privateKey = keyFactory.generatePrivate(pkcs8KeySpec);
		
		//�����ݽ���
		Cipher cipher = Cipher.getInstance(keyFactory.getAlgorithm());
		cipher.init(Cipher.DECRYPT_MODE, privateKey);
		
		return cipher.doFinal(data);
	}
	
	/**
	 * ��˽Կ����
	 * @param data
	 * @param key
	 * @return
	 * @throws Exception
	 */
	public static byte[] encryptByPrivateKey(byte[] data,String key) throws Exception{
		//����Կ����
		byte[] keyBytes = decryptBASE64(key);
		
		//ȡ��˽Կ
		PKCS8EncodedKeySpec pkcs8KeySpec = new PKCS8EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(KEY_ALGORITHM);
		Key privateKey = keyFactory.generatePrivate(pkcs8KeySpec);
		
		//�����ݽ���
		Cipher cipher = Cipher.getInstance(keyFactory.getAlgorithm());
		cipher.init(Cipher.ENCRYPT_MODE, privateKey);
		return cipher.doFinal(data);
	}
	
	/**
	 * �ù�Կ����
	 * @param data
	 * @param key
	 * @return
	 * @throws Exception
	 */
	public static byte[] decryptByPublicKey(byte[] data,String key)throws Exception{
		//����Կ����
		byte[] keyBytes = decryptBASE64(key);
		
		//��ȡ��Կ
		X509EncodedKeySpec x509EncodeKeySpec = new X509EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(KEY_ALGORITHM);
		Key publicKey = keyFactory.generatePublic(x509EncodeKeySpec);
		
		//�����ݽ���
		Cipher cipher = Cipher.getInstance(keyFactory.getAlgorithm());
		cipher.init(Cipher.DECRYPT_MODE, publicKey);
		return cipher.doFinal(data);
	}
	/**
	 * �ù�Կ����
	 * @param data
	 * @param key
	 * @return
	 * @throws Exception
	 */
	public static byte[] encryptByPublicKey(byte[] data,String key) throws Exception{
		//�Թ�Կ����
		byte[] keyBytes = decryptBASE64(key);
		
		//��ȡ��Կ
		X509EncodedKeySpec x509EncodeKeySpec = new X509EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(KEY_ALGORITHM);
		Key publicKey = keyFactory.generatePublic(x509EncodeKeySpec);
		
		//�����ݽ���
		Cipher cipher = Cipher.getInstance(keyFactory.getAlgorithm());
		cipher.init(Cipher.ENCRYPT_MODE, publicKey);
		return cipher.doFinal(data);
	}
	/**
	 * ��ȡ˽Կ
	 * @param keyMap
	 * @return
	 * @throws Exception
	 */
	public static String getPrivateKey(Map<String,Object> keyMap)throws Exception{
		Key key = (Key)keyMap.get(PRIVATE_KEY);
		return encryptBASE64(key.getEncoded());
	}
	
	public static String getPublicKey(Map<String,Object> keyMap) throws Exception{
		Key key = (Key)keyMap.get(PUBLIC_KEY);
		return encryptBASE64(key.getEncoded());
	}
	/**
	 * ��ʼ����Կ
	 * @return
	 * @throws Exception
	 */
	public static Map<String,Object> initKey() throws Exception{
		KeyPairGenerator keyPairGen = KeyPairGenerator.getInstance(KEY_ALGORITHM);
		keyPairGen.initialize(1024);
		KeyPair keyPair = keyPairGen.generateKeyPair();
		
		//��Կ
		RSAPublicKey publicKey = (RSAPublicKey)keyPair.getPublic();
		//˽Կ
		RSAPrivateKey privateKey = (RSAPrivateKey)keyPair.getPrivate();
		
		Map<String,Object> keyMap = new HashMap<String,Object>(2);
		
		keyMap.put(PUBLIC_KEY, publicKey);
		keyMap.put(PRIVATE_KEY,privateKey);
		return keyMap;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
