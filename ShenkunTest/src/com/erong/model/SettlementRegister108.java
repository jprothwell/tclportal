package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.Pyee;
import com.erong.model.util.CommercialDraft;
/**
 * 纸票结清登记报文
 * @author SHENKUN
 *
 */
public class SettlementRegister108 extends CommercialDraft{

	/*
	 * 付款日期
	 */
	private Date payDt;
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 最后一手持票人信息
	 */
	private Pyee pyee;
	/*
	 * 备注
	 */
	private String rmrk;
}
