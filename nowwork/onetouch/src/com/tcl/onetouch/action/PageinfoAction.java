package com.tcl.onetouch.action;

import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
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
import org.apache.struts.upload.FormFile;

import com.tcl.onetouch.domain.Language;
import com.tcl.onetouch.domain.Pageinfo;
import com.tcl.onetouch.form.PageinfoForm;
import com.tcl.onetouch.service.LanguageService;
import com.tcl.onetouch.service.PageinfoService;
import com.tcl.onetouch.util.Pager;
import com.tcl.onetouch.util.PagerBuilder;


public class PageinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(PageinfoAction.class);
	
	private PageinfoService  pageinfoService;
	
	private LanguageService languageService;
	
	public void setPageinfoService(PageinfoService pageinfoService) {
		this.pageinfoService = pageinfoService;
	}

	public void setLanguageService(LanguageService languageService) {
		this.languageService = languageService;
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
		for(Pageinfo pageinfo:list){
			pageinfo.setLanguageName(languageService.queryLanguageName(pageinfo.getLanguageid()));
		}
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	//增加页面以及初始化数据
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		List<Language> list = languageService.findAll();
		request.setAttribute("languageList", list);
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String pagetype = request.getParameter("pagetype");
		//filepath = request.getset
		String filePath = "d:/pathTest";
		if(pagetype.equals("1")){
			filePath = "d:/pathTest";
		}else if(pagetype.equals("2")){
			filePath = "d:/pathTest";
		}else if(pagetype.equals("3")){
			filePath = "d:/pathTest";
		}
		PageinfoForm pageinfoForm = (PageinfoForm)form;
		Pageinfo pageinfo = new Pageinfo();
		BeanUtils.copyProperties(pageinfo,pageinfoForm);
		FormFile fileOne = pageinfoForm.getFileOne();
		String filePathName = filePath+"/"+fileOne.getFileName();
		pageinfo.setFilename(filePathName);
		
		InputStream is = fileOne.getInputStream();
		OutputStream os = new FileOutputStream(filePathName);
		 int bufferSize = 1024*4;
		 byte[] buffer = new byte[bufferSize];
		 int len = 0;
		 while((len = is.read(buffer, 0,bufferSize))!=-1){
			 os.write(buffer, 0, len);
		 }
		 os.flush();
		 os.close();
		 is.close();
		 
		pageinfoService.save(pageinfo);
		logger.info("pageinfo save");
		return mapping.findForward("save");
	}
	
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String pagetype = request.getParameter("pagetype");
		String filePath = "d:/pathTest";
		if(pagetype.equals("1")){
			filePath = "d:/pathTest";
		}else if(pagetype.equals("2")){
			filePath = "d:/pathTest";
		}else if(pagetype.equals("3")){
			filePath = "d:/pathTest";
		}
		PageinfoForm pageinfoForm = (PageinfoForm)form;
		Pageinfo pageinfo = new Pageinfo();
		BeanUtils.copyProperties(pageinfo,pageinfoForm);
		FormFile fileOne = pageinfoForm.getFileOne();
		
		String fileName = fileOne.getFileName().trim();
		if(!fileName.equals("")){
			pageinfo.setFilename(fileName);
			String filePathName = filePath+"/"+fileName;
			InputStream is = fileOne.getInputStream();
			OutputStream os = new FileOutputStream(filePathName);
			 int bufferSize = 1024*4;
			 byte[] buffer = new byte[bufferSize];
			 int len = 0;
			 while((len = is.read(buffer, 0,bufferSize))!=-1){
				 os.write(buffer, 0, len);
			 }
			 os.flush();
			 os.close();
			 is.close();
		}else{
			Pageinfo pi = pageinfoService.queryPageinfo(pageinfo.getId());
			pageinfo.setFilename(pi.getFilename());
		}
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
		
		List<Language> list = languageService.findAll();
		request.setAttribute("languageList", list);
		return mapping.findForward("edit");
	}
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
	    int flag = pageinfoService.delete(Integer.parseInt(id));
		
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
