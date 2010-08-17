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
import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.Javaparameter;
import com.tcl.portal.form.CityForm;
import com.tcl.portal.form.JavaparameterForm;
import com.tcl.portal.service.JavaparameterService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class JavaparameterAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(JavaparameterAction.class);
	
	private JavaparameterService javaparameterService;

	public void setJavaparameterService(JavaparameterService javaparameterService) {
		this.javaparameterService = javaparameterService;
	}
	
	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		pager.setEntryCount(javaparameterService.findCount(map));
		List<Javaparameter> list = javaparameterService.findList(map);
		
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
		
		JavaparameterForm javaparameterForm = (JavaparameterForm)form;
		Javaparameter javaparameter = new Javaparameter();
		BeanUtils.copyProperties(javaparameter,javaparameterForm);
		javaparameterService.save(javaparameter);
		logger.info("javaparameter save");
		return mapping.findForward("save");
	}
	
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		JavaparameterForm javaparameterForm = (JavaparameterForm)form;
		Javaparameter javaparameter = new Javaparameter();
		BeanUtils.copyProperties(javaparameter,javaparameterForm);
		javaparameterService.update(javaparameter);
		logger.info("javaparameter update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Javaparameter javaparameter = javaparameterService.queryJavaparameter(Integer.parseInt(id));
		JavaparameterForm javaparameterForm = new JavaparameterForm();
		BeanUtils.copyProperties(javaparameterForm,javaparameter);
		request.setAttribute("obj",javaparameterForm );
		return mapping.findForward("edit");
	}
}
