package com.erong.model.CommercialDraft034;

import java.util.Date;

import com.erong.model.CommonTransmission034;
import com.erong.model.user.User;
/**
 * ������ʾ������Ϣ
 * @author IBM
 *
 */

public class OvrduePrsnttn extends  CommonTransmission034{
	/*
	 * ������ʾ������������
	 */
	private Date applDt;
	/*
	 * ������ʾ����ǩ��ʱ��
	 */
	private Date dtTmDate;
	/*
	 * ������ʾ������
	 */
	private int /*CurrencyAndAmount*/ amt;
	/*
	 * ����ԭ��˵��
	 */
	private String /*Max256Text*/ rsn;
	/*
	 * ����������
	 */
	private String /*SettlementMarkCode*/sttlmMkString;
	/*
	 * �ܸ�����
	 */
	private String /*DishonorCode*/ dshnrCd;
	/*
	 * �ܸ���ע��Ϣ
	 */
	private String /*Max256Text*/ dshnrRsn;
	/*
	 * ������ʾ��������Ϣ
	 */
	
	private User drftHldr;
	/*
	 * ������ʾ��������Ϣ �н����к�
	 */
	
	private int/*MaxMin12NumericText*/ drftHldrAgcy;
	/*
	 * ��������Ϣ
	 */
	
	private User payBk;
	
	/*
	 * ��������Ϣ �н����к�
	 */
	private int /*MaxMin12NumericText*/ payBkAgcy;
}
