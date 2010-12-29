package com.erong.model;

import java.util.Date;

import com.erong.model.user.DrftHldr;
import com.erong.model.util.CommercialDraft;
/**
 * 逾期提示付款申请报文
 * @author SHENKUN
 *
 */
public class OverduePresentationRequest021 extends CommercialDraft{

//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * 逾期提示付款申请日期
	 */
	private Date applDt;
	/*
	 * 逾期提示付款金额
	 */
	private String amt;
	/*
	 * 逾期原因说明
	 */
	private String rsn;
	/*
	 * 线上清算标记
	 */
	private String sttlmMk;
	/*
	 * 逾期提示付款人信息
	 */
	private DrftHldr drftHldr;
}
