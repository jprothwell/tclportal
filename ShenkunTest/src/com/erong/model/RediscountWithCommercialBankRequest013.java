package com.erong.model;

import java.util.Date;

import com.erong.model.user.RcvgBkOfRdscntWthComrclBk;
import com.erong.model.util.CommercialDraft;
import com.erong.model.util.ComrclDrft;
import com.erong.model.util.MsgId;
/**
 * 转贴现申请报文
 * @author SHENKUN
 *
 */
public class RediscountWithCommercialBankRequest013 extends CommercialDraft{

//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	
	//转贴现信息
	/*
	 * 转贴现种类
	 */
	private String ppdMk;
	/*
	 * 转贴现申请日期
	 */
	private Date dt;
	/*
	 * 转贴现利率
	 */
	private String intrstRate;
	
	/*
	 * 转贴现实付金额
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
	private String rpdIntrstRate;
	/*
	 * 转贴现赎回金额
	 */
	private String rpdAmt;
	
	/*
	 * 贴出人信息
	 */
	private RcvgBkOfRdscntWthComrclBk rcvgBkOfRdscntWthComrclBk;
}
