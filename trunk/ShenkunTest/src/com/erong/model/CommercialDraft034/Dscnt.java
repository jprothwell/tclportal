package com.erong.model.CommercialDraft034;
import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * ����
 * @author IBM
 *
 */

public class Dscnt extends CommonTransmission034 {
	/*
	 * ��������
	 */
	private String /*  RepurchasedMarkCode*/ rpdMk;
	
	/*
	 * ����ǩ��ʱ��
	 */
	private Date dtTm;
	/*
	 * ��������
	 */
	private String /* PercentageRate */ intrstRate;
	/*
	 * ����ʵ�����
	 */
	private int /*CurrencyAndAmount */ amt;
	/*
	 * ����ת�ñ��
	 */
	private String /* BanEndorsementMarkCode*/ BanEndrsmtMk;
	/*
	 * ����������
	 */
	private String /*SettlementMarkCode */ sttlmMk;
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
	private int/* PercentageRate*/ rpdIntrstRate;
	/*
	 * ������ؽ��
	 */
	private int /*CurrencyAndAmount*/ rpdAmt;
	/*
	 * ���׺�ͬ���
	 */
	private String  txlCtrctNb;
	/*
	 * ��Ʊ����
	 */
	private String invcNb;
	/*
	 * ����Э����
	 */
	private String dscntAgrmtNb;
	/*
	 * ������Ϣ �˺�
	 */
	private String aOAccnInfId;
	/*
	 * �к�
	 */
	private int aOAccnInfAcctSvcr;
	/*
	 * ������������Ϣ ���
	 */
	private String /* RoleCode*/ rscntPropsrrole;
	/*
	 * �˺�
	 */
	private String dscntPropsrId;
	/*
	 * �������к�
	 */
	private int rscntPropsrAcctSvcr;
	/*
	 * �н����к�
	 */
	private int dscntPropsrAgcy;
	/*
	 * ��������Ϣ ���
	 */
	private String /*RoleCode*/ dscntBkrole;
	/*
	 * ����
	 */
	private String dscntBknm;
	/*
	 * ��֯��������
	 */
	private String dscntBkCmonId;
	/*
	 * �˺�
	 */
	private String dscntBkid;
	/*
	 * �к�
	 */
	private int dscntBkCmonAcctSvcr;

}
