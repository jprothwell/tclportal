package com.erong.model;

import java.util.Date;

import com.erong.model.user.DscntBk;
import com.erong.model.user.DscntPropsr;
import com.erong.model.util.CommercialDraft;

/**
 * �������뱨��
 * @author SHENKUN
 *
 */
public class DiscountRequest011 extends CommercialDraft{
	
//	/*
//	 * ���ı�ʾ��Ϣ
//	 */
//	private String id;
//	
//	/*
//	 * ����ʱ��
//	 */
//	private Date creDtTm;
//	
//	/*
//	 * ����Ʊ�ݺ���
//	 */
//	private String idNb;
//	
//	/*
//	 * Ʊ�ݽ��
//	 */
//	private String isseAmt;

	/*
	 * ��������
	 */
	private String rpdMk;
	
	/*
	 * ������������
	 */
	private Date dt;
	
	/*
	 * ��������
	 */
	private float intrstRate;
	
	/*
	 * ����ʵ�����
	 */
	private long amt;
	/*
	 * ����ת�ñ��
	 */
	private String banEndrsmtMk;
	/*
	 * ����������
	 */
	private String sttlmMk;
	/*
	 * ������ؿ�����
	 */
	private Date rpdOpenDt;
	/*
	 * ������ؽ�ֹ��
	 */
	private Date rpdDueDt;
	/*
	 * �����������
	 */
	private String rpdIntrstRate;
	/*
	 * ������ؽ��
	 */
	private String rpdAmt;
	/*
	 * ���׺�ͬ���
	 */
	private String txlCtrctNb;
	/*
	 * ��Ʊ����
	 */
	private String invcNb;
	
	//������Ϣ
	/*
	 * �ʺ�
	 */
	private String aOAccnInfId;
	/*
	 * �к�
	 */
	private String aOAccnInfacctSvcr;
	
	/*
	 * ����������
	 */
	private DscntPropsr dscntPropsr;
	/*
	 * ��������Ϣ
	 */
	private DscntBk dscntBk;
}
