package com.erong.model;

import java.util.List;

import com.erong.model.util.CommercialDraft;
import com.erong.model.util.Dtls;
/**
 * 纸票登记信息查复报文
 * @author SHENKUN
 *
 */
public class RegisterInformationResponse122 extends CommercialDraft{
	/*
	 * 原报文标识  待添加
	 */
	
	/*
	 * 承兑信息是否为补充登记信息
	 */
	private String splmtryReg;
	/*
	 * 历史查询信息 次数
	 */
	private int quriesCnt;
	/*
	 * 历史查询信息 详细
	 */
	private List<Dtls> dtls;
	
}
