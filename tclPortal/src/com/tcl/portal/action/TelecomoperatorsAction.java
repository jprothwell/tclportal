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

import com.tcl.portal.domain.City;
import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.Province;
import com.tcl.portal.domain.Telecomoperators;
import com.tcl.portal.form.CityForm;
import com.tcl.portal.form.TelecomoperatorsForm;
import com.tcl.portal.service.CountryService;
import com.tcl.portal.service.TelecomoperatorsService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class TelecomoperatorsAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(TelecomoperatorsAction.class);
	
	private TelecomoperatorsService telecomoperatorsService;
	
	private CountryService countryService;
	
	public void setCountryService(CountryService countryService) {
		this.countryService = countryService;
	}

	public void setTelecomoperatorsService(
			TelecomoperatorsService telecomoperatorsService) {
		this.telecomoperatorsService = telecomoperatorsService;
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
		
		pager.setEntryCount(telecomoperatorsService.findCount(map));
		List<Telecomoperators> list = telecomoperatorsService.findList(map);
		for(Telecomoperators telecomoperators:list){
			Country country = countryService.queryCountry(telecomoperators.getCountryid());
			if(country!=null){
				telecomoperators.setCountryName(country.getName());
			}
		}
		request.setAttribute("list", list);
		List<Country> listCountry = countryService.findAll();
		request.setAttribute("listCountry", listCountry);
		return mapping.findForward("list");
	}
	
	//增加页面以及初始化数据
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		List<Country> list = countryService.findAll();
		request.setAttribute("listCountry", list);
		return mapping.findForward("add");
	}
	
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		TelecomoperatorsForm telecomoperatorsForm = (TelecomoperatorsForm)form;
		Telecomoperators telecom = new Telecomoperators();
		BeanUtils.copyProperties(telecom,telecomoperatorsForm);
		telecomoperatorsService.save(telecom);
		logger.info("Telecomoperators save");
		return mapping.findForward("save");
	}
	
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		TelecomoperatorsForm telecomoperatorsForm = (TelecomoperatorsForm)form;
		Telecomoperators telecom = new Telecomoperators();
		BeanUtils.copyProperties(telecom,telecomoperatorsForm);
		telecomoperatorsService.update(telecom);
		logger.info("Telecomoperators update");
		return mapping.findForward("update");
	}
	
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Telecomoperators telecomoperators = telecomoperatorsService.queryTelecomoperators(Integer.parseInt(id));
		TelecomoperatorsForm telecomoperatorsForm = new TelecomoperatorsForm();
		BeanUtils.copyProperties(telecomoperatorsForm,telecomoperators);
		request.setAttribute("obj",telecomoperatorsForm );
		List<Country> list = countryService.findAll();
		request.setAttribute("listCountry", list);
		return mapping.findForward("edit");
	}
	
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
	    int flag = telecomoperatorsService.delete(Integer.parseInt(id));
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("telecompoperator delete");
			out.write("1");
		}else{
			logger.info("telecompoperator delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
}
