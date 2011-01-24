package security;

import java.security.Key;
import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.HashMap;
import java.util.Map;

import javax.crypto.Cipher;
import javax.crypto.KeyAgreement;
import javax.crypto.SecretKey;
import javax.crypto.interfaces.DHPrivateKey;
import javax.crypto.interfaces.DHPublicKey;
import javax.crypto.spec.DHParameterSpec;

/**
 * ������Կһ��Э��ļ����㷨 DH�㷨
 * @author kun.shen
 *
 */
public class DHCoder extends Coder{
	
	private static final String ALGORITHM = "DH";
	
	private static final int KEY_SIZE = 1024;
	
	private static final String SECRET_ALGORITHM = "DES";
	
	private static final String PUBLIC_KEY = "DHPublicKey";
	
	private static final String PRIVATE_KEY = "DHPrivateKey";
	/**
	 * ��ʼ���׷���Կ
	 * @return
	 * @throws Exception
	 */
	public static Map<String,Object> initKey() throws Exception{
		KeyPairGenerator keypair = KeyPairGenerator.getInstance(ALGORITHM);
		keypair.initialize(KEY_SIZE);
		
		KeyPair keyPair = keypair.generateKeyPair();
		
		//��Կ
		DHPublicKey publicKey = (DHPublicKey)keyPair.getPublic();
		DHPrivateKey privateKey = (DHPrivateKey)keyPair.getPrivate();
		
		Map<String,Object> keyMap = new HashMap<String,Object>();
		keyMap.put(PUBLIC_KEY, publicKey);
		keyMap.put(PRIVATE_KEY, privateKey);
		
		return keyMap;
	}
	/**
	 * ���ݼ׷���Կ��ʼ���ҷ���Կ��
	 * @param key �׷���Կ
	 * @return
	 * @throws Exception
	 */
	public static Map<String,Object> initKey(String key) throws Exception{
		//��ȡ�׷���Կ
		byte[] keyBytes = decryptBASE64(key);
		X509EncodedKeySpec x509KeySpec = new X509EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(ALGORITHM);
		PublicKey publicKey = keyFactory.generatePublic(x509KeySpec);
		
		//�����Լ���˽Կ��
		DHParameterSpec dhParamSpec = ((DHPublicKey)publicKey).getParams();
		KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance(keyFactory.getAlgorithm());
		keyPairGenerator.initialize(dhParamSpec);
		KeyPair keyPair = keyPairGenerator.generateKeyPair();
		
		//�ҷ���Կ,˽Կ
		DHPublicKey pubKey = (DHPublicKey)keyPair.getPublic();
		DHPrivateKey priKey = (DHPrivateKey)keyPair.getPrivate();
		Map<String,Object> keyMap = new HashMap<String,Object>(2);
		keyMap.put(PUBLIC_KEY, publicKey);
		keyMap.put(PRIVATE_KEY, priKey);
		
		return keyMap;
	}
	/**
	 * ����
	 * @param data
	 * @param publicKey
	 * @param privateKey
	 * @return
	 * @throws Exception
	 */
	public static byte[] encrypt(byte[] data,String publicKey,String privateKey) throws Exception{
		//���ɱ���˽Կ
		SecretKey scretKey = getSecretKey(publicKey,privateKey);
		
		//���ݼ���
		Cipher cipher = Cipher.getInstance(scretKey.getAlgorithm());
		cipher.init(Cipher.ENCRYPT_MODE,scretKey);
		return cipher.doFinal(data);
	}
	
	public static byte[] decrypt(byte[] data,String publicKey,String privateKey) throws Exception{
		//���ɱ�����Կ
		SecretKey scretKey = getSecretKey(publicKey,privateKey);
		//���ݼ���
		Cipher cipher = Cipher.getInstance(scretKey.getAlgorithm());
		cipher.init(Cipher.DECRYPT_MODE, scretKey);
		return cipher.doFinal(data);
	}
	/**
	 * ������Կ
	 * @param publicKey
	 * @param privateKey
	 * @return
	 * @throws Exception
	 */
	private static SecretKey getSecretKey(String publicKey, String privateKey) throws Exception {
		
		KeyFactory keyFactory = KeyFactory.getInstance(ALGORITHM);
		
		//��ʼ����Կ
		byte[] pubKeyBytes = decryptBASE64(publicKey);
		X509EncodedKeySpec x509KeySpec = new X509EncodedKeySpec(pubKeyBytes);
		PublicKey pubKey = keyFactory.generatePublic(x509KeySpec);
		
		//��ʼ��˽Կ
		byte[] priKeyBytes = decryptBASE64(privateKey);
		PKCS8EncodedKeySpec pkcs8KeySpec = new PKCS8EncodedKeySpec(priKeyBytes);
		PrivateKey priKey = keyFactory.generatePrivate(pkcs8KeySpec);
		
		KeyAgreement keyAgree = KeyAgreement.getInstance(keyFactory.getAlgorithm());
		keyAgree.init(priKey);
		keyAgree.doPhase(pubKey, true);
		
		//���ɱ�����Կ
		SecretKey secretKey = keyAgree.generateSecret(SECRET_ALGORITHM);
		return secretKey;
	}
	/**
	 * ȡ��˽Կ
	 * @param keyMap
	 * @return
	 * @throws Exception
	 */
	public static String getPrivateKey(Map<String,Object> keyMap) throws Exception{
		Key key = (Key)keyMap.get(PRIVATE_KEY);
		return encryptBASE64(key.getEncoded());
	}
	/**
	 * ȡ�ù�Կ
	 * @param keyMap
	 * @return
	 * @throws Exception
	 */
	public static String getPublicKey(Map<String,Object> keyMap) throws Exception{
		Key key = (Key)keyMap.get(PUBLIC_KEY);
		return encryptBASE64(key.getEncoded());
	}
}
