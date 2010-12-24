package com.tclPaypal.service;

import java.util.ArrayList;
import java.util.List;

import org.apache.log4j.Logger;

import com.tclPaypal.domain.Business;

public class MessageStatuService {
	
	public Logger logger = Logger.getLogger(MessageStatuService.class);
	
	//保存交易信息
	private List<Business> messageList = new ArrayList<Business>();
	
	public void add(){
		//交易没有得到返回信息，增加在list中
	}
	
	public void remove(){
		//收到回复后移除
	}
	
	public void update(){
		//更新状态
	}
	
	public List getResendMessage(){
		return messageList;
	}
}
