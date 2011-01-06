package com.tclPaypal.message;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import com.tclPaypal.domain.Business;
import com.tclPaypal.service.BusinessService;

/**
 * 发送确认消息
 * @author kun.shen
 *
 */
public class SendMessage {
	
	private  Business business;

	public SendMessage(Business business){
		this.business = business;
	}
	static ExecutorService execut =  Executors.newFixedThreadPool(10);
	
	public  void send(){
		execut.submit(new ConnectShangmail(business));
	}
}
