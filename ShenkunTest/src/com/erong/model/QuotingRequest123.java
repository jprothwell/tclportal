package com.erong.model;

import java.util.Date;
import java.util.List;

import com.erong.model.user.Brdcstee;
import com.erong.model.user.Qtr;
import com.erong.model.util.CommercialDraft;

/**
 * ת���ֱ��۷�������
 * @author SHENKUN
 *
 */
public class QuotingRequest123 extends CommercialDraft{
	
	/*
	 * ���۷�ʽ
	 */
	private String qtgTp;
	/*
	 * ҵ������
	 */
	private String bizTp;
	/*
	 * ���
	 */
	private String amt;
	/*
	 * ����
	 */
	private String intrstRate;
	/*
	 * ����
	 */
	private Date rmdrMtrty;
	/*
	 * �ж��˷�Χ
	 */
	private String accptrScp;
	/*
	 * Ʊ������
	 */
	private String drftTp;
	/*
	 * ���۷���Ϣ
	 */
	private Qtr qtr;
	/*
	 * �����ͷ�ʽ���շ���Ϣ
	 */
	private List<Brdcstee> brdcstees;
}
