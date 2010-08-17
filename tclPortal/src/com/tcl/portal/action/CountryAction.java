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

import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.User;
import com.tcl.portal.form.CountryForm;
import com.tcl.portal.form.UserForm;
import com.tcl.portal.service.CountryService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;
/**
 * 国家信息
 * @author kun.shen
 *
 */
public class CountryAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(CountryAction.class);
	
	private CountryService  countryService;
	
	public void setCountryService(CountryService countryService) {
		this.countryService = countryService;
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
		pager.setEntryCount(countryService.findCount(map));
		pager.addParam("name", name);
		List<Country> list = countryService.findList(map);
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
		
		CountryForm countryForm = (CountryForm)form;
		Country country = new Country();
		BeanUtils.copyProperties(country,countryForm);
		countryService.save(country);
		logger.info("country save");
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		CountryForm countryForm = (CountryForm)form;
		Country country = new Country();
		BeanUtils.copyProperties(country,countryForm);
		countryService.update(country);
		logger.info("country update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Country country = countryService.queryCountry(Integer.parseInt(id));
		CountryForm countryForm = new CountryForm();
		BeanUtils.copyProperties(countryForm,country);
		request.setAttribute("obj",countryForm );
		return mapping.findForward("edit");
	}
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		int flag = countryService.delete(Integer.parseInt(id));
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("country delete");
			out.write("1");
		}else{
			logger.info("country delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
}
