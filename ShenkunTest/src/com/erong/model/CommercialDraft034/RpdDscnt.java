package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * 回购式贴现赎回
 * @author IBM
 *
 */
public class RpdDscnt extends CommonTransmission034 {
	/*
	 * 贴现赎回签收时间
	 */
	private Date dtTm;
	/*
	 * 贴现赎回利率
	 */
	private int/* PercentageRate*/ rate;
	/*
	 * 贴现赎回实付金额
	 */
	private int /*CurrencyAndAmount*/ amt;
	/*
	 * 不得转让标记
	 */
	private String /*BanEndorsementMarkCode*/ banEndrsmtMk ;
	
	/*
	 * 贴现赎回申请人信息（原贴入人）类别
	 */
	private String /* RoleCode*/ dscntBkrole;
	/*
	 * 名称
	 */
	private String dscntBknm;
	/*
	 * 组织机构代码
	 */
	private String dscntBkcmonId;
	/*
	 * 账号
	 */
	private String dscntBkacctid;
	/*
	 * 开户行行号
	 */
	private int dscntBkAcctSvcrid;
	/*
	 * 承接行行号
	 */
	private int  dscntBkAgcyid;
	
	/*
	 * 贴现赎回签收人信息（原贴现申请人) 类别
	 */
	
	private String /*RoleCode*/ orgnlDscntPropsrrole;
	/*
	 * 名称
	 */
	private String orgnlDscntPropsrnm;
	/*
	 * 组织机构代码
	 */
	private String orgnlDscntPropsrcmonId;
	/*
	 * 账号
	 */
	private String orgnlDscntPropsracct;
	/*
	 * 行号
	 */
	private int  orgnlDscntPropsracctSvcr;
	/*
	 * 承接行行号
	 */
	private int  orgnlDscntPropsrAgcy;

}
