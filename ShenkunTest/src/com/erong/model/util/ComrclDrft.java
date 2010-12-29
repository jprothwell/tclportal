package com.erong.model.util;

import java.util.Date;

/**
 * 票据信息
 * @author SHENKUN
 *
 */
public class ComrclDrft {
	
	/*
	 * 票据种类
	 */
	private String tp;
	
	/*
	 * 票据金额
	 */
	private long isseAmt;
	
	/*
	 * 出票日期
	 */
	private Date issDt;
	
	/*
	 * 到期日
	 */
	private Date dueDt;
	
	/*
	 * 不得转让标记
	 */
	private String banEndrsmtMk;
	
	/*
	 * 电子票据号码
	 */
	private String idNb;
	
	/*
	 * 到期无条件支付委托
	 */
	private String ucondlConsgnmtMrk;
	
	/*
	 * 交易合同编号
	 */
	private String txlCtrctNb;
	/*
	 * 发票号码
	 */
	private String invcNb;
}
