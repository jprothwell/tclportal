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

import com.tcl.portal.domain.Javaparameter;
import com.tcl.portal.domain.Systemparameter;
import com.tcl.portal.form.JavaparameterForm;
import com.tcl.portal.form.SystemparameterForm;
import com.tcl.portal.service.SystemparameterService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class SystemparameterAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(SystemparameterAction.class);
	
	private SystemparameterService systemparameterService;

	public void setSystemparameterService(
			SystemparameterService systemparameterService) {
		this.systemparameterService = systemparameterService;
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
		pager.setEntryCount(systemparameterService.findCount(map));
		pager.addParam("name", name);
		List<Systemparameter> list = systemparameterService.findList(map);
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
		
		SystemparameterForm systemparameterForm = (SystemparameterForm)form;
		Systemparameter systemparameter = new Systemparameter();
		BeanUtils.copyProperties(systemparameter,systemparameterForm);
		systemparameterService.save(systemparameter);
		logger.info("systemparameter save");
		return mapping.findForward("save");
	}
	
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		SystemparameterForm systemparameterForm = (SystemparameterForm)form;
		Systemparameter systemparameter = new Systemparameter();
		BeanUtils.copyProperties(systemparameter,systemparameterForm);
		systemparameterService.update(systemparameter);
		logger.info("systemparameter update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Systemparameter systemparameter = systemparameterService.querySystemparameter(Integer.parseInt(id));
		SystemparameterForm systemparameterForm = new SystemparameterForm();
		BeanUtils.copyProperties(systemparameterForm,systemparameter);
		request.setAttribute("obj",systemparameterForm);
		return mapping.findForward("edit");
	}
}
