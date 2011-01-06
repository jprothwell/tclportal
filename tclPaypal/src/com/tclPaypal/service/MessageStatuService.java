package com.tclPaypal.service;

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

import org.apache.log4j.Logger;

import com.tclPaypal.domain.Business;

public class MessageStatuService {
	
	public Logger logger = Logger.getLogger(MessageStatuService.class);
	
	//保存交易信息
	private List<Business> messageList = Collections.synchronizedList(new LinkedList<Business>());
	

	public void add(Business business){
		//交易没有得到返回信息，增加在list中
		messageList.add(business);
	}
	
	public void remove(Business business){
//		//收到回复后移除
//		Iterator<Business> iter = messageList.iterator();
//		while(iter.hasNext()){
//			Business bus = iter.next();
//			if(bus.getToken().equals(business.getToken())){
//				iter.remove();
//			}
//		}
		messageList.remove(business);
	
	}
	
	public List<Business> getResendMessage(){
		return messageList;
	}
	public void start(List<Business> list) {
		messageList.addAll(list);
	}
}
