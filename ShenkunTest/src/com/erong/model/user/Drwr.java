package com.erong.model.user;

/**
 * 出票人信息
 * @author SHENKUN
 *
 */
public class Drwr extends User{
	
	/*
	 * 类别
	 */
	private String role;
	/*
	 * 组织机构代码
	 */
	private String cmonId;
	
	/*
	 * 电子签名
	 */
	private String elctrncSgntr;
	
	/*
	 * 账号
	 */
	private String id;
	/*
	 * 开户行行号
	 */
	private String acctSvcr;
	/*
	 * 信用等级
	 */
	private String cdtRatgs;
	
	/*
	 * 评级机构
	 */
	private String cdtRatgAgcy;
	
	/*
	 * 评级到期日
	 */
	private String cdtRatgDueDt;
}
