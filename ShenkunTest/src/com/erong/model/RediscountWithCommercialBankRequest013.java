package com.erong.model;

import java.util.Date;

import com.erong.model.user.RcvgBkOfRdscntWthComrclBk;
import com.erong.model.util.CommercialDraft;
import com.erong.model.util.ComrclDrft;
import com.erong.model.util.MsgId;
/**
 * ת�������뱨��
 * @author SHENKUN
 *
 */
public class RediscountWithCommercialBankRequest013 extends CommercialDraft{

//	/*
//	 * ���ı�ʶ
//	 */
//	private MsgId msgId;
//	/*
//	 * Ʊ����Ϣ
//	 */
//	private ComrclDrft comrclDrft;
	
	//ת������Ϣ
	/*
	 * ת��������
	 */
	private String ppdMk;
	/*
	 * ת������������
	 */
	private Date dt;
	/*
	 * ת��������
	 */
	private String intrstRate;
	
	/*
	 * ת����ʵ�����
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
	 * ��ؿ�����
	 */
	private Date rpdOpenDt;
	/*
	 * ��ؽ�ֹ��
	 */
	private Date rpdDueDt;
	/*
	 * �������
	 */
	private String rpdIntrstRate;
	/*
	 * ת������ؽ��
	 */
	private String rpdAmt;
	
	/*
	 * ��������Ϣ
	 */
	private RcvgBkOfRdscntWthComrclBk rcvgBkOfRdscntWthComrclBk;
}
