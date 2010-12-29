package com.erong.model;

import com.erong.model.user.Accptr;
import com.erong.model.user.Drwr;
import com.erong.model.user.Pyee;
import com.erong.model.util.CommercialDraft;

/**
 * 纸票承兑登记报文
 * @author SHENKUN
 *
 */

public class AcceptanceRegister101 extends CommercialDraft{

	/*
	 * 承兑信息
	 */
	private String dt;
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 出票人信息
	 */
	private Drwr drwr;
	/*
	 * 收款人信息
	 */
	private Pyee pyee;
	/*
	 * 备注
	 */
	private String rmrk;
}
