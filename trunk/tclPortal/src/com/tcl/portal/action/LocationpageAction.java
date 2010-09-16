package com.tcl.portal.action;

import java.io.PrintWriter;
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

import com.tcl.portal.domain.Language;
import com.tcl.portal.domain.Locationpage;
import com.tcl.portal.form.LanguageForm;
import com.tcl.portal.form.LocationpageForm;
import com.tcl.portal.service.LocationpageService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class LocationpageAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(LocationpageAction.class);
	
	private LocationpageService locationpageService;
	
	public void setLocationpageService(LocationpageService locationpageService) {
		this.locationpageService = locationpageService;
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
		pager.setEntryCount(locationpageService.findCount(map));
		pager.addParam("name", name);
		List<Locationpage> list = locationpageService.findList(map);
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	
	//增加页面以及初始化数据
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		LocationpageForm locationpageForm = (LocationpageForm)form;
		Locationpage locationpage = new Locationpage();
		BeanUtils.copyProperties(locationpage,locationpageForm);
		locationpageService.save(locationpage);
		logger.info("locationpage save");
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		LocationpageForm locationpageForm = (LocationpageForm)form;
		Locationpage locationpage = new Locationpage();
		BeanUtils.copyProperties(locationpage,locationpageForm);
		locationpageService.update(locationpage);
		logger.info("locationpage update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Locationpage locationpage = locationpageService.queryLocationpage(Integer.parseInt(id));
		LocationpageForm locationpageForm  = new LocationpageForm();
		BeanUtils.copyProperties(locationpageForm,locationpage);
		request.setAttribute("obj",locationpageForm);
		return mapping.findForward("edit");
	}
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
	    int flag = locationpageService.delete(Integer.parseInt(id));
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("spinfo delete");
			out.write("1");
		}else{
			logger.info("spinfo delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
}
