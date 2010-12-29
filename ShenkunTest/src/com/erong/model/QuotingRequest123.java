package com.erong.model;

import java.util.Date;
import java.util.List;

import com.erong.model.user.Brdcstee;
import com.erong.model.user.Qtr;
import com.erong.model.util.CommercialDraft;

/**
 * 转贴现报价发布报文
 * @author SHENKUN
 *
 */
public class QuotingRequest123 extends CommercialDraft{
	
	/*
	 * 报价方式
	 */
	private String qtgTp;
	/*
	 * 业务类型
	 */
	private String bizTp;
	/*
	 * 金额
	 */
	private String amt;
	/*
	 * 利率
	 */
	private String intrstRate;
	/*
	 * 期限
	 */
	private Date rmdrMtrty;
	/*
	 * 承兑人范围
	 */
	private String accptrScp;
	/*
	 * 票据类型
	 */
	private String drftTp;
	/*
	 * 报价方信息
	 */
	private Qtr qtr;
	/*
	 * 定向发送方式接收方信息
	 */
	private List<Brdcstee> brdcstees;
}
