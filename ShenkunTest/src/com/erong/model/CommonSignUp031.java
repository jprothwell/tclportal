package com.erong.model;

import java.util.Date;

import com.erong.model.util.CommercialDraft;


/**
 * 通用报文回复
 * 
 * @author IBM
 * 
 */

public class CommonSignUp031 extends CommercialDraft {

	

	/*
	 * 原报文申请标识号
	 */

	private String orgnlMsgId;

	/*
	 * 原报文时间
	 */
	private Date orgnlcreDtTm;


	/*
	 * 回复人类别
	 */

	private String role;

	/*
	 * 回复人组织机构代码
	 */
	private String cmonId;

	/*
	 * 回复人电子签名
	 */
	private String elctrncSgntr;

	/*
	 * 回复人帐号
	 */

	private String sgnrId;

	/*
	 * 回复人开户行行号
	 */

	private int acctSvcr;

	/*
	 * 承接行行号
	 */
	private int acctSvcrNO;
	/*
	 * 承兑人信用等级
	 */

	private String cdtRatgs;

	/*
	 * 承兑人评级机构
	 */

	private String CdtRatgAgcy;

	/*
	 * 承兑人评级到期日
	 */
	private String cdtRatgDueDt;

	/*
	 * 保证人地址
	 */

	private String adr;

	/*
	 * 回复信息
	 */

}
