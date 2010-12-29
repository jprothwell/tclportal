package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.DscntBk;
import com.erong.model.user.DscntPropsr;
import com.erong.model.util.CommercialDraft;

/**
 * 纸票贴现登记报文
 * @author SHENKUN
 *
 */
public class DiscountRegister102 extends CommercialDraft{
	
	/*
	 * 贴现日期
	 */
	private Date dt;
	
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 贴出人信息
	 */
	private DscntPropsr dscntPropsr;
	/*
	 * 贴入人信息
	 */
	private DscntBk dscntBk;
	/*
	 * 备注
	 */
	private String rmrk;
}
