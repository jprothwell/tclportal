package com.erong.model;

import java.util.List;

import com.erong.model.util.CommercialDraft;
import com.erong.model.util.ComrclDrfts;
/**
 * 每月票据信息明细回复报文
 * @author SHENKUN
 *
 */
public class Information079 extends CommercialDraft{
	
	/*
	 * 每月票据信息明细
	 */
	private List<ComrclDrfts> ComrclDrfts;
	/*
	 * 票据历史行为信息  待定
	 */
	private String ComrclDrftBiz;
}
