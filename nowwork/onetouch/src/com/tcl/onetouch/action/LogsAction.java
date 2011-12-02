package com.tcl.onetouch.action;

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

import com.tcl.onetouch.domain.Logs;
import com.tcl.onetouch.domain.User;
import com.tcl.onetouch.service.LogsService;
import com.tcl.onetouch.service.UserService;
import com.tcl.onetouch.util.DateUtil;
import com.tcl.onetouch.util.Pager;
import com.tcl.onetouch.util.PagerBuilder;


public class LogsAction extends DispatchAction{
		
	public Logger logger = Logger.getLogger(LogsAction.class);
	
	private LogsService logsService;
	
	private UserService userService;
	
	public void setUserService(UserService userService) {
		this.userService = userService;
	}


	public void setLogsService(LogsService logsService) {
		this.logsService = logsService;
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
		pager.setEntryCount(logsService.findCount(map));
		pager.addParam("startDate", startDate);
		pager.addParam("endDate", endDate);
		List<Logs> list = logsService.findList(map);
		for(Logs log:list){
			User user = userService.queryUser(log.getUserid().toString());
			if(user!=null){
				log.setUserName(user.getName());
			}
		}
		request.setAttribute("startDate", startDate);
		request.setAttribute("endDate", endDate);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	
}
