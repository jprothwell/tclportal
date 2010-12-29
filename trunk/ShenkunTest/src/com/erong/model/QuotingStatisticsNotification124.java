package com.erong.model;

import java.util.Date;

import com.erong.model.util.CommercialDraft;
/**
 * 转贴现报价统计信息发布报文
 * @author SHENKUN
 *
 */
public class QuotingStatisticsNotification124 extends CommercialDraft{
	
	/*
	 * 统计开始日期
	 */
	private Date startDt;
	/*
	 * 统计结束日期
	 */
	private Date endDt;
	/*
	 * 统计内容
	 */
	private String cnts;
}
