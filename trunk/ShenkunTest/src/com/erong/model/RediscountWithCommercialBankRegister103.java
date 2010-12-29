package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.RcvgBkOfRdscntWthComrclBk;
import com.erong.model.user.RqstngBkOfRdscntWthComrclBk;
import com.erong.model.util.CommercialDraft;

/**
 * 纸票转贴现登记报文
 * @author SHENKUN
 *
 */
public class RediscountWithCommercialBankRegister103 extends CommercialDraft{

	/*
	 * 转贴现日期
	 */
	private Date dt;
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 贴出人信息
	 */
	private RqstngBkOfRdscntWthComrclBk rqstngBkOfRdscntWthComrclBk;
	/*
	 * 贴入人信息
	 */
	private RcvgBkOfRdscntWthComrclBk rcvgBkOfRdscntWthComrclBk;
	/*
	 * 备注
	 */
	private String rmrk;
}
