package com.tclPaypal.servlet;

import java.util.List;

import org.springframework.context.ApplicationEvent;
import org.springframework.context.ApplicationListener;

import com.tclPaypal.domain.Business;
import com.tclPaypal.service.BusinessService;
import com.tclPaypal.service.MessageStatuService;
/**
 * 在系统启动时候，初始化数据
 * @author kun.shen
 *
 */
public class LoadSendMessage implements  ApplicationListener{
	
	private BusinessService businessService;
	
	private MessageStatuService messageStatuService;
	
	public void onApplicationEvent(ApplicationEvent arg0) {
		System.out.println("start load message.....");
		List<Business> list = businessService.findBusinessNeedResend();
		messageStatuService.start(list);
		
	}



	
	public void setBusinessService(BusinessService businessService) {
		this.businessService = businessService;
	}

	public void setMessageStatuService(MessageStatuService messageStatuService) {
		this.messageStatuService = messageStatuService;
	}

}
