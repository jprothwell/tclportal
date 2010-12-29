package com.erong.model;
//汇总信息报文
import java.util.Date;
import java.util.List;

import com.erong.model.util.CommercialDraft;
import com.erong.model.util.Ptcpt;

public class SummaryInformation071 extends CommercialDraft {
//	汇总信息
	private List<Ptcpt> Ptcpts;
}
