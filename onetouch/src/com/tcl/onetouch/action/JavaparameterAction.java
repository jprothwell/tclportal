package com.tcl.onetouch.action;

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

import com.tcl.onetouch.domain.Javaparameter;
import com.tcl.onetouch.form.JavaparameterForm;
import com.tcl.onetouch.service.JavaparameterService;
import com.tcl.onetouch.util.Pager;
import com.tcl.onetouch.util.PagerBuilder;


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
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
	    int flag = javaparameterService.delete(Integer.parseInt(id));
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("language delete");
			out.write("1");
		}else{
			logger.info("language delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
}
