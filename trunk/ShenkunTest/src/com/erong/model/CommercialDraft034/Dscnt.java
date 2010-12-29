package com.erong.model.CommercialDraft034;
import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * 贴现
 * @author IBM
 *
 */

public class Dscnt extends CommonTransmission034 {
	/*
	 * 贴现种类
	 */
	private String /*  RepurchasedMarkCode*/ rpdMk;
	
	/*
	 * 贴现签收时间
	 */
	private Date dtTm;
	/*
	 * 贴现利率
	 */
	private String /* PercentageRate */ intrstRate;
	/*
	 * 贴现实付金额
	 */
	private int /*CurrencyAndAmount */ amt;
	/*
	 * 不得转让标记
	 */
	private String /* BanEndorsementMarkCode*/ BanEndrsmtMk;
	/*
	 * 线上清算标记
	 */
	private String /*SettlementMarkCode */ sttlmMk;
	/*
	 * 贴现赎回开放日
	 */
	private Date rpdOpenDt;
	/*
	 * 贴现赎回截止日
	 */
	private Date rpdDueDt;
	/*
	 * 贴现赎回利率
	 */
	private int/* PercentageRate*/ rpdIntrstRate;
	/*
	 * 贴现赎回金额
	 */
	private int /*CurrencyAndAmount*/ rpdAmt;
	/*
	 * 交易合同编号
	 */
	private String  txlCtrctNb;
	/*
	 * 发票号码
	 */
	private String invcNb;
	/*
	 * 贴现协议编号
	 */
	private String dscntAgrmtNb;
	/*
	 * 入账信息 账号
	 */
	private String aOAccnInfId;
	/*
	 * 行号
	 */
	private int aOAccnInfAcctSvcr;
	/*
	 * 贴现申请人信息 类别
	 */
	private String /* RoleCode*/ rscntPropsrrole;
	/*
	 * 账号
	 */
	private String dscntPropsrId;
	/*
	 * 开户行行号
	 */
	private int rscntPropsrAcctSvcr;
	/*
	 * 承接行行号
	 */
	private int dscntPropsrAgcy;
	/*
	 * 贴入人信息 类别
	 */
	private String /*RoleCode*/ dscntBkrole;
	/*
	 * 名称
	 */
	private String dscntBknm;
	/*
	 * 组织机构代码
	 */
	private String dscntBkCmonId;
	/*
	 * 账号
	 */
	private String dscntBkid;
	/*
	 * 行号
	 */
	private int dscntBkCmonAcctSvcr;

}
