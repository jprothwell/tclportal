package com.erong.model;

import java.util.Date;

import com.erong.model.user.Accptr;
import com.erong.model.user.DscntBk;
import com.erong.model.user.DscntPropsr;
import com.erong.model.util.CommercialDraft;

/**
 * ֽƱ���ֵǼǱ���
 * @author SHENKUN
 *
 */
public class DiscountRegister102 extends CommercialDraft{
	
	/*
	 * ��������
	 */
	private Date dt;
	
	/*
	 * �ж�����Ϣ
	 */
	private Accptr accptr;
	/*
	 * ��������Ϣ
	 */
	private DscntPropsr dscntPropsr;
	/*
	 * ��������Ϣ
	 */
	private DscntBk dscntBk;
	/*
	 * ��ע
	 */
	private String rmrk;
}
