package com.erong.model;

import com.erong.model.user.CollztnBk;
import com.erong.model.user.CollztnPropsr;
import com.erong.model.util.CommercialDraft;

/**
 * 质押申请报文
 * @author SHENKUN
 *
 */
public class CollateralizationRequest018 extends CommercialDraft{
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * 质押申请日期
	 */
	private String dt;
	/*
	 * 出质人信息
	 */
	private CollztnPropsr collztnPropsr;
	/*
	 * 质权人信息
	 */
	private CollztnBk collztnBk;
}
