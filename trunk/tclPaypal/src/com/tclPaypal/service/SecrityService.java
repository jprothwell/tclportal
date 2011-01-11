package com.tclPaypal.service;

import java.io.FileInputStream;
import java.security.Key;
import java.security.KeyFactory;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.Signature;
import java.security.spec.EncodedKeySpec;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.HashMap;
import java.util.Map;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import org.apache.commons.io.IOUtils;
import org.apache.xerces.impl.dv.util.Base64;

import com.tclPaypal.util.Constants;

public class SecrityService {
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public   Map<String, Object>  init() throws Exception{
		Map<String,Object> map = new HashMap<String,Object>();
		Element element = this.cache.get(Constants.CERT_SHANGMAIL);
		 if (null != element) {
			 map = (Map)element.getObjectValue();
			 return map;
		 }else{
			
			byte[] priKey =  IOUtils.toByteArray(new FileInputStream("D:/workspace/tclPaypal/WebRoot/WEB-INF/cert/private_key.cer"));
			byte[] pubKey =  IOUtils.toByteArray(new FileInputStream("D:/workspace/tclPaypal/WebRoot/WEB-INF/cert/public_key.dat"));
			
			KeyFactory keyFactory = KeyFactory.getInstance(Constants.ENCRYPT_ALGORITHM);
			//私钥
			EncodedKeySpec privateKeySpec = new PKCS8EncodedKeySpec(priKey);
			PrivateKey privateKey = keyFactory.generatePrivate(privateKeySpec);
			map.put("privateKey", privateKey);
			//对方公钥
			EncodedKeySpec publicKeySpec = new X509EncodedKeySpec(pubKey);
			PublicKey publicKey = keyFactory.generatePublic(publicKeySpec);
			
			element = new Element(Constants.CERT_SHANGMAIL, map);
			map.put("publicKey", publicKey);
			this.cache.put(element);
			return map;
		 }
		
	}
	/**
	 * 利用尚邮公钥验证shangmail消息
	 * @param sign
	 * @param info
	 * @return
	 * @throws Exception 
	 */
	public  boolean vertify(String sign, String info) throws Exception{
		Map<String,Object> map = init();
		Signature signature = Signature.getInstance(Constants.SIGN_ALGORITHM);
		signature.initVerify((PublicKey)map.get("publicKey"));
		signature.update(info.getBytes(Constants.CHARSET));
		return signature.verify(Base64.decode(sign));
	}
	/**
	 * 利用本地私钥进行加密
	 * @param info
	 * @return
	 * @throws Exception 
	 */
	public String sign(String info) throws Exception{
		Map<String,Object> map = init();
		Signature signature = Signature.getInstance(Constants.SIGN_ALGORITHM);
		signature.initSign((PrivateKey)map.get("privateKey"));
		signature.update(info.getBytes(Constants.CHARSET));
		return Base64.encode(signature.sign());
	}
}
