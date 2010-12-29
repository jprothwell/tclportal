package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * 回购式转贴现赎回
 * @author IBM
 *
 */

public class RpdRdscntWthComrclBk  extends CommonTransmission034{
	
	/*
	 * 转贴现赎回签收时间
	 */
	private Date dtTm;
	/*
	 * 转贴现赎回利率
	 */
	private int /*PercentageRate*/ rate;
	/*
	 * 转贴现赎回实付金额
	 */
	private int /*CurrencyAndAmount*/ amt;
	/*
	 * 不得转让标记
	 */
	private String /**/banEndrsmtMk;

}
