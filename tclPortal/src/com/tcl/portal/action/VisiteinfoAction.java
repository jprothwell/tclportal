package com.tcl.portal.action;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.portal.domain.Gameinfo;
import com.tcl.portal.domain.Mobileinfo;
import com.tcl.portal.domain.Visiteinfo;
import com.tcl.portal.service.GameinfoService;
import com.tcl.portal.service.MobileinfoService;
import com.tcl.portal.service.VisiteinfoService;
import com.tcl.portal.util.DateUtil;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;


public class VisiteinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(VisiteinfoAction.class);
	
	private VisiteinfoService  visiteinfoService;
	
	private MobileinfoService mobileinfoService;
	
	private GameinfoService gameinfoService;
	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}

	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}

	public void setVisiteinfoService(VisiteinfoService visiteinfoService) {
		this.visiteinfoService = visiteinfoService;
	}


	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String startDate=request.getParameter("startDate");
		String endDate=request.getParameter("endDate");
		if (("").equals(startDate)||startDate==null)
		{
			startDate = DateUtil.getTheMonthFirstDay();
		}
		if (("").equals(endDate)||endDate==null)
		{
			endDate = DateUtil.getCurrentDate();
		}
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		Date startD = null;
		Date endD = null;
		try {
			startD =  new SimpleDateFormat("yyyy-MM-dd").parse(startDate);
			endD = DateUtil.getTomorrow(endDate);
			
		} catch (ParseException e) {
			e.printStackTrace();
		}
		if(!"".equals(startDate)&&startDate!=null){
			map.put("startDate",startD);
		}
		if(!"".equals(endDate)&&endDate!=null){
			map.put("endDate",endD);
		}
		pager.setEntryCount(visiteinfoService.findCount(map));
		pager.addParam("startDate", startDate);
		pager.addParam("endDate", endDate);
		List<Visiteinfo> list = visiteinfoService.findList(map);
		for(Visiteinfo visiteinfo:list){
			Mobileinfo mobileinfo = mobileinfoService.queryMobileinfo(visiteinfo.getDid());
			if(mobileinfo!=null){
				visiteinfo.setDidName(mobileinfo.getPhonetype());
			}
			Gameinfo gameinfo = gameinfoService.queryGameinfo(visiteinfo.getGameid());
			if(gameinfo!=null){
				visiteinfo.setGameName(gameinfo.getGamename());
			}
		}
		request.setAttribute("startDate", startDate);
		request.setAttribute("endDate", endDate);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
}
