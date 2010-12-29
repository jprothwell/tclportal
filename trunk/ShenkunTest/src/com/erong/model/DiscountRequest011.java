package com.erong.model;

import java.util.Date;

import com.erong.model.user.DscntBk;
import com.erong.model.user.DscntPropsr;
import com.erong.model.util.CommercialDraft;

/**
 * 贴现申请报文
 * @author SHENKUN
 *
 */
public class DiscountRequest011 extends CommercialDraft{
	
//	/*
//	 * 报文标示信息
//	 */
//	private String id;
//	
//	/*
//	 * 报文时间
//	 */
//	private Date creDtTm;
//	
//	/*
//	 * 电子票据号码
//	 */
//	private String idNb;
//	
//	/*
//	 * 票据金额
//	 */
//	private String isseAmt;

	/*
	 * 贴现种类
	 */
	private String rpdMk;
	
	/*
	 * 贴现申请日期
	 */
	private Date dt;
	
	/*
	 * 贴现利率
	 */
	private float intrstRate;
	
	/*
	 * 贴现实付金额
	 */
	private long amt;
	/*
	 * 不得转让标记
	 */
	private String banEndrsmtMk;
	/*
	 * 线上清算标记
	 */
	private String sttlmMk;
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
	private String rpdIntrstRate;
	/*
	 * 贴现赎回金额
	 */
	private String rpdAmt;
	/*
	 * 交易合同编号
	 */
	private String txlCtrctNb;
	/*
	 * 发票号码
	 */
	private String invcNb;
	
	//入账信息
	/*
	 * 帐号
	 */
	private String aOAccnInfId;
	/*
	 * 行号
	 */
	private String aOAccnInfacctSvcr;
	
	/*
	 * 贴现申请人
	 */
	private DscntPropsr dscntPropsr;
	/*
	 * 贴入人信息
	 */
	private DscntBk dscntBk;
}
