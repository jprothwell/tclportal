package com.erong.model;

import java.util.Date;

import com.erong.model.user.Guarntr;
import com.erong.model.user.Warntee;
import com.erong.model.util.CommercialDraft;

/**
 * 保证申请报文
 * @author SHENKUN
 *
 */
public class GuaranteeRequest017 extends CommercialDraft{
//	/*
//	 * 报文标识
//	 */
//	private MsgId msgId;
//	/*
//	 * 票据信息
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * 保证申请日期
	 */
	private Date dt;
	/*
	 * 被保证人信息
	 */
	private Warntee warntee;
	/*
	 * 保证人信息
	 */
	private Guarntr guarntr;
}
