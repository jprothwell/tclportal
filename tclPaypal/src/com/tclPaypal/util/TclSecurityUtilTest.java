package com.tclPaypal.util;

import static org.junit.Assert.*;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;

import junit.framework.Assert;

import org.apache.commons.io.IOUtils;
import org.junit.Test;

public class TclSecurityUtilTest {
	
	private static final String ENCRYPT_ALGORITHM = "RSA";

	private static void generateKey() throws NoSuchAlgorithmException,
			IOException {
		KeyPairGenerator keyGen = KeyPairGenerator
				.getInstance(ENCRYPT_ALGORITHM);
		keyGen.initialize(1024);
		KeyPair keyPair = keyGen.generateKeyPair();

		OutputStream privateKeyOut = new FileOutputStream(
				TclSecurityUtil.SHANGMAIL_PRIVATE_KEY_PATH);
		OutputStream publicKeyOut = new FileOutputStream(
				TclSecurityUtil.TCL_PUBLIC_KEY_PATH);

		IOUtils.write(keyPair.getPrivate().getEncoded(), privateKeyOut);
		IOUtils.write(keyPair.getPublic().getEncoded(), publicKeyOut);

		IOUtils.closeQuietly(privateKeyOut);
		IOUtils.closeQuietly(publicKeyOut);
	}

	@Test
	public void testSignAndVerifyFromFile() throws Exception {
		generateKey();
		String orignalInfo = "测试签名";
		String sign = TclSecurityUtil.sign(orignalInfo);
		Assert.assertTrue(TclSecurityUtil.verify(orignalInfo, sign));
	}
}
