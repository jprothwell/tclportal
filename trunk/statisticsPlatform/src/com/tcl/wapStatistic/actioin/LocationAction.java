package com.tcl.wapStatistic.actioin;


import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.wapStatistic.domain.Location;
import com.tcl.wapStatistic.service.LocationService;
import com.tcl.wapStatistic.util.BatchGetCountry;
import com.tcl.wapStatistic.util.GetIp;
public class LocationAction  extends DispatchAction{
	
	public Logger logger = Logger.getLogger(LocationAction.class);
	
	private LocationService locationService;

	public void setLocationService(LocationService locationService) {
		this.locationService = locationService;
	}
	
	//完善ip的所在地数据
	public ActionForward atuoAddCountry(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		List<Location> listLocation = locationService.findLocationCountryIsNull();
		int num = listLocation.size();
		System.out.println("num:"+num);
		ExecutorService executor = Executors.newFixedThreadPool(num/5);
		List<Future<String>>  listFurture = new ArrayList<Future<String>>();
		for(Location location :listLocation){
			listFurture.add(executor.submit(new BatchGetCountry(location)));
		}
		List<Location> results = new ArrayList<Location>();
		for(Future<String> fs:listFurture){
			String rs = fs.get();
			if(!"".equals(rs)){
				Location location = new Location();
				location.setId(Long.parseLong(rs.split(":")[0]));
				location.setCountry(rs.split(":")[1]);
				log.info("id:"+location.getId()+",country:"+location.getCountry());
				results.add(location);
			}
		}
		locationService.updateLocation(results);
		request.setAttribute("attention", listLocation.size()+"需要更新国家，完成："+results.size());
		return mapping.findForward("atuoAddCountry");
	}
	//逐条查询插入
	public ActionForward atuoAddCountrySingle(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		List<Location> listLocation = locationService.findLocationCountryIsNull();
		for(Location location:listLocation){
			String country = GetIp.getIp(location.getIp()+".2");
			location.setCountry(country);
			locationService.updateLocationSigle(location);
			log.info("id:"+location.getId()+",ip:"+location.getIp()+",country:"+location.getCountry());
		}
		
		request.setAttribute("attention", listLocation.size()+"更新国家");
		return mapping.findForward("atuoAddCountry");
	}
	//取出存入文件中，再做入库处理
	
}
