package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * ��������Ϣ
 * @author IBM
 *
 */

public class RdscntWthCntrlBk 	extends  CommonTransmission034{
	/*
	 * ����������
	 */
	private String /*RepurchasedMarkCode*/ rpdMk;
	/*
	 * ��������������
	 */
	private Date dt;
	
	private int /*PercentageRate*/ intrstRate;
	/*
	 * ������ʵ�����
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
	private int /*PercentageRate*/ rpdIntrstRate;
	/*
	 * ��������ؽ��
	 */
	private int/*CurrencyAndAmount*/ rpdAmt;
	/*
	 * ��������Ϣ 
	 */
	private User RequestingBankOfRediscountWithCentralBank;
	
	/*
	 * ��������Ϣ
	 */
    private User RediscountWithCentralBankSystem;
}
