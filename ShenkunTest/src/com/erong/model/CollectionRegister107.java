package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.ColltgBk;
import com.erong.model.util.CommercialDraft;

/**
 * 纸票委托收款登记报文
 * @author SHENKUN
 *
 */
public class CollectionRegister107 extends CommercialDraft{
	
	/*
	 * 委托收款日期
	 */
	private Date dt;
	/*
	 * 背书次数
	 */
	private int endrsmtCnt;
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 委托收款银行名称
	 */
	private ColltgBk colltgBk;
	/*
	 * 最后一手持票人信息名称
	 */
	private String nm;
	/*
	 * 备注
	 */
	private String rmrk; 
}
