package com.erong.model;

import java.util.Date;

import com.erong.model.user.RdscntWthCntrlBkSys;
import com.erong.model.user.RqstngBkOfRdscntWthCntrlBk;
import com.erong.model.util.CommercialDraft;
/**
 * 再贴现申请报文
 * @author SHENKUN
 *
 */
public class RediscountWithCentralBankRequest015 extends CommercialDraft{
	
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	
	//再贴现信息RdscntWthCntrlBk
	/*
	 * 再贴现种类
	 */
	private String rpdMk;
	/*
	 * 再贴现申请日期
	 */
	private Date dt;
	/*
	 * 再贴现利率
	 */
	private String intrstRate;
	/*
	 * 再贴现实付金额
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
	 * 再贴现赎回开放日
	 */
	private Date rpdOpenDt;
	/*
	 * 再贴现赎回截止日
	 */
	private Date rpdDueDt;
	/*
	 * 再贴现赎回利率
	 */
	private String rpdIntrstRate;
	/*
	 * 再贴现赎回金额
	 */
	private String rpdAmt;
	/*
	 * 贴出人信息
	 */
	private RqstngBkOfRdscntWthCntrlBk rqstngBkOfRdscntWthCntrlBk;
	/*
	 * 贴入行信息
	 */
	private RdscntWthCntrlBkSys rdscntWthCntrlBkSys;
}
