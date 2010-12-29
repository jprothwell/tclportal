package com.erong.model;

import com.erong.model.user.DrftHldr;
import com.erong.model.util.CommercialDraft;
/**
 * 提示付款申请报文
 * @author SHENKUN
 *
 */
public class PresentationRequest020 extends CommercialDraft{
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * 提示付款申请日期
	 */
	private String applDt;
	/*
	 * 提示付款金额
	 */
	private String amt;
	/*
	 * 线上清算标记
	 */
	private String sttlmMk;
	/*
	 * 提示付款人信息
	 */
	private DrftHldr drftHldr;
}
