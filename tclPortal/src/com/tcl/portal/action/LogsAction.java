package com.tcl.portal.action;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.portal.domain.City;
import com.tcl.portal.domain.Logs;
import com.tcl.portal.service.LogsService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class LogsAction extends DispatchAction{
		
	public Logger logger = Logger.getLogger(LogsAction.class);
	
	private LogsService logsService;
	
	public void setLogsService(LogsService logsService) {
		this.logsService = logsService;
	}


	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String name = request.getParameter("name");
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("name", name);
		pager.setEntryCount(logsService.findCount(map));
		pager.addParam("name", name);
		List<Logs> list = logsService.findList(map);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	
}
