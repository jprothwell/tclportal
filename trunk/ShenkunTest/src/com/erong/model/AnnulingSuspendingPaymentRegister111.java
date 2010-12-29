package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.util.CommercialDraft;
/**
 * 纸票止付解除登记报文
 * @author SHENKUN
 *
 */
public class AnnulingSuspendingPaymentRegister111 extends CommercialDraft{
	
	/*
	 * 止付解除信息 止付解除类型
	 */
	private String tp;
	/*
	 * 止付解除信息 止付解除日期
	 */
	private Date dt;
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 申请止付解除人信息
	 */
	private String propsrNm;
	/*
	 * 止付解除人信息 
	 */
	private String OprtrNm;
	/*
	 * 备注
	 */
	private String rmrk;
}
