package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.util.CommercialDraft;

/**
 * 纸票挂失止付及公示催告登记报文
 * @author SHENKUN
 *
 */
public class SuspendingPaymentRegister110 extends CommercialDraft{
	/*
	 * 止付登记信息  止付类型
	 */
	private String sspdgPmtTp;
	/*
	 * 止付登记信息 申请止付日期
	 */
	private Date dt;
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 申请止付人信息
	 */
	private String propsrNm;
	/*
	 * 受理挂失止付人信息
	 */
	private String oprtrNm;
	/*
	 * 备注
	 */
	private String rmrk;
}
