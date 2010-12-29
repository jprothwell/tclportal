package com.erong.model.CommercialDraft031;

import java.util.Date;

import com.erong.model.CommonSignUp031;

/**
 * 承兑回复信息
 * @author IBM
 *
 */

public class Accptnc extends CommonSignUp031 {
	
	/*
	 * 承兑回复信息日期
	 */
	
	private Date accptrSgnUpDt;
	
	/*
	 * 承兑回复标记
	 */
	private String accptrSgnUpMk;
	
	/*
	 * 到期无条件支付承诺
	 */
	
	private String ucondlPrmsMrk;
	
	/*
	 * 承兑协议编号
	 */
	
	private String accptncAgrmtNb;
}
