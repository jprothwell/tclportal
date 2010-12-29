package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * 转贴现
 * @author IBM
 *
 */

public class RdscntWthComrclBk extends CommonTransmission034{
	/*
	 * 转贴现种类
	 */
	private String /*RepurchasedMarkCode*/ rpdMk;
	/*
	 * 转贴现签收时间
	 */
	private Date dtTm;
	/*
	 * 转贴现利率
	 */
	private int /*PercentageRate*/ rate;
	/*
	 * 转贴现实付金额
	 */
	private int /*CurrencyAndAmount*/amt;
	/*
	 * 不得转让标记
	 */
	private String /*BanEndorsementMarkCode*/ banEndrsmtMk;
	/*
	 * 线上清算标记
	 */
	
	private String /*SettlementMarkCode*/ sttlmMk;
	/*
	 * 赎回开放日
	 */
	private Date rpdOpenDt;
	/*
	 * 赎回截止日
	 */
	private Date rpdDueDt;
	/*
	 * 赎回利率
	 */
	private int/*PercentageRate*/ RpdIntrstRate;
	/*
	 * 转贴现赎回金额
	 */
	private int /*CurrencyAndAmount*/ rpdAmt;
	/*
	 * 贴出人信息  类别
	 */
	private String /*RoleCode*/ rqstngBkOfRdscntWthComrclBkrole;
	/*
	 * 名称
	 */
	private String rqstngBkOfRdscntWthComrclBknm;
	/*
	 * 组织机构代码
	 */
	private String rqstngBkOfRdscntWthComrclBkcmonId;
	/*
	 * 账号
	 */
	private String rqstngBkOfRdscntWthComrclBkAcctId;
	/*
	 * 行号
	 */
	private String  rqstngBkOfRdscntWthComrclBkAcctSvcr;
	/*
	 * 承接行行号
	 */
	private int rqstngBkOfRdscntWthComrclBkAgcy;
	/*
	 * 贴入人信息 类别
	 */
	private String /*RoleCode*/ rcvgBkOfRdscntWthComrclBkRole;
	/*
	 * 名称
	 */
	private String rcvgBkOfRdscntWthComrclBkRNM;
	/*
	 * 组织机构代码
	 */
	private String rcvgBkOfRdscntWthComrclBkRCmonId;
	/*
	 * 账号
	 */
	private String rcvgBkOfRdscntWthComrclBkAcctid;
	/*
	 * 行号
	 */
	private int rcvgBkOfRdscntWthComrclBkAcctSvcr;
}
