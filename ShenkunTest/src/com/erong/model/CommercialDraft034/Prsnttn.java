package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * ��ʾ������Ϣ
 * @author IBM
 *
 */

public class Prsnttn extends  CommonTransmission034{
	/*
	 * ��ʾ������������
	 */
	private Date applDt;
	/*
	 * ��ʾ����ǩ��ʱ��
	 */
	private Date dtTm;
	/*
	 * ��ʾ������
	 */
	private int/*CurrencyAndAmount*/ amt;
	/*
	 * ����������
	 */
	private String /*SettlementMarkCode*/ sttlmMkString;
	/*
	 * �ܸ�����
	 */
	private String /*DishonorCode*/ dshnrCd;
	/*
	 * �ܸ���ע��Ϣ
	 */
	private String dshnrRsn;
	
	/*
	 * ��ʾ��������Ϣ
	 */
	private User drftHldr;
	/*
	 * ��������Ϣ
	 */
	private User payBk;
	/*
	 * ��������Ϣ �н����к�
	 */
	private int /*MaxMin12NumericText*/ Agcy;
	

}
