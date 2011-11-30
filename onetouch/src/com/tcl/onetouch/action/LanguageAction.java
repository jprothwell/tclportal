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

import com.tcl.onetouch.domain.Language;
import com.tcl.onetouch.form.LanguageForm;
import com.tcl.onetouch.service.LanguageService;
import com.tcl.onetouch.util.Pager;
import com.tcl.onetouch.util.PagerBuilder;


public class LanguageAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(LanguageAction.class);
	
	private LanguageService languageService;
	
	public void setLanguageService(LanguageService languageService) {
		this.languageService = languageService;
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
		pager.setEntryCount(languageService.findCount(map));
		pager.addParam("name", name);
		List<Language> list = languageService.findList(map);
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
		
		LanguageForm languageForm = (LanguageForm)form;
		Language language = new Language();
		BeanUtils.copyProperties(language,languageForm);
		languageService.save(language);
		logger.info("language save");
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		LanguageForm languageForm = (LanguageForm)form;
		Language language = new Language();
		BeanUtils.copyProperties(language,languageForm);
		languageService.update(language);
		logger.info("language update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Language language = languageService.queryLanguage(Integer.parseInt(id));
		LanguageForm languageForm  = new LanguageForm();
		BeanUtils.copyProperties(languageForm,language);
		request.setAttribute("obj",languageForm);
		return mapping.findForward("edit");
	}
	
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
	    int flag = languageService.delete(Integer.parseInt(id));
		
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