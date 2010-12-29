package com.erong.model.CommercialDraft041;
import java.util.Date;

import com.erong.model.CommonBusinessNotification041;

/**
 * 追索
 */


public class Rcrs extends CommonBusinessNotification041{
	/*
	 * 追索类型
	 */
	private String tp;
	/*
	 * 追索通知日期
	 */
	private Date applDt ;
	/*
	 * 清偿时间
	 */
	private Date dtTm;
	/*
	 * 追索金额
	 */
	private int reqAmt;
	/*
	 * 清偿金额
	 */
	private int amt;
}
