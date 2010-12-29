package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * 提示付款信息
 * @author IBM
 *
 */

public class Prsnttn extends  CommonTransmission034{
	/*
	 * 提示付款申请日期
	 */
	private Date applDt;
	/*
	 * 提示付款签收时间
	 */
	private Date dtTm;
	/*
	 * 提示付款金额
	 */
	private int/*CurrencyAndAmount*/ amt;
	/*
	 * 线上清算标记
	 */
	private String /*SettlementMarkCode*/ sttlmMkString;
	/*
	 * 拒付代码
	 */
	private String /*DishonorCode*/ dshnrCd;
	/*
	 * 拒付备注信息
	 */
	private String dshnrRsn;
	
	/*
	 * 提示付款人信息
	 */
	private User drftHldr;
	/*
	 * 付款人信息
	 */
	private User payBk;
	/*
	 * 付款人信息 承接行行号
	 */
	private int /*MaxMin12NumericText*/ Agcy;
	

}
