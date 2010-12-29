package com.erong.model;
import com.erong.model.user.Drwr;
import com.erong.model.user.Pyee;
import com.erong.model.util.CommercialDraft;

/**
 * 出票人登记
 * @author SHENKUN
 *
 */
public class RegisterRequest001 extends CommercialDraft{

	/*
	 * 出票人信息
	 */
	private Drwr drwr;
	/*
	 * 收款人信息
	 */
	private Pyee pyee;
}
