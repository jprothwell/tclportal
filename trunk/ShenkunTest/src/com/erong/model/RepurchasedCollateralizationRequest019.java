package com.erong.model;

import java.util.Date;

import com.erong.model.user.CollztnBk;
import com.erong.model.util.CommercialDraft;

/**
 * 质押解除申请报文
 * @author SHENKUN
 *
 */
public class RepurchasedCollateralizationRequest019 extends CommercialDraft{
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * 质押解除申请日期
	 */
	private Date dt;
	/*
	 * 质押解除申请人信息
	 */
	private CollztnBk collztnBk;
}
