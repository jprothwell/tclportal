package com.erong.model;

import java.util.Date;

import com.erong.model.util.CommercialDraft;

/**
 * 报文标识
 * @author IBM
 *
 */
public class CommonTransmission034 extends CommercialDraft {
	/*
	 * 请求信息
	 * CommercialDraft 代表报文的基类
	 */
	private CommercialDraft reqInf;
	/*
	 * 票据种类
	 */
	private /* DraftTypeCode*/ String tp;
	
	/*
	 * 出票日期
	 */
	private Date isseDt;
	/*
	 * 到期日
	 */
	private Date dueDt;
	/*
	 * 不得转让标记
	 */
	private String banEndrsmtMk;
	/*
	 * 出票人类别
	 */
	private /*RoleCode*/ String role;
	/*
	 * 出票人名称
	 */
	private String nm;
	/*
	 * 组织机构代码
	 */
	private String cmonId;
	/*
	 * 出票人帐号
	 * 
	 */
	private String acctId;
	/*
	 * 出票人开户行行号
	 */
	private int AcctSvcrid;
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
	 * 收款人信息名称
	 */
	private String PyeeNm;
	/*
	 * 收款人账号
	 */
	private String pyeeAcctId;
	/*
	 * 出票人开户行行号
	 */
	private int pyeeAcctSvcr;
	/*
	 * 票据历史行为信息
	 */
}
