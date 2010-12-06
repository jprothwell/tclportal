package com.tcl.wapStatistic.actioin;


import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
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
import com.tcl.wapStatistic.util.GetIp;
import com.tcl.wapStatistic.util.GetIps;
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
		ExecutorService executor = Executors.newFixedThreadPool(num/5);
		List<Future<List>> listFuture = new ArrayList<Future<List>>();
		for(int i=0;i<num/5;i++){
			List<Location> sublist =  listLocation.subList(i*5, (i+1)*5);
			Future<List> future =  executor.submit(new GetIps(sublist));
			listFuture.add(future);
		}
		for(Future<List> future:listFuture){
			listLocation  = future.get();
			//System.out.println();
		}
		for(Location location:listLocation){
			System.out.println("获取结果：id:"+location.getId()+",ip:"+location.getIp()+",contry:"+location.getCountry());
		}
		locationService.updateLocation(listLocation);
		request.setAttribute("attention", listLocation.size()+"更新国家");
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
}
