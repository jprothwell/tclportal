package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * 追索
 * @author IBM
 *
 */

public class Rcrs extends  CommonTransmission034 {
	/*
	 * 追索类型
	 */
	private String /*RecourseTypeCode*/tp;
	/*
	 * 追索通知日期
	 */
	private Date applDt;
	/*
	 * 清偿日期
	 */
	private Date dt;
	/*
	 * 追索金额
	 */
	private int /*CurrencyAndAmount*/ reqAmt;
	/*
	 * 清偿金额
	 */
	private int/*CurrencyAndAmount*/ amt;
	
	/*
	 * 追索人信息信息
	 */
	
	private User drftHldr;
	/*
	 * 追索人信息信息 承接行行号
	 */
	
	private int/*MaxMin12NumericText*/ drftHldrAgcy;
	/*
	 * 清偿人信息
	 */
	
	private User payBk;
	
	/*
	 * 清偿人信息 承接行行号
	 */
	private int /*MaxMin12NumericText*/ payBkAgcy;
	

}
