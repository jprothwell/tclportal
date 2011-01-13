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
import org.apache.log4j.Logger;
import org.apache.xerces.impl.dv.util.Base64;

import com.tclPaypal.action.BusinessAction;
import com.tclPaypal.util.Constants;

public class SecrityService {
	
	public Logger logger = Logger.getLogger(SecrityService.class);
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	private String privateUrl;
	
	private String publicUrl;
	
	private String PRIVATEKEY = "privateKey";
	
	private String PUBLICKEY = "publicKey";
	
	
	public   Map<String, Object>  init() throws Exception{
		
		Map<String,Object> map = new HashMap<String,Object>();
		Element element = this.cache.get(Constants.CERT_SHANGMAIL);
		 if (null != element) {
			 map = (Map)element.getObjectValue();
			 return map;
		 }else{
			logger.info("publicKey and private key init");
			byte[] priKey =  IOUtils.toByteArray(new FileInputStream(getPrivateUrl()));
			byte[] pubKey =  IOUtils.toByteArray(new FileInputStream(getPublicUrl()));
			
			KeyFactory keyFactory = KeyFactory.getInstance(Constants.ENCRYPT_ALGORITHM);
			//私钥
			EncodedKeySpec privateKeySpec = new PKCS8EncodedKeySpec(priKey);
			PrivateKey privateKey = keyFactory.generatePrivate(privateKeySpec);
			map.put(PRIVATEKEY, privateKey);
			
//			//本地公钥
//			byte[] bubKeyLocal = IOUtils.toByteArray(new FileInputStream("D:/workspace/tclPaypal/WebRoot/WEB-INF/cert/public_key.cer"));
//			EncodedKeySpec publicKeySpeLocal = new X509EncodedKeySpec(bubKeyLocal);
//			PublicKey publicKeyLocal = keyFactory.generatePublic(publicKeySpeLocal);
//			map.put("pubLocal", publicKeyLocal);
			//对方公钥
			EncodedKeySpec publicKeySpec = new X509EncodedKeySpec(pubKey);
			PublicKey publicKey = keyFactory.generatePublic(publicKeySpec);
			map.put(PUBLICKEY, publicKey);
			
			element = new Element(Constants.CERT_SHANGMAIL, map);
			
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
		signature.initVerify((PublicKey)map.get(PUBLICKEY));
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
		signature.initSign((PrivateKey)map.get(PRIVATEKEY));
		signature.update(info.getBytes(Constants.CHARSET));
		return Base64.encode(signature.sign());
	}
	/**
	 * 用本地公钥进行解码
	 * @return
	 */
	public  boolean vertifyLocal(String sign, String info) throws Exception{
		Map<String,Object> map = init();
		Signature signature = Signature.getInstance(Constants.SIGN_ALGORITHM);
		signature.initVerify((PublicKey)map.get("pubLocal"));
		signature.update(info.getBytes(Constants.CHARSET));
		return signature.verify(Base64.decode(sign));
	}
	
	public String getPrivateUrl() {
		return privateUrl;
	}
	public void setPrivateUrl(String privateUrl) {
		this.privateUrl = privateUrl;
	}
	public String getPublicUrl() {
		return publicUrl;
	}
	public void setPublicUrl(String publicUrl) {
		this.publicUrl = publicUrl;
	}
}
