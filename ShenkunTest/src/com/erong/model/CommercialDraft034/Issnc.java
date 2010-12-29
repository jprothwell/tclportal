package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * 提示收票
 * @author IBM
 *
 */
public class Issnc extends CommonTransmission034{
	/*
	 * 提示收票签收时间
	 */
	private Date dtTm;
	/*
	 * 收款人类别
	 */
	private String /* RoleCode*/ role;
    /*
     * 收款人名称
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
	 * 出票人信息 账号
	 */
	private String drwrId;
	/*
	 * 出票人开户行行号
	 */
	private int drwrAcctSvcr;
	/*
	 * 承接行行号
	 */
	private int AcctSvcrId;
	

}
