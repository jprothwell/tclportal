package com.erong.model;

import java.util.Date;

import com.erong.model.util.CommercialDraft;

/**
 * 通用撤回报文
 * @author IBM
 *
 */
public class CancellationRequest032 extends CommercialDraft {

	/*
	 * 原申请报文标识号
	 */
	private String orgnlMsgId;
	/*
	 * 原报文时间
	 */
	private Date orgnlCreDtTm;
	/*
	 * 撤回申请人电子签名
	 */
	private String elctrncSgntr;
	/*
	 * 撤回申请人账号
	 */
	private int acctSvcr;
	/*
	 * 承接行行号
	 */
	private int acctSvcrAgcy;
}
