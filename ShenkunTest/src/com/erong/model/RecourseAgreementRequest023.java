package com.erong.model;

import java.util.Date;

import com.erong.model.user.RcvgPrsnOfRcrs;
import com.erong.model.util.CommercialDraft;

/**
 * 追索同意清偿申请报文
 * @author SHENKUN
 *
 */
public class RecourseAgreementRequest023 extends CommercialDraft{
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	
	/*
	 * 同意清偿日期
	 */
	private Date dt;
	/*
	 * 同意清偿金额
	 */
	private String amt;
	/*
	 * 同意清偿人信息
	 */
	private RcvgPrsnOfRcrs rcvgPrsnOfRcrs;
}
