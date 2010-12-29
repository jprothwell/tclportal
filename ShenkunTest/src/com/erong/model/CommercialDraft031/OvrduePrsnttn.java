package com.erong.model.CommercialDraft031;

import java.util.Date;

import com.erong.model.CommonSignUp031;

/**
 * 提示付款回复信息
 * @author IBM
 *
 */
public class OvrduePrsnttn extends CommonSignUp031 {
	/*
	 * 逾期提示付款回复日期
	 */
	private Date dt;
	
	/*
	 * 逾期提示付款回复标记
	 */
	private String sgnUpMk;
	
	/*
	 * 拒付代码
	 */
	private String dshnrCd;
	
	/*
	 * 拒付备注信息
	 */
	private String dshnrRsn;

}
