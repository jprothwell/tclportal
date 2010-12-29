package com.erong.model;

import java.util.Date;

import com.erong.model.user.DscntBk;
import com.erong.model.util.CommercialDraft;
/**
 * 回购式贴现赎回申请报文
 * @author SHENKUN
 *
 */
public class RepurchasedDiscountRequest012 extends CommercialDraft{
//	
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	
	//贴现赎回信息
	/*
	 * 贴现赎回申请日期
	 */
	private Date dt;
	/*
	 * 贴现赎回利率
	 */
	private String rate;
	/*
	 * 贴现赎回实付金额
	 */
	private String amt;
	/*
	 * 不得转让标记
	 */
	private String banEndrsmtMk;
	/*
	 * 线上清算标记
	 */
	private String sttlmMk;
	/*
	 * 原贴入人
	 */
	private DscntBk dscntBk;
}
