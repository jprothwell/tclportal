package com.erong.model;
//每月票据信息明细申请报文
import java.util.Date;
import java.util.List;

import com.erong.model.util.CommercialDraft;
import com.erong.model.util.ForComrclDrft;

public class MonthlyDetailsRequest078 extends CommercialDraft {


//	  行号
	private String AcctSvcr;
//	申请的票据信息
	private List<ForComrclDrft> forComrclDrfts;
	
}
