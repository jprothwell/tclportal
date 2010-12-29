package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.util.CommercialDraft;

/**
 * 纸票未用退回登记报文
 * @author SHENKUN
 *
 */
public class DrawingbackRegister125 extends CommercialDraft{
	
	/*
	 * 未用退回日期
	 */
	private Date drwgBckDt; 
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 备注
	 */
	private String addtlInf;
}
