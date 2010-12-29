package com.erong.model;

import java.util.Date;

import com.erong.model.user.User;
import com.erong.model.util.CommercialDraft;

/**
 * 线上清算结果通知报文
 * 
 * @author IBM
 * 
 */

public class SettlementResultNotification036 extends
		CommercialDraft {
	/*
	 * 原申请报文标识 报文标识号
	 */
	private String orgnlMsgId;

	/*
	 * 原申请报文标识 报文时间
	 */
	private Date orgncreDtTm;
	/* 
	 *即时转账报文信息 特许参与者号码
	 */
	private String trfRef;
	/*
	 * 报文日期
	 */
	private Date tradDt;
	/*
	 * 支付交易序号
	 */
	private String trfId;
	/*
	 * 处理码
	 */
	private String prcCd;
	/*
	 * 处理信息
	 */
	private String prcMsg;
	/*
	 * 签收人信息
	 */
	private User sgnr;
	/*
	 * 签收人信息 承接行行号
	 */
	private int SgnrId;
	/*
	 * 原业务申请人信息信息
	 */
	private User orgnlPropsr;
	/*
	 * 原业务申请人信息信息 承接行行号
	 */
	private int OrgnlPropsrId;
	
}
