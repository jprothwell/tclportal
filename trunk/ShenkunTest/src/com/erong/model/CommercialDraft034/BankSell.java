package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * ����������Ʊ��Ϣ
 * @author IBM
 *
 */

public class BankSell extends  CommonTransmission034 {
	/*
	 * ��������
	 */
	private Date dt;
	/*
	 * ����
	 */
	private int /*PercentageRate*/ intrstRate;
	/*
	 * ʵ�����
	 */
	private int/*CurrencyAndAmount*/ amt;
	/*
	 * ����ת�ñ��
	 */
	private String /*BanEndorsementMarkCode*/banEndrsmtMk;
	/*
	 * ����������
	 */
	private String /*SettlementMarkCode*/sttlmMk;
	/*
	 * ��������Ϣ
	 */
	private User user;
	/*
	 * ��������Ϣ �н����к�
	 */
	private int /*MaxMin12NumericText*/ agcy;
	/*
	 * ��������Ϣ
	 */
	private User use1;
}
