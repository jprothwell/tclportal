package com.erong.model;

import java.util.Date;

import com.erong.model.user.BuyrInf;
import com.erong.model.user.SellrInf;
import com.erong.model.util.CommercialDraft;

/**
 * ����������ҵ��Ʊ���뱨��
 * @author SHENKUN
 *
 */
public class CentralBankSellingDraftsRequest025 extends CommercialDraft{
	
//	/*
//	 * ���ı�ʶ
//	 */
//	private MsgId msgId;
//	/*
//	 * Ʊ����Ϣ
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * ��������
	 */
	private Date dt;
	/*
	 * ����
	 */
	private String intrstRate;
	/*
	 * ʵ�����
	 */
	private String amt;
	/*
	 * ����ת�ñ��
	 */
	private String banEndrsmtMk;
	/*
	 * ����������
	 */
	private String sttlmMk;
	/*
	 * ��������Ϣ
	 */
	private SellrInf sellrInf;
	/*
	 * ��������Ϣ
	 */
	private BuyrInf buyrInf;
}
