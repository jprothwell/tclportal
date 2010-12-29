package com.erong.model;

import java.util.Date;

import com.erong.model.user.Endrsee;
import com.erong.model.user.Endrsr;
import com.erong.model.util.CommercialDraft;
/**
 * 背书转让申请报文
 * @author SHENKUN
 *
 */
public class DraftEndorsementRequest010 extends CommercialDraft{
	
//	/*
//	 * 报文标示信息
//	 */
//	private String id;
//	
//	/*
//	 * 报文时间
//	 */
//	private Date creDtTm;
//	 
//	/*
//	 * 电子票据号码
//	 */
//	private String idNb;
//	
//	/*
//	 * 票据金额
//	 */
//	private String isseAmt;
	
	/*
	 * 背书申请日期
	 */
	private Date dt;
	
	/*
	 * 不得转让标记
	 */
	private String banEndrsmtMk;
	
	/*
	 * 背书人信息
	 */
	private Endrsr endrsr;
	
	/*
	 * 被背书人信息
	 */
	private Endrsee endrsee;
}
