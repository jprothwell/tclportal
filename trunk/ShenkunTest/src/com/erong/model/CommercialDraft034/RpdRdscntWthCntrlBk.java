package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * �����������Ϣ
 * @author IBM
 *
 */

public class RpdRdscntWthCntrlBk extends  CommonTransmission034{
	
	/*
	 * ���������ǩ��ʱ��
	 */
	private Date dtTm;
	/*
	 * �������������
	 */
	private int /*PercentageRate*/ rate;
	/*
	 * ���������ʵ�����
	 */
	private int /*CurrencyAndAmount*/ amt;
	/*
	 * ����ת�ñ��
	 */
	private String /*BanEndorsementMarkCode*/banEndrsmtMk;
	/*
	 * ����������
	 */
	private String /*SettlementMarkCode*/ sttlmMk;
	/*
	 * �����������������Ϣ
	 */
	private User user;
	/*
	 * �н����к�
	 */
	private int orgnlRqstngBkOfRdscntWthCntrlBkAgcy;
	/*
	 * ���������ǩ������Ϣ
	 */
	private User user1;
	/*
	 * �н����к�
	 */

	private int rdscntWthCntrlBkSysAcctSvcr;
}
