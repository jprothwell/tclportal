package com.erong.model;

import java.util.Date;

import com.erong.model.user.RdscntWthCntrlBkSys;
import com.erong.model.util.CommercialDraft;
/**
 * �ع�ʽ������������뱨��
 * @author SHENKUN
 *
 */
public class RepurchasedRediscountWithCentralBankRequest016 extends CommercialDraft{
//	/*
//	 * ���ı�ʶ
//	 */
//	private MsgId msgId;
//	/*
//	 * Ʊ����Ϣ
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * �����������������
	 */
	private Date dt;
	/*
	 * �������������
	 */
	private String rate;
	/*
	 * ���������ʵ�����
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
	 * �����������������Ϣ
	 */
	private RdscntWthCntrlBkSys rdscntWthCntrlBkSys;
	
}
