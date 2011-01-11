package com.tclPaypal.util;

import java.io.Serializable;

public class Constants {
	

	//证书缓存
	public static String CERT_CHCHE = "CERTIFICATE";
	
	//证书信息
	public static String API_USERNAME = "sdk-seller_api1.sdk.com";
	
	public static String API_PASSWORD = "12345678";
	
	public static String CERT_PATH_NAME = "/WEB-INF/cert/sdk-seller.p12";
	
	public static String PRIVATE_KEY_PASSWORD = "password";
	
	public static String CERT_ENVIROMENT = "sandbox";
	
	public static final String GOODS_ID = "goodsId";
	
	public static final String GOODS_DID = "did";
	//真实环境证书信息
//	public static String API_USERNAME = "tmotion_api1.tcl.com";
//	
//	public static String API_PASSWORD = "ERQJDFRB2PH4EZG8";
//	
//	public static String CERT_PATH_NAME = "/WEB-INF/cert/paypal_cert.p12";
//	
//	public static String PRIVATE_KEY_PASSWORD = "ERQJDFRB2PH4EZG8";
//	
//	public static String CERT_ENVIROMENT = "live";
	
	public static final String DOWNLOAD_PATH = "/home/my-onetouch/apps/jakarta-tomcat-5.0.28/webapps/wapPortal/objectsdw/games/";
	
	
	//socket服务器IP地址
	public static final String SOCKET_IP = "";
	//socket端口地址
	public static final int SOCKET_PORT = 7902;
	//socket失效时间
	public static final int SOCKET_TIME = 1200000;
	
	public static final String SHANGMAIL_URL = "http://dev.unikcity.com:11302/payment-webservice/callback/tcl?status=ok&tradeId=";
	
	//加密参数
	public static final String ENCRYPT_ALGORITHM = "RSA";
	
	public static final String SIGN_ALGORITHM = "MD5withRSA";

	public static final String CHARSET = "UTF-8";

	public static final Serializable CERT_SHANGMAIL = "certShangmail";
	
//	public static final String error_rulTest = "http://www.test123.com";
}
