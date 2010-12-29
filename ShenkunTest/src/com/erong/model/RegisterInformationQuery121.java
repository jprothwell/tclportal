package com.erong.model;

import com.erong.model.user.Accptr;
import com.erong.model.util.CommercialDraft;
/**
 * 纸票登记信息查询报文
 * @author SHENKUN
 *
 */
public class RegisterInformationQuery121 extends CommercialDraft{
	
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 查询行信息 行号
	 */
	private String qryBkAcctSvcr;
}
