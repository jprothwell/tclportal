package com.erong.model;

import java.util.Date;

import com.erong.model.user.Endrsee;
import com.erong.model.user.Endrsr;
import com.erong.model.util.CommercialDraft;
/**
 * ����ת�����뱨��
 * @author SHENKUN
 *
 */
public class DraftEndorsementRequest010 extends CommercialDraft{
	
//	/*
//	 * ���ı�ʾ��Ϣ
//	 */
//	private String id;
//	
//	/*
//	 * ����ʱ��
//	 */
//	private Date creDtTm;
//	 
//	/*
//	 * ����Ʊ�ݺ���
//	 */
//	private String idNb;
//	
//	/*
//	 * Ʊ�ݽ��
//	 */
//	private String isseAmt;
	
	/*
	 * ������������
	 */
	private Date dt;
	
	/*
	 * ����ת�ñ��
	 */
	private String banEndrsmtMk;
	
	/*
	 * ��������Ϣ
	 */
	private Endrsr endrsr;
	
	/*
	 * ����������Ϣ
	 */
	private Endrsee endrsee;
}
