package com.tcl.onetouch.action;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
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
import org.apache.struts.upload.FormFile;

import com.tcl.onetouch.domain.Ad;
import com.tcl.onetouch.domain.Mobileinfo;
import com.tcl.onetouch.domain.Spinfo;
import com.tcl.onetouch.form.AdForm;
import com.tcl.onetouch.service.AdService;
import com.tcl.onetouch.service.MobileinfoService;
import com.tcl.onetouch.service.SpinfoService;
import com.tcl.onetouch.service.SystemparameterService;
import com.tcl.onetouch.util.Constants;
import com.tcl.onetouch.util.Pager;
import com.tcl.onetouch.util.PagerBuilder;

public class AdAction extends DispatchAction{
	
	private Logger logger = Logger.getLogger(AdAction.class);
	
	private AdService adService;
	
	private SpinfoService spinfoService;
	
	private SystemparameterService systemparameterService;
	
	private MobileinfoService mobileinfoService;
	
	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}

	public void setSystemparameterService(
			SystemparameterService systemparameterService) {
		this.systemparameterService = systemparameterService;
	}

	public void setSpinfoService(SpinfoService spinfoService) {
		this.spinfoService = spinfoService;
	}

	public void setAdService(AdService adService) {
		this.adService = adService;
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
		
		pager.setEntryCount(adService.findCount(map));
		List<Ad> list = adService.findList(map);
		for(Ad as:list){
			Mobileinfo mobileinfo = mobileinfoService.queryMobileinfo(as.getDid());
			if(mobileinfo!=null){
				as.setDidName(mobileinfo.getPhonetype());
			}
			Spinfo spinfo = spinfoService.querySpinfo(as.getSpid());
			if(spinfo!=null){
				as.setSpName(spinfo.getName());
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
		
		List<Spinfo> spinfoList =  spinfoService.findAll();
		request.setAttribute("spinfoList", spinfoList);
		
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		AdForm adForm = (AdForm)form;
		Ad ad = new Ad();
		BeanUtils.copyProperties(ad,adForm);
		FormFile formFileOne = adForm.getFileOne();
		ad.setImage(formFileOne.getFileName());
		
		String dids = adForm.getDid();
		String[] strs = dids.split(",");
		for(String did:strs){
			ad.setDid(did);
			adService.save(ad);
		}
		logger.info("ad save");
		String imagePath = systemparameterService.queryByKey(Constants.AD_IMAGE_PATH);	
		File file = new File(imagePath);
		//不存在文件夹，创建
		if(!file.isDirectory()){
			file.mkdir();
		}
//		for(FormFile formFile:formFiles){
			InputStream is = formFileOne.getInputStream();
			OutputStream os = new FileOutputStream(imagePath+File.separatorChar+formFileOne.getFileName());
			 int bufferSize = 1024*4;
			 byte[] buffer = new byte[bufferSize];
			 int len = 0;
			 while((len = is.read(buffer, 0,bufferSize))!=-1){
				 os.write(buffer, 0, len);
			 }
			 os.flush();
			 os.close();
			 is.close();
			
		return mapping.findForward("save");
	}
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		AdForm adForm = (AdForm)form;
		Ad ad = new Ad();
		BeanUtils.copyProperties(ad,adForm);
	
		FormFile formFileOne = adForm.getFileOne();
		String imageName = formFileOne.getFileName();
		if(!"".equals(imageName)){
			ad.setImage(formFileOne.getFileName());
			String imagePath = systemparameterService.queryByKey(Constants.AD_IMAGE_PATH);	
			File file = new File(imagePath);
			//不存在文件夹，创建
			if(!file.isDirectory()){
				file.mkdir();
			}
//			for(FormFile formFile:formFiles){
				InputStream is = formFileOne.getInputStream();
				OutputStream os = new FileOutputStream(imagePath+File.separatorChar+formFileOne.getFileName());
				 int bufferSize = 1024*4;
				 byte[] buffer = new byte[bufferSize];
				 int len = 0;
				 while((len = is.read(buffer, 0,bufferSize))!=-1){
					 os.write(buffer, 0, len);
				 }
				 os.flush();
				 os.close();
				 is.close();
		}
		adService.update(ad);
		logger.info("ad update");
		
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Ad ad = adService.queryAd(Integer.parseInt(id));
		AdForm adForm = new AdForm();
		BeanUtils.copyProperties(adForm,ad);
		request.setAttribute("obj",adForm );
		
		List<Spinfo> spinfoList =  spinfoService.findAll();
		request.setAttribute("spinfoList", spinfoList);
		return mapping.findForward("edit");
	}

}
