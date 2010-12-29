package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.Pyee;
import com.erong.model.util.CommercialDraft;
/**
 * 纸票拒付登记报文
 * @author SHENKUN
 *
 */
public class PaymentRefusedRegister109 extends CommercialDraft{
	
	/*
	 * 拒付日期
	 */
	private Date dt;
	/*
	 * 拒付代码
	 */
	private String dshnrCd;
	/*
	 * 拒付备注信息
	 */
	private String dshnrRsn;
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
