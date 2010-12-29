package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.OrginCollztnBk;
import com.erong.model.user.OrginCollztnPrpsr;
import com.erong.model.util.CommercialDraft;

/**
 * 纸票质押解除登记报文
 * @author SHENKUN
 *
 */
public class RepurchasedCollateralizationRegister106 extends CommercialDraft{
	
	/*
	 * 质押解除日期
	 */
	private Date dt;
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 原质权人信息
	 */
	private OrginCollztnBk orginCollztnBk;
	/*
	 * 原出质人信息
	 */
	private OrginCollztnPrpsr orginCollztnPrpsr;
	/*
	 * 备注
	 */
	private String rmrk;
}
