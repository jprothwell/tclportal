package com.erong.model;

import java.util.Date;

import com.erong.model.util.CommercialDraft;
/**
 * 清分失败回复报文
 * @author IBM
 *
 */

public class ExceptionNotification035 extends CommercialDraft {
	
	/*
	 * 原申请报文标识 报文标识号
	 */
	private String orgnlMsgId;
	
	/*
	 * 原申请报文标识 报文时间
	 */
	private Date orgncreDtTm;
	/*
	 * 异常信息 异常处理码
	 */
	private String /*ExceptionCode*/ xcptnCd;
	/*
	 * 异常消息
	 */
	private String /*Max60Text*/ xcptnMsg;

}
