package com.erong.model;

import java.util.Date;

import com.erong.model.user.OrgnlRcvgBkOfRdscntWthComrclBk;
import com.erong.model.util.CommercialDraft;

/**
 * 回购式转贴现赎回申请报文
 * @author SHENKUN
 *
 */
public class RepurchasedRediscountWithCommercialBankRequest014 extends CommercialDraft{

//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	
	//转贴现赎回信息RpdRdscntWthComrclBk
	/*
	 * 转贴现赎回申请日期
	 */
	private Date dt;

	/*
	 * 转贴现赎回利率
	 */
	private String rate;
	/*
	 * 转贴现赎回实付金额
	 */
	private String amt;
	/*
	 * 不得转让标记
	 */
	private String BanEndrsmtMk;
	
	/*
	 * 原贴出人信息
	 */
	 private OrgnlRcvgBkOfRdscntWthComrclBk orgnlRcvgBkOfRdscntWthComrclBk;
}
