package com.erong.model;

import java.util.Date;

import com.erong.model.user.BuyrInf;
import com.erong.model.user.SellrInf;
import com.erong.model.util.CommercialDraft;

/**
 * 央行卖出商业汇票申请报文
 * @author SHENKUN
 *
 */
public class CentralBankSellingDraftsRequest025 extends CommercialDraft{
	
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * 申请日期
	 */
	private Date dt;
	/*
	 * 利率
	 */
	private String intrstRate;
	/*
	 * 实付金额
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
	 * 卖出人信息
	 */
	private SellrInf sellrInf;
	/*
	 * 买入人信息
	 */
	private BuyrInf buyrInf;
}
