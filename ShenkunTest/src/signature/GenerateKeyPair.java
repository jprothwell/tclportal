package signature;

import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.SecureRandom;

public class GenerateKeyPair {

	private String privateKey;
	
	private String publicKey;
	
	public void run(){
		//The KeyPairGenerator class is used to generate pairs of public and private keys
		KeyPairGenerator keyPair = null;
		try {
			keyPair = KeyPairGenerator.getInstance("rsa");
			//This class provides a cryptographically strong random number generator (RNG). 
			SecureRandom secure = new SecureRandom();
			secure.setSeed("test".getBytes());
			keyPair.initialize(1024,secure);
		} catch (NoSuchAlgorithmException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		KeyPair key = keyPair.generateKeyPair();
		PublicKey pubKey = key.getPublic();
		PrivateKey priKey = key.getPrivate();
		publicKey = byteToHexStr(pubKey.getEncoded());
		privateKey = byteToHexStr(priKey.getEncoded());
		
		System.out.println(publicKey);
		System.out.println(privateKey);
		
	}
	
	private final String byteToHexStr(byte[] bcd) {
		StringBuffer s = new StringBuffer(bcd.length * 2);

		for (int i = 0; i < bcd.length; i++) {
		s.append(bcdLookup[(bcd[i] >>> 4) & 0x0f]);
		s.append(bcdLookup[bcd[i] & 0x0f]);
		}
		return s.toString();
	}
	
	private static final char[] bcdLookup = { '0', '1', '2', '3', '4', '5',
		'6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	
	public static void main(String[] args){
		GenerateKeyPair keyPair = new GenerateKeyPair();
		keyPair.run();
	}

}
