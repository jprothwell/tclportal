package com.erong.model;

import java.util.List;

import com.erong.model.util.CommercialDraft;
import com.erong.model.util.Dtls;
/**
 * ֽƱ�Ǽ���Ϣ�鸴����
 * @author SHENKUN
 *
 */
public class RegisterInformationResponse122 extends CommercialDraft{
	/*
	 * ԭ���ı�ʶ  �����
	 */
	
	/*
	 * �ж���Ϣ�Ƿ�Ϊ����Ǽ���Ϣ
	 */
	private String splmtryReg;
	/*
	 * ��ʷ��ѯ��Ϣ ����
	 */
	private int quriesCnt;
	/*
	 * ��ʷ��ѯ��Ϣ ��ϸ
	 */
	private List<Dtls> dtls;
	
}
