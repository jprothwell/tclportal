package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * 再贴现赎回信息
 * @author IBM
 *
 */

public class RpdRdscntWthCntrlBk extends  CommonTransmission034{
	
	/*
	 * 再贴现赎回签收时间
	 */
	private Date dtTm;
	/*
	 * 再贴现赎回利率
	 */
	private int /*PercentageRate*/ rate;
	/*
	 * 再贴现赎回实付金额
	 */
	private int /*CurrencyAndAmount*/ amt;
	/*
	 * 不得转让标记
	 */
	private String /*BanEndorsementMarkCode*/banEndrsmtMk;
	/*
	 * 线上清算标记
	 */
	private String /*SettlementMarkCode*/ sttlmMk;
	/*
	 * 再贴现赎回申请行信息
	 */
	private User user;
	/*
	 * 承接行行号
	 */
	private int orgnlRqstngBkOfRdscntWthCntrlBkAgcy;
	/*
	 * 再贴现赎回签收人信息
	 */
	private User user1;
	/*
	 * 承接行行号
	 */

	private int rdscntWthCntrlBkSysAcctSvcr;
}
