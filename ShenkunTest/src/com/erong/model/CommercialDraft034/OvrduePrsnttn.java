package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * 逾期提示付款信息
 * @author IBM
 *
 */

public class OvrduePrsnttn extends  CommonTransmission034{
	/*
	 * 逾期提示付款申请日期
	 */
	private Date applDt;
	/*
	 * 逾期提示付款签收时间
	 */
	private Date dtTmDate;
	/*
	 * 逾期提示付款金额
	 */
	private int /*CurrencyAndAmount*/ amt;
	/*
	 * 逾期原因说明
	 */
	private String /*Max256Text*/ rsn;
	/*
	 * 线上清算标记
	 */
	private String /*SettlementMarkCode*/sttlmMkString;
	/*
	 * 拒付代码
	 */
	private String /*DishonorCode*/ dshnrCd;
	/*
	 * 拒付备注信息
	 */
	private String /*Max256Text*/ dshnrRsn;
	/*
	 * 逾期提示付款人信息
	 */
	
	private User drftHldr;
	/*
	 * 逾期提示付款人信息 承接行行号
	 */
	
	private int/*MaxMin12NumericText*/ drftHldrAgcy;
	/*
	 * 付款人信息
	 */
	
	private User payBk;
	
	/*
	 * 付款人信息 承接行行号
	 */
	private int /*MaxMin12NumericText*/ payBkAgcy;
}
