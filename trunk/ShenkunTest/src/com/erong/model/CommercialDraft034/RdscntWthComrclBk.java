package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * ת����
 * @author IBM
 *
 */

public class RdscntWthComrclBk extends CommonTransmission034{
	/*
	 * ת��������
	 */
	private String /*RepurchasedMarkCode*/ rpdMk;
	/*
	 * ת����ǩ��ʱ��
	 */
	private Date dtTm;
	/*
	 * ת��������
	 */
	private int /*PercentageRate*/ rate;
	/*
	 * ת����ʵ�����
	 */
	private int /*CurrencyAndAmount*/amt;
	/*
	 * ����ת�ñ��
	 */
	private String /*BanEndorsementMarkCode*/ banEndrsmtMk;
	/*
	 * ����������
	 */
	
	private String /*SettlementMarkCode*/ sttlmMk;
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
	private int/*PercentageRate*/ RpdIntrstRate;
	/*
	 * ת������ؽ��
	 */
	private int /*CurrencyAndAmount*/ rpdAmt;
	/*
	 * ��������Ϣ  ���
	 */
	private String /*RoleCode*/ rqstngBkOfRdscntWthComrclBkrole;
	/*
	 * ����
	 */
	private String rqstngBkOfRdscntWthComrclBknm;
	/*
	 * ��֯��������
	 */
	private String rqstngBkOfRdscntWthComrclBkcmonId;
	/*
	 * �˺�
	 */
	private String rqstngBkOfRdscntWthComrclBkAcctId;
	/*
	 * �к�
	 */
	private String  rqstngBkOfRdscntWthComrclBkAcctSvcr;
	/*
	 * �н����к�
	 */
	private int rqstngBkOfRdscntWthComrclBkAgcy;
	/*
	 * ��������Ϣ ���
	 */
	private String /*RoleCode*/ rcvgBkOfRdscntWthComrclBkRole;
	/*
	 * ����
	 */
	private String rcvgBkOfRdscntWthComrclBkRNM;
	/*
	 * ��֯��������
	 */
	private String rcvgBkOfRdscntWthComrclBkRCmonId;
	/*
	 * �˺�
	 */
	private String rcvgBkOfRdscntWthComrclBkAcctid;
	/*
	 * �к�
	 */
	private int rcvgBkOfRdscntWthComrclBkAcctSvcr;
}
