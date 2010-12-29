package com.erong.model;

import java.util.Date;

import com.erong.model.user.RdscntWthCntrlBkSys;
import com.erong.model.util.CommercialDraft;
/**
 * 回购式再贴现赎回申请报文
 * @author SHENKUN
 *
 */
public class RepurchasedRediscountWithCentralBankRequest016 extends CommercialDraft{
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * 再贴现赎回申请日期
	 */
	private Date dt;
	/*
	 * 再贴现赎回利率
	 */
	private String rate;
	/*
	 * 再贴现赎回实付金额
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
	 * 再贴现赎回申请行信息
	 */
	private RdscntWthCntrlBkSys rdscntWthCntrlBkSys;
	
}
