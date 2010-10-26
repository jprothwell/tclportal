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
import com.tcl.portal.form.CityForm;
import com.tcl.portal.service.CityService;
import com.tcl.portal.service.CountryService;
import com.tcl.portal.service.ProvinceService;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;
/**
 * 城市信息
 * @author kun.shen
 *
 */
public class CityAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(CityAction.class);
	
	private CityService cityService;
	
	private ProvinceService provinceService;
	
	private CountryService countryService;
	
	public void setCountryService(CountryService countryService) {
		this.countryService = countryService;
	}

	public void setProvinceService(ProvinceService provinceService) {
		this.provinceService = provinceService;
	}

	public void setCityService(CityService cityService) {
		this.cityService = cityService;
	}
	
	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String countryid = request.getParameter("countryid");
		String provinceid = request.getParameter("provinceid");
		String cityname = request.getParameter("cityname");
		if(countryid==null){
			countryid = "";
		}
		if(provinceid==null){
			provinceid = "";
		}
		if(cityname==null){
			cityname = "";
		}
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("provinceid", provinceid);
		map.put("cityname", cityname);
		
		pager.setEntryCount(cityService.findCount(map));
		pager.addParam("provinceid", provinceid);
		pager.addParam("cityname", cityname);
		List<City> list = cityService.findList(map);
		for(City city:list){
			Province province = provinceService.queryProvince(city.getProvinceid());
			Country country = null;
			if(province!=null){
				city.setProvinceName(province.getProvincename());
				country = countryService.queryCountry(province.getCountryid());
			}
			if(country!=null){
				city.setCountryId(country.getId());
				city.setCountryName(country.getName());
			}
		}
		List<Country> listCountry = countryService.findAll();
		request.setAttribute("listCountry", listCountry);
		request.setAttribute("list", list);
		request.setAttribute("countryidSelect", countryid);
		request.setAttribute("cityname",cityname);
		if(null==provinceid){
			provinceid = "";
		}
		if(!"".equals(provinceid)){
			StringBuilder sb = new StringBuilder();
			sb.append("<option value=\"");
			sb.append(provinceid);
			sb.append("\" selected");
			sb.append(">");
			sb.append(provinceService.queryProvince(Integer.parseInt(provinceid)).getProvincename());
			sb.append("</option>");
			request.setAttribute("provinceidSelect", sb.toString());
		}
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
		
		CityForm cityForm = (CityForm)form;
		City city = new City();
		BeanUtils.copyProperties(city,cityForm);
		cityService.save(city);
		logger.info("city save");
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		CityForm cityForm = (CityForm)form;
		City city = new City();
		BeanUtils.copyProperties(city,cityForm);
		cityService.update(city);
		logger.info("city update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		String countryId=request.getParameter("countryId");
		City city = cityService.queryCountry(Integer.parseInt(id));
		CityForm cityForm = new CityForm();
		BeanUtils.copyProperties(cityForm,city);
		request.setAttribute("obj",cityForm );
		List<Country> list = countryService.findAll();
		request.setAttribute("listCountry", list);
		request.setAttribute("countryId", countryId);
		
		StringBuilder sb = new StringBuilder();
		sb.append("<option value=\"");
		sb.append(city.getProvinceid());
		sb.append("\" selected");
		sb.append(">");
		sb.append(provinceService.queryProvince(city.getProvinceid()).getProvincename());
		sb.append("</option>");
		request.setAttribute("provinceidSelect", sb.toString());
		return mapping.findForward("edit");
	}
	
	public ActionForward findCityByProvince(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String provinceid = request.getParameter("provinceid");
		List<City> list = cityService.findAll();
		StringBuilder sb = new StringBuilder("<option value=>选择城市</option>");
		for(City city:list){
			if(String.valueOf(city.getProvinceid()).equals(provinceid)){
				sb.append("<option value=");
				sb.append(city.getId());
				sb.append(">");
				sb.append(city.getCityname());
				sb.append("</option>");
			}
		}
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		out.write(sb.toString());
		out.flush();
		return null;
	}
	
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
	    int flag = cityService.delete(Integer.parseInt(id));
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("city delete");
			out.write("1");
		}else{
			logger.info("city delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
}
