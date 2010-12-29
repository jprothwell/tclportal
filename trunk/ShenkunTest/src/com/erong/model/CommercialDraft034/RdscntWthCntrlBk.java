package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * 再贴现信息
 * @author IBM
 *
 */

public class RdscntWthCntrlBk 	extends  CommonTransmission034{
	/*
	 * 再贴现种类
	 */
	private String /*RepurchasedMarkCode*/ rpdMk;
	/*
	 * 再贴现申请日期
	 */
	private Date dt;
	
	private int /*PercentageRate*/ intrstRate;
	/*
	 * 再贴现实付金额
	 */
	private int /*CurrencyAndAmount*/amt;
	/*
	 * 不得转让标记
	 */
	private String /*BanEndorsementMarkCode*/ banEndrsmtMk;
	/*
	 * 线上清算标记
	 */
	private String /*SettlementMarkCode*/ sttlmMk;
	/*
	 * 再贴现赎回开放日
	 */
	private Date rpdOpenDt;
	/*
	 * 再贴现赎回截止日
	 */
	private Date rpdDueDt;
	/*
	 * 再贴现赎回利率
	 */
	private int /*PercentageRate*/ rpdIntrstRate;
	/*
	 * 再贴现赎回金额
	 */
	private int/*CurrencyAndAmount*/ rpdAmt;
	/*
	 * 贴出人信息 
	 */
	private User RequestingBankOfRediscountWithCentralBank;
	
	/*
	 * 贴出行信息
	 */
    private User RediscountWithCentralBankSystem;
}
