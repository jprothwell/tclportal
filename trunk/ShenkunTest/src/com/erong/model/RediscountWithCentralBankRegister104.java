package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.RdscntWthCntrlBkSys;
import com.erong.model.user.RqstngBkOfRdscntWthCntrlBk;
import com.erong.model.util.CommercialDraft;

/**
 * 纸票再贴现登记报文
 * @author SHENKUN
 *
 */
public class RediscountWithCentralBankRegister104 extends CommercialDraft{
	
	/*
	 * 再贴现日期
	 */
	private Date dt;
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 贴出人信息
	 */
	private RqstngBkOfRdscntWthCntrlBk rqstngBkOfRdscntWthCntrlBk;
	/*
	 * 贴入人信息
	 */
	private RdscntWthCntrlBkSys rdscntWthCntrlBkSys;
	/*
	 * 备注
	 */
	private String rmrk;
}
