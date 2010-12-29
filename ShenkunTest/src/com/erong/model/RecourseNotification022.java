package com.erong.model;

import java.util.Date;

import com.erong.model.user.Rcrsr;
import com.erong.model.user.RcvgPrsnOfRcrs;
import com.erong.model.util.CommercialDraft;

/**
 * 追索通知报文
 * @author SHENKUN
 *
 */
public class RecourseNotification022 extends CommercialDraft{
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * 追索类型
	 */
	private String tp;
	/*
	 * 追索通知日期
	 */
	private Date applDt;
	/*
	 * 追索金额
	 */
	private String reqAmt;
	/*
	 * 追索人信息
	 */
	private Rcrsr rcrsr;
	/*
	 * 被追索信息
	 */
	private RcvgPrsnOfRcrs rcvgPrsnOfRcrs;
}
