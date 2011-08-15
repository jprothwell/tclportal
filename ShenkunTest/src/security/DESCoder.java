package security;

import java.security.Key;
import java.security.SecureRandom;

import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.DESKeySpec;

public class DESCoder extends Coder{
	/** 
	#      * ALGORITHM �㷨 <br> 
	#      * ���滻Ϊ��������һ���㷨��ͬʱkeyֵ��size��Ӧ�ı䡣 
	#      *  
	#      * <pre> 
	#      * DES                  key size must be equal to 56 
	#      * DESede(TripleDES)    key size must be equal to 112 or 168 
	#      * AES                  key size must be equal to 128, 192 or 256,but 192 and 256 bits may not be available 
	#      * Blowfish             key size must be multiple of 8, and can only range from 32 to 448 (inclusive) 
	#      * RC2                  key size must be between 40 and 1024 bits 
	#      * RC4(ARCFOUR)         key size must be between 40 and 1024 bits 
	#      * </pre> 
	#      *  
	#      * ��Key toKey(byte[] key)������ʹ���������� 
	#      * <code>SecretKey secretKey = new SecretKeySpec(key, ALGORITHM);</code> �滻 
	#      * <code> 
	#      * DESKeySpec dks = new DESKeySpec(key); 
	#      * SecretKeyFactory keyFactory = SecretKeyFactory.getInstance(ALGORITHM); 
	#      * SecretKey secretKey = keyFactory.generateSecret(dks); 
	#      * </code> 
	   */  
	public static final String ALGORITHM = "DES";
	/**
	 * ת����Կ
	 * @param key
	 * @return
	 * @throws Exception
	 */
	private static Key toKey(byte[] key) throws Exception{
		DESKeySpec dks = new DESKeySpec(key);
		SecretKeyFactory keyFactory = SecretKeyFactory.getInstance(ALGORITHM);
		SecretKey secretKey = keyFactory.generateSecret(dks);
		return secretKey;
	}
	/**
	 * ����
	 * @param data
	 * @param key
	 * @return
	 * @throws Exception
	 */
	public static byte[] decrypt(byte[] data,String key) throws Exception{
		Key k = toKey(decryptBASE64(key));
		
		Cipher cipher = Cipher.getInstance(ALGORITHM);
		cipher.init(Cipher.DECRYPT_MODE, k);
		
		return cipher.doFinal(data);
	}
	/**
	 * ����
	 * @param data
	 * @param key
	 * @return
	 * @throws Exception
	 */
	public static byte[] encrypt(byte[] data,String key) throws Exception{
		Key k = toKey(decryptBASE64(key));
		Cipher cipher = Cipher.getInstance(ALGORITHM);
		cipher.init(Cipher.ENCRYPT_MODE, k);
		return cipher.doFinal(data);
	}
	/**
	 * ������Կ
	 * @return
	 * @throws Exception
	 */
	public static String initKey() throws Exception{
		return initKey(null);
	}
	/**
	 * ������Կ
	 * @param seed
	 * @return
	 * @throws Exception
	 */
	private static String initKey(String seed) throws Exception{
		
		SecureRandom secureRandom = null;
		
		if(seed != null){
			secureRandom = new SecureRandom(decryptBASE64(seed));
		}else{
			secureRandom = new SecureRandom();
		}
		
		KeyGenerator kg = KeyGenerator.getInstance(ALGORITHM);
		kg.init(secureRandom);
		SecretKey secretKey = kg.generateKey();
		return encryptBASE64(secretKey.getEncoded());
	}
	
}