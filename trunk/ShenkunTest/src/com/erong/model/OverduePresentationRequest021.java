package com.erong.model;

import java.util.Date;

import com.erong.model.user.DrftHldr;
import com.erong.model.util.CommercialDraft;
/**
 * ������ʾ�������뱨��
 * @author SHENKUN
 *
 */
public class OverduePresentationRequest021 extends CommercialDraft{

//	/*
//	 * ���ı�ʶ
//	 */
//	private MsgId msgId;
//	/*
//	 * Ʊ����Ϣ
//	 */
//	private ComrclDrft comrclDrft;
	/*
	 * ������ʾ������������
	 */
	private Date applDt;
	/*
	 * ������ʾ������
	 */
	private String amt;
	/*
	 * ����ԭ��˵��
	 */
	private String rsn;
	/*
	 * ����������
	 */
	private String sttlmMk;
	/*
	 * ������ʾ��������Ϣ
	 */
	private DrftHldr drftHldr;
}
