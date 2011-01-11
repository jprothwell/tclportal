package com.tclPaypal.util;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.security.InvalidKeyException;
import java.security.Key;
import java.security.KeyFactory;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.security.SignatureException;
import java.security.spec.EncodedKeySpec;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;

import org.apache.commons.io.IOUtils;
import org.apache.log4j.Logger;
import org.apache.xerces.impl.dv.util.Base64;

public class TclSecurityUtil {
	
	public static  Logger LOG = Logger.getLogger(TclSecurityUtil.class);
	
	private static final String SIGN_ALGORITHM = "MD5withRSA";
	private static final String CHARSET = "utf-8";
	private static final String ENCRYPT_ALGORITHM = "RSA";
	// TODO should be load from config file
	static final String SHANGMAIL_PRIVATE_KEY_PATH = "D:/private_key.cer";
	// TODO should be load from config file
	static final String TCL_PUBLIC_KEY_PATH = "D:/public_key.cer";

	public static String sign(String info) {
		PrivateKey privateKey = (PrivateKey) loadKeyFromFile(SHANGMAIL_PRIVATE_KEY_PATH, PrivateKey.class);
		return sign(info, privateKey);
	}

	public static boolean verify(String orignalInfo, String sign) {
		PublicKey publicKey = (PublicKey) loadKeyFromFile(TCL_PUBLIC_KEY_PATH,
				PublicKey.class);
		return verify(sign, orignalInfo, publicKey);
	}

	private static Key loadKeyFromFile(String filePath, Class keyType) {
		byte[] key = null;
		
		try {
			key = IOUtils.toByteArray(new FileInputStream(filePath));
		} catch (FileNotFoundException e) {
			LOG.error(e.getMessage(), e);
		} catch (IOException e) {
			LOG.error(e.getMessage(), e);
		}

		try {

			KeyFactory keyFactory = KeyFactory.getInstance(ENCRYPT_ALGORITHM);

			if (keyType == PrivateKey.class) {
				EncodedKeySpec privateKeySpec = new PKCS8EncodedKeySpec(key);
				return keyFactory.generatePrivate(privateKeySpec);

			} else if (keyType == PublicKey.class) {

				EncodedKeySpec publicKeySpec = new X509EncodedKeySpec(key);
				return keyFactory.generatePublic(publicKeySpec);
			}

		} catch (NoSuchAlgorithmException e) {
			LOG.error(e.getMessage(), e);
			
		} catch (InvalidKeySpecException e) {
			LOG.error(e.getMessage(), e);
		}
		return null;
	}

	private static String sign(String info, PrivateKey privateKey) {
		Signature signature;
		try {
			signature = Signature.getInstance(SIGN_ALGORITHM);
			signature.initSign(privateKey);
			signature.update(info.getBytes(CHARSET));
			return Base64.encode(signature.sign());
		} catch (NoSuchAlgorithmException e) {
			LOG.error(e.getMessage(), e);
		} catch (InvalidKeyException e) {
			LOG.error(e.getMessage(), e);
		} catch (SignatureException e) {
			LOG.error(e.getMessage(), e);
		} catch (UnsupportedEncodingException e) {
			LOG.error(e.getMessage(), e);
		}
		return null;
	}

	private static boolean verify(String sign, String info, PublicKey publicKey) {

		try {

			Signature signature = Signature.getInstance(SIGN_ALGORITHM);
			signature.initVerify(publicKey);
			signature.update(info.getBytes(CHARSET));

			return signature.verify(Base64.decode(sign));

		} catch (InvalidKeyException e) {
			LOG.error(e.getMessage(), e);
		} catch (NoSuchAlgorithmException e) {
			LOG.error(e.getMessage(), e);
		} catch (SignatureException e) {
			LOG.error(e.getMessage(), e);
		} catch (UnsupportedEncodingException e) {
			LOG.error(e.getMessage(), e);
		}
		return false;
	}
}
