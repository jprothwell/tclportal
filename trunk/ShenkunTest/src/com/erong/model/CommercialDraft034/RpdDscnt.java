package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;

/**
 * �ع�ʽ�������
 * @author IBM
 *
 */
public class RpdDscnt extends CommonTransmission034 {
	/*
	 * �������ǩ��ʱ��
	 */
	private Date dtTm;
	/*
	 * �����������
	 */
	private int/* PercentageRate*/ rate;
	/*
	 * �������ʵ�����
	 */
	private int /*CurrencyAndAmount*/ amt;
	/*
	 * ����ת�ñ��
	 */
	private String /*BanEndorsementMarkCode*/ banEndrsmtMk ;
	
	/*
	 * ���������������Ϣ��ԭ�����ˣ����
	 */
	private String /* RoleCode*/ dscntBkrole;
	/*
	 * ����
	 */
	private String dscntBknm;
	/*
	 * ��֯��������
	 */
	private String dscntBkcmonId;
	/*
	 * �˺�
	 */
	private String dscntBkacctid;
	/*
	 * �������к�
	 */
	private int dscntBkAcctSvcrid;
	/*
	 * �н����к�
	 */
	private int  dscntBkAgcyid;
	
	/*
	 * �������ǩ������Ϣ��ԭ����������) ���
	 */
	
	private String /*RoleCode*/ orgnlDscntPropsrrole;
	/*
	 * ����
	 */
	private String orgnlDscntPropsrnm;
	/*
	 * ��֯��������
	 */
	private String orgnlDscntPropsrcmonId;
	/*
	 * �˺�
	 */
	private String orgnlDscntPropsracct;
	/*
	 * �к�
	 */
	private int  orgnlDscntPropsracctSvcr;
	/*
	 * �н����к�
	 */
	private int  orgnlDscntPropsrAgcy;

}
