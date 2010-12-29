package com.erong.model;

import java.util.Date;

import com.erong.model.util.CommercialDraft;

/**
 * 通用确认报文
 * @author IBM
 *
 */
public class CommonStatus033 extends CommercialDraft {
	/*
	 * 原申请报文标识号
	 */
	private String orgnlMsgId;
	/*
	 * 原申请报文时间
	 */
	private Date orgnlCreDtTm;
	/*
	 * 报文处理码
	 */
	private String prcCd;
	/*
	 * 处理信息
	 */
	private String prcMsg;

}
