package com.erong.model;

import java.util.Date;

import com.erong.model.user.RdscntWthCntrlBkSys;
import com.erong.model.user.RqstngBkOfRdscntWthCntrlBk;
import com.erong.model.util.CommercialDraft;
/**
 * ���������뱨��
 * @author SHENKUN
 *
 */
public class RediscountWithCentralBankRequest015 extends CommercialDraft{
	
//	/*
//	 * ���ı�ʶ
//	 */
//	private MsgId msgId;
//	/*
//	 * Ʊ����Ϣ
//	 */
//	private ComrclDrft comrclDrft;
	
	//��������ϢRdscntWthCntrlBk
	/*
	 * ����������
	 */
	private String rpdMk;
	/*
	 * ��������������
	 */
	private Date dt;
	/*
	 * ����������
	 */
	private String intrstRate;
	/*
	 * ������ʵ�����
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
	 * ��������ؿ�����
	 */
	private Date rpdOpenDt;
	/*
	 * ��������ؽ�ֹ��
	 */
	private Date rpdDueDt;
	/*
	 * �������������
	 */
	private String rpdIntrstRate;
	/*
	 * ��������ؽ��
	 */
	private String rpdAmt;
	/*
	 * ��������Ϣ
	 */
	private RqstngBkOfRdscntWthCntrlBk rqstngBkOfRdscntWthCntrlBk;
	/*
	 * ��������Ϣ
	 */
	private RdscntWthCntrlBkSys rdscntWthCntrlBkSys;
}
