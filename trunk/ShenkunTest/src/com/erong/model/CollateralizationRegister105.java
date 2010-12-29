package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.CollztnBk;
import com.erong.model.user.CollztnPropsr;
import com.erong.model.util.CommercialDraft;

/**
 * 纸票质押登记报文
 * @author SHENKUN
 *
 */
public class CollateralizationRegister105 extends CommercialDraft{
	
	/*
	 * 质押信息
	 */
	private Date dt; 
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 出质人信息
	 */
	private CollztnPropsr collztnPropsr;
	/*
	 * 质权人信息
	 */
	private CollztnBk collztnBk;
	/*
	 * 备注
	 */
	private String addtlInf;
}
