package com.tclPaypal.service;

import javax.servlet.http.HttpSession;

import net.sf.ehcache.Cache;
import net.sf.ehcache.Element;

import com.paypal.sdk.exceptions.PayPalException;
import com.paypal.sdk.profiles.APIProfile;
import com.paypal.sdk.profiles.ProfileFactory;
import com.paypal.sdk.services.NVPCallerServices;
import com.tclPaypal.util.Constants;

/**
 * 证书加载
 * @author kun.shen
 *
 */
public class CertCacheService {
	
	private Cache cache;
	
	public void setCache(Cache cache) {
		this.cache = cache;
	}
	
	public NVPCallerServices getCertCathe(String certificateFile) throws PayPalException{
		 NVPCallerServices  caller = new NVPCallerServices();
		 Element element = this.cache.get(Constants.CERT_CHCHE);
		 if (null != element) {
			 caller = (NVPCallerServices)element.getObjectValue();
			 return caller;
		 }else{
				APIProfile profile = ProfileFactory.createSSLAPIProfile();
				profile.setAPIUsername(Constants.API_USERNAME);
				profile.setAPIPassword(Constants.API_PASSWORD);
				//profile.setCertificateFile(session.getServletContext().getRealPath(Constants.CERT_PATH_NAME));
				profile.setCertificateFile(certificateFile);
				profile.setPrivateKeyPassword(Constants.PRIVATE_KEY_PASSWORD);
				profile.setEnvironment(Constants.CERT_ENVIROMENT);
				caller.setAPIProfile(profile);
				element = new Element(Constants.CERT_CHCHE, caller);
				this.cache.put(element);
				return caller;
		 }
	}
}

