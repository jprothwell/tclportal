package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * 央行卖出商票信息
 * @author IBM
 *
 */

public class BankSell extends  CommonTransmission034 {
	/*
	 * 申请日期
	 */
	private Date dt;
	/*
	 * 利率
	 */
	private int /*PercentageRate*/ intrstRate;
	/*
	 * 实付金额
	 */
	private int/*CurrencyAndAmount*/ amt;
	/*
	 * 不得转让标记
	 */
	private String /*BanEndorsementMarkCode*/banEndrsmtMk;
	/*
	 * 线上清算标记
	 */
	private String /*SettlementMarkCode*/sttlmMk;
	/*
	 * 卖出人信息
	 */
	private User user;
	/*
	 * 卖出人信息 承接行行号
	 */
	private int /*MaxMin12NumericText*/ agcy;
	/*
	 * 买入人信息
	 */
	private User use1;
}
