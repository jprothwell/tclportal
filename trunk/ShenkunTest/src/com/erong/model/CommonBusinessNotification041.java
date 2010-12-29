package com.erong.model;

import com.erong.model.user.User;
import com.erong.model.util.CommercialDraft;
/**
 * 通用业务通知报文
 * @author IBM
 *
 */

public class CommonBusinessNotification041 extends CommercialDraft{
	/*
	 * 申请人信息
	 */
	
	private User rqstr;
	
	/*
	 * 申请人信息 承接行行号
	 */
	
	private int rqstrAgcy;
	
	
	/*
	 * 签收人信息
	 */
	
	private User sgnr;
	
	/*
	 * 签收人信息 承接行行号
	 */
	private int sgnrAgcy;
	
	/*
	 * 保证人地址
	 */

	private String adr;
}
