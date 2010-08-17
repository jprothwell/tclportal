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

import com.tcl.portal.domain.Mobileinfo;
import com.tcl.portal.domain.Pageinfo;
import com.tcl.portal.form.MobileinfoForm;
import com.tcl.portal.form.PageinfoForm;
import com.tcl.portal.service.PageinfoService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class PageinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(PageinfoAction.class);
	
	private PageinfoService  pageinfoService;
	
	public void setPageinfoService(PageinfoService pageinfoService) {
		this.pageinfoService = pageinfoService;
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
		pager.setEntryCount(pageinfoService.findCount(map));
		List<Pageinfo> list = pageinfoService.findList(map);
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
		
		PageinfoForm pageinfoForm = (PageinfoForm)form;
		Pageinfo pageinfo = new Pageinfo();
		BeanUtils.copyProperties(pageinfo,pageinfoForm);
		pageinfoService.save(pageinfo);
		logger.info("pageinfo save");
		return mapping.findForward("save");
	}
	
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		PageinfoForm pageinfoForm = (PageinfoForm)form;
		Pageinfo pageinfo = new Pageinfo();
		BeanUtils.copyProperties(pageinfo,pageinfoForm);
		pageinfoService.update(pageinfo);
		logger.info("pageinfo update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Pageinfo pageinfo = pageinfoService.queryPageinfo(Integer.parseInt(id));
		PageinfoForm pageinfoForm = new PageinfoForm();
		BeanUtils.copyProperties(pageinfoForm,pageinfo);
		request.setAttribute("obj",pageinfoForm );
		return mapping.findForward("edit");
	}
}
