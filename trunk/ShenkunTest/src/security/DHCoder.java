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
 * 基于密钥一致协议的加密算法 DH算法
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
	 * 初始化甲方密钥
	 * @return
	 * @throws Exception
	 */
	public static Map<String,Object> initKey() throws Exception{
		KeyPairGenerator keypair = KeyPairGenerator.getInstance(ALGORITHM);
		keypair.initialize(KEY_SIZE);
		
		KeyPair keyPair = keypair.generateKeyPair();
		
		//公钥
		DHPublicKey publicKey = (DHPublicKey)keyPair.getPublic();
		DHPrivateKey privateKey = (DHPrivateKey)keyPair.getPrivate();
		
		Map<String,Object> keyMap = new HashMap<String,Object>();
		keyMap.put(PUBLIC_KEY, publicKey);
		keyMap.put(PRIVATE_KEY, privateKey);
		
		return keyMap;
	}
	/**
	 * 根据甲方密钥初始化乙方密钥对
	 * @param key 甲方公钥
	 * @return
	 * @throws Exception
	 */
	public static Map<String,Object> initKey(String key) throws Exception{
		//获取甲方公钥
		byte[] keyBytes = decryptBASE64(key);
		X509EncodedKeySpec x509KeySpec = new X509EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance(ALGORITHM);
		PublicKey publicKey = keyFactory.generatePublic(x509KeySpec);
		
		//构建自己的私钥对
		DHParameterSpec dhParamSpec = ((DHPublicKey)publicKey).getParams();
		KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance(keyFactory.getAlgorithm());
		keyPairGenerator.initialize(dhParamSpec);
		KeyPair keyPair = keyPairGenerator.generateKeyPair();
		
		//乙方公钥,私钥
		DHPublicKey pubKey = (DHPublicKey)keyPair.getPublic();
		DHPrivateKey priKey = (DHPrivateKey)keyPair.getPrivate();
		Map<String,Object> keyMap = new HashMap<String,Object>(2);
		keyMap.put(PUBLIC_KEY, publicKey);
		keyMap.put(PRIVATE_KEY, priKey);
		
		return keyMap;
	}
	/**
	 * 加密
	 * @param data
	 * @param publicKey
	 * @param privateKey
	 * @return
	 * @throws Exception
	 */
	public static byte[] encrypt(byte[] data,String publicKey,String privateKey) throws Exception{
		//生成本地私钥
		SecretKey scretKey = getSecretKey(publicKey,privateKey);
		
		//数据加密
		Cipher cipher = Cipher.getInstance(scretKey.getAlgorithm());
		cipher.init(Cipher.ENCRYPT_MODE,scretKey);
		return cipher.doFinal(data);
	}
	
	public static byte[] decrypt(byte[] data,String publicKey,String privateKey) throws Exception{
		//生成本地密钥
		SecretKey scretKey = getSecretKey(publicKey,privateKey);
		//数据加密
		Cipher cipher = Cipher.getInstance(scretKey.getAlgorithm());
		cipher.init(Cipher.DECRYPT_MODE, scretKey);
		return cipher.doFinal(data);
	}
	/**
	 * 构建密钥
	 * @param publicKey
	 * @param privateKey
	 * @return
	 * @throws Exception
	 */
	private static SecretKey getSecretKey(String publicKey, String privateKey) throws Exception {
		
		KeyFactory keyFactory = KeyFactory.getInstance(ALGORITHM);
		
		//初始化公钥
		byte[] pubKeyBytes = decryptBASE64(publicKey);
		X509EncodedKeySpec x509KeySpec = new X509EncodedKeySpec(pubKeyBytes);
		PublicKey pubKey = keyFactory.generatePublic(x509KeySpec);
		
		//初始化私钥
		byte[] priKeyBytes = decryptBASE64(privateKey);
		PKCS8EncodedKeySpec pkcs8KeySpec = new PKCS8EncodedKeySpec(priKeyBytes);
		PrivateKey priKey = keyFactory.generatePrivate(pkcs8KeySpec);
		
		KeyAgreement keyAgree = KeyAgreement.getInstance(keyFactory.getAlgorithm());
		keyAgree.init(priKey);
		keyAgree.doPhase(pubKey, true);
		
		//生成本地密钥
		SecretKey secretKey = keyAgree.generateSecret(SECRET_ALGORITHM);
		return secretKey;
	}
	/**
	 * 取得私钥
	 * @param keyMap
	 * @return
	 * @throws Exception
	 */
	public static String getPrivateKey(Map<String,Object> keyMap) throws Exception{
		Key key = (Key)keyMap.get(PRIVATE_KEY);
		return encryptBASE64(key.getEncoded());
	}
	/**
	 * 取得公钥
	 * @param keyMap
	 * @return
	 * @throws Exception
	 */
	public static String getPublicKey(Map<String,Object> keyMap) throws Exception{
		Key key = (Key)keyMap.get(PUBLIC_KEY);
		return encryptBASE64(key.getEncoded());
	}
}
