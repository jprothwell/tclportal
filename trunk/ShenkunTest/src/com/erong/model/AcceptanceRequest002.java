package com.erong.model;

import com.erong.model.user.Accptr;
import com.erong.model.user.Drwr;
import com.erong.model.util.CommercialDraft;
/**
 * 提示承兑报文
 * @author SHENKUN
 *
 */

public class AcceptanceRequest002 extends CommercialDraft{	
	/*
	 * 承兑人信息
	 */
	private Accptr accptr;
	/*
	 * 出票人信息
	 */
	private Drwr drwr;
}
