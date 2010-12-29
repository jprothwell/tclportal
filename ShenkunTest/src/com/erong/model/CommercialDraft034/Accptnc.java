package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * 提示承兑信息
 * @author IBM
 *
 */
public class Accptnc extends CommonTransmission034 {
	
	/*
	 * 提示承兑签收时间
	 */
	private Date accptrSgnUpDtTm;
	/*
	 * 到期无条件支付委托
	 */
	private String /*ConsignmentCode */ ucondlConsgnmtMrk;
	/*
	 * 到期无条件支付承诺
	 */
	private String /* ConsignmentCode*/ ucondlPrmsMrk;
	/*
	 * 交易合同编号
	 */
	private String txlCtrctNb;
	/*
	 * 发票号码
	 */
	private String invcNb;
	/*
	 * 承兑协议编号
	 */
	private String accptncAgrmtNb;
	
	/*
	 * 承兑人信息
	 */
	
	
	/*
	 * 类别
	 */
	private /*RoleCode */String role;
	
	/*
	 * 名称
	 */
	private String nm;
	
	/*
	 * 组织机构代码
	 */
	private String cmonId;
	/*
	 * 账号
	 */
	private String acctId;
	/*
	 * 开户行行号
	 */
	private int AcctSvcr;
	/*
	 * 信用等级
	 */
	private String cdtRatgs;
	/*
	 * 评级机构
	 */
	private String cdtRatgAgcy;
	/*
	 * 评级到期日
	 */
	private Date cdtRatgDueDt;

	
	/*
	 * 出票人信息
	 */
	
	/*
	 * 账号
	 */
	private String drwrId;
	
	/*
	 * 开户行行号
	 */
	private int drwrAcctSvcr;
	/*
	 * 承接行行号
	 */
	private int  drwrAgcy;
	
	
	
}
