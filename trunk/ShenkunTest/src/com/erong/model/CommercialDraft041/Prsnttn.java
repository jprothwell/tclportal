package com.erong.model.CommercialDraft041;
import java.util.Date;

import com.erong.model.CommonBusinessNotification041;

/**
 * 提示付款信息
 */


public class Prsnttn extends CommonBusinessNotification041{
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
	private int amt;
	/*
	 * 线上清算标记
	 */
	private String sttlmMk;
	/*
	 * 提示付款签收标记
	 */
	private String sgnUpMk;
	/*
	 * 拒付代码
	 */
	private String dshnrCd;
	/*
	 * 拒付理由
	 */
	private String dshnrRsn;

}
