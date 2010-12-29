package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * 背书
 * @author IBM
 *
 */

public class Endrsmt extends CommonTransmission034 {
	
	/*
	 * 背书签收时间
	 */
	private Date dtTm;
	/*
	 * 不得转让标记
	 */
	private String /* BanEndorsementMarkCode*/ banEndrsmtMk;
	
	/*
	 * 背书人信息 类别
	 */
	
	private String /* Rolecode*/ role;
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
	private String endrsrId;
	/*
	 * 开户行行号
	 */
	private int endrsrAcctSvcr;
	/*
	 * 承接行行号
	 */
	private int endrsrAgcy;
	/*
	 * 被背书人信息 类别
	 */
	
	private String /*RoleCode*/ endrseerole;
	
	/*
	 * 名称
	 */
	private String endrseenm;
	/*
	 * 组织机构代码
	 */
	private String endrseecmonId;
	/*
	 * 账号
	 */
	private String endrseeId;
	/*
	 * 开户行账号
	 */
	private int endrseeAcctSvcr;
	
	

}
