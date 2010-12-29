package com.erong.model;
//每月票据信息汇总回复报文
import java.util.Date;
import java.util.List;

import com.erong.model.util.Accptd;
import com.erong.model.util.CommercialDraft;
import com.erong.model.util.Hldg;

public class MonthlySummaryInformation077 extends CommercialDraft {
//	行号
	private String AcctSvcr;
//	做为承兑人的存量票据明细
	private List<Accptd> accptds;
//	做为持票人的存量票据明细
	private List<Hldg> hldgs;
}
