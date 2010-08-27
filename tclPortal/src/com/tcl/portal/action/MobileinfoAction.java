package com.tcl.portal.action;

import java.util.Date;
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
import com.tcl.portal.domain.Mobileinfo;
import com.tcl.portal.domain.Pageinfo;
import com.tcl.portal.form.MobileinfoForm;
import com.tcl.portal.service.JavaparameterService;
import com.tcl.portal.service.MobileinfoService;
import com.tcl.portal.service.PageinfoService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class MobileinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(MobileinfoAction.class);
	
	private MobileinfoService mobileinfoService;
	
	private PageinfoService pageinfoService;
	
	private JavaparameterService javaparameterService;
	
	public void setJavaparameterService(JavaparameterService javaparameterService) {
		this.javaparameterService = javaparameterService;
	}

	public void setPageinfoService(PageinfoService pageinfoService) {
		this.pageinfoService = pageinfoService;
	}

	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}


	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String did = request.getParameter("did");
		String phonetype = request.getParameter("phonetype");
		
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("did", did);
		map.put("phonetype", phonetype);
		pager.setEntryCount(mobileinfoService.findCount(map));
		List<Mobileinfo> list = mobileinfoService.findList(map);
		
		for(Mobileinfo mobileinfo:list){
			Pageinfo pageinfo = pageinfoService.queryPageinfo(mobileinfo.getPageid());
			if(pageinfo!=null){
				mobileinfo.setPageName(pageinfo.getPagename());
			}
		}
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	//增加页面以及初始化数据
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		Date date = new Date();
		request.setAttribute("date", date);
		
		List<Pageinfo> list = pageinfoService.findAll();
		request.setAttribute("pageinfoList", list);
		
		List<Javaparameter> javaparameters = javaparameterService.findAll();
		request.setAttribute("javaparameters", javaparameters);
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		MobileinfoForm mobileinfoForm = (MobileinfoForm)form;
		Mobileinfo mobileinfo = new Mobileinfo();
		BeanUtils.copyProperties(mobileinfo,mobileinfoForm);
		mobileinfoService.save(mobileinfo);
		logger.info("mobileinfo save");
		return mapping.findForward("save");
	}
	
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		MobileinfoForm mobileinfoForm = (MobileinfoForm)form;
		Mobileinfo mobileinfo = new Mobileinfo();
		BeanUtils.copyProperties(mobileinfo,mobileinfoForm);
		mobileinfoService.update(mobileinfo);
		logger.info("mobileinfo update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Mobileinfo mobileinfo = mobileinfoService.queryMobileinfo(id);
		MobileinfoForm mobileinfoForm = new MobileinfoForm();
		BeanUtils.copyProperties(mobileinfoForm,mobileinfo);
		request.setAttribute("obj",mobileinfoForm );
		
		List<Pageinfo> list = pageinfoService.findAll();
		request.setAttribute("pageinfoList", list);
		
		List<Javaparameter> javaparameters = javaparameterService.findAll();
		request.setAttribute("javaparameters", javaparameters);
		
		return mapping.findForward("edit");
	}
	//列出选中列表
	public ActionForward findListChoice(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		pager.setEntryCount(mobileinfoService.findCount(map));
		List<Mobileinfo> list = mobileinfoService.findList(map);
		request.setAttribute("list", list);
		return mapping.findForward("listChoice");
	}
	//查找did
	public ActionForward queryDid(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
//		String did = request.getParameter("id");
//		Mobileinfo mobileinfo = mobileinfoService.queryMobileinfo(did);
//		response.setCharacterEncoding("UTF-8");
//		response.setContentType("text/html"); 
//		PrintWriter out = response.getWriter();
//		out.write(mobileinfo.getDid());
//		out.flush();
		return null;
	}
}
