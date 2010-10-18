package com.tcl.portal.action;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
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

import com.tcl.portal.domain.Changelog;
import com.tcl.portal.domain.Country;
import com.tcl.portal.domain.Gameinfo;
import com.tcl.portal.domain.Gameresouce;
import com.tcl.portal.domain.Locationpage;
import com.tcl.portal.domain.Mobileinfo;
import com.tcl.portal.domain.Province;
import com.tcl.portal.domain.Types;
import com.tcl.portal.form.GameresouceForm;
import com.tcl.portal.service.ChangelogService;
import com.tcl.portal.service.CountryService;
import com.tcl.portal.service.GameinfoService;
import com.tcl.portal.service.GameresouceService;
import com.tcl.portal.service.LocationpageService;
import com.tcl.portal.service.MobileinfoService;
import com.tcl.portal.service.ProvinceService;
import com.tcl.portal.service.SystemparameterService;
import com.tcl.portal.service.TypesService;
import com.tcl.portal.util.Constants;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class GameresouceAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(GameresouceAction.class);
	
	private GameresouceService gameresouceService;
	
	private GameinfoService gameinfoService;
	
	private ProvinceService provinceService;
	
	private CountryService countryService;
	
	private ChangelogService  changelogService;
	
	private SystemparameterService systemparameterService;
	
	private MobileinfoService mobileinfoService;
	
	private TypesService typesService;
	
	private LocationpageService locationpageService;
	
	public void setLocationpageService(LocationpageService locationpageService) {
		this.locationpageService = locationpageService;
	}

	public void setTypesService(TypesService typesService) {
		this.typesService = typesService;
	}
	
	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}

	public void setChangelogService(ChangelogService changelogService) {
		this.changelogService = changelogService;
	}

	public void setCountryService(CountryService countryService) {
		this.countryService = countryService;
	}
	
	public void setProvinceService(ProvinceService provinceService) {
		this.provinceService = provinceService;
	}

	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}

	public void setGameresouceService(GameresouceService gameresouceService) {
		this.gameresouceService = gameresouceService;
	}

	public void setSystemparameterService(
			SystemparameterService systemparameterService) {
		this.systemparameterService = systemparameterService;
	}

	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String countryid = request.getParameter("countryid");
		String provinceid = request.getParameter("provinceid");
		String gamename = request.getParameter("gamename");
		String did = request.getParameter("did");
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("provinceid", provinceid);
		map.put("gamename", gamename);
		map.put("did", did);
		
		pager.setEntryCount(gameresouceService.findCount(map));
		List<Gameresouce> list = gameresouceService.findList(map);
		for(Gameresouce gameresouce:list){
			Gameinfo gameinfo = gameinfoService.queryGameinfo(gameresouce.getGameid());
			if(gameinfo!=null){
				gameresouce.setGameName(gameinfo.getGamename());
			}
			Province province = provinceService.queryProvince(gameresouce.getProvinceid());
			if(province!=null){
				gameresouce.setProvinceName(province.getProvincename());
			}
			Mobileinfo mobileinfo = mobileinfoService.queryMobileinfo(gameresouce.getDid());
			if(mobileinfo!=null){
				gameresouce.setDidName(mobileinfo.getPhonetype());
			}
			Locationpage locationpage = locationpageService.queryLocationpage(gameresouce.getTypeid());
			if(locationpage!=null){
				gameresouce.setTypeName(locationpage.getLocalname());
			}
//			Types types = typesService.queryTypes(gameresouce.getTypeid());
//			if(types!=null){
//				gameresouce.setTypeName(types.getTypevalue());
//			}
		}
		request.setAttribute("list", list);
		
		List<Country> listCountry = countryService.findAll();
		request.setAttribute("listCountry", listCountry);
		request.setAttribute("countryidSelect", countryid);
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
		Date date = new Date();
		request.setAttribute("date", date);
		List<Country> list = countryService.findAll();
		request.setAttribute("listCountry", list);
		
		List<Locationpage> listType = locationpageService.findAll();
//		List<Types> listType = typesService.findAll();
		request.setAttribute("listType", listType);
		//初始化autocomplete
		List<Gameinfo> gameinfos = gameinfoService.findAll();
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		for(Gameinfo gameinfo:gameinfos){
			sb.append("{id:\"");
			sb.append(gameinfo.getId());
			sb.append("\",");
			sb.append("gameName:\"");
			sb.append(gameinfo.getGamename());
			sb.append("\"}");
		}
		sb.append("]");
		request.setAttribute("autoVale", sb.toString());
		
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		GameresouceForm gameresouceForm = (GameresouceForm)form;
		Gameresouce gameresouce = new Gameresouce();
		BeanUtils.copyProperties(gameresouce,gameresouceForm);
		
		//获取文件保存路径
		String realPath = systemparameterService.queryByKey(Constants.jarPathName);
		//上传
		FormFile formFileOne = gameresouceForm.getFileOne();
		FormFile formFileTwo = gameresouceForm.getFileTwo();
		List<FormFile> formFiles = new ArrayList<FormFile>();
		formFiles.add(formFileOne);
		formFiles.add(formFileTwo);
		gameresouce.setJarfile(formFileOne.getFileName());
		gameresouce.setJadfile(formFileTwo.getFileName());
		
		String dids = gameresouce.getDid();
		String[] strs = dids.split(",");
		for(String did:strs){
			gameresouce.setDid(did);
			File file = new File(realPath+File.separatorChar+gameresouce.getGameid()+File.separatorChar+gameresouce.getDid());
			//不存在文件夹，创建
			
			if(!file.isDirectory()){
				file.mkdir();
			}
			for(FormFile formFile:formFiles){
				InputStream is = formFileOne.getInputStream();
				OutputStream os = new FileOutputStream(realPath+File.separatorChar+gameresouce.getGameid()+File.separatorChar+gameresouce.getDid()+File.separatorChar+formFile.getFileName());
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
			gameresouceService.save(gameresouce);
			logger.info("gameresouce save");
		}
		
		return mapping.findForward("save");
	}
	
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		GameresouceForm gameresouceForm = (GameresouceForm)form;
		Gameresouce gameresouce = new Gameresouce();
		BeanUtils.copyProperties(gameresouce,gameresouceForm);
		//获取原始数据
		Gameresouce gameresouceOrig  = gameresouceService.queryGameresouce(gameresouceForm.getId());
		//上传
		FormFile formFileOne = gameresouceForm.getFileOne();
		FormFile formFileTwo = gameresouceForm.getFileTwo();
		String jarFile = formFileOne.getFileName().trim();
		String jadFile = formFileTwo.getFileName().trim();
		//获取文件保存路径
		String realPath = systemparameterService.queryByKey(Constants.jarPathName);
		List<FormFile> formFiles = new ArrayList<FormFile>();
		if(!jarFile.equals("")){
			//删除原有的jar文件
			File file = new File(gameresouceOrig.getJarfile());
			file.delete();
			formFiles.add(formFileOne);
			gameresouce.setJarfile(formFileOne.getFileName());
		}
		if(!jadFile.equals("")){
			//删除原有的jad文件
			File file = new File(gameresouceOrig.getJadfile());
			file.delete();
			formFiles.add(formFileTwo);
			gameresouce.setJadfile(formFileTwo.getFileName());
		}

//		File file = new File(realPath);
//		//不存在文件夹，创建
//		if(!file.isDirectory()){
//			file.mkdir();
//		}
		for(FormFile formFile:formFiles){
			
			InputStream is = formFile.getInputStream();
			OutputStream os = new FileOutputStream(realPath+File.separatorChar+""+formFile.getFileName());
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

		gameresouceService.update(gameresouce);
		
		//记录更改日志表
		String oprice = request.getParameter("oprice");
		if(gameresouce.getPrice()!=Long.parseLong(oprice)){
			Changelog changelog = new Changelog();
			changelog.setGameresourceid(gameresouce.getId());
			changelog.setPrice(gameresouce.getPrice());
			changelogService.save(changelog);
		}
		//修改是否可用
		String odisable = request.getParameter("odisable");
		if(gameresouce.getDisable()!=Integer.parseInt(odisable)){
			Changelog changelog = new Changelog();
			changelog.setGameresourceid(gameresouce.getId());
			changelog.setDisable(gameresouce.getDisable());
			changelogService.save(changelog);
		}
		logger.info("gameresouce update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Gameresouce gameresouce  = gameresouceService.queryGameresouce(Integer.parseInt(id));
	
		GameresouceForm gameresouceForm = new GameresouceForm();
		BeanUtils.copyProperties(gameresouceForm,gameresouce);
		
		request.setAttribute("obj",gameresouceForm);
		
		List<Country> list = countryService.findAll();
		request.setAttribute("listCountry", list);
		
//		List<Types> listType = typesService.findAll();
		List<Locationpage> listType = locationpageService.findAll();
		request.setAttribute("listType", listType);
		
		Province province = provinceService.queryProvince(gameresouce.getProvinceid());
		
		String provinceName = "";
		if(null!=province){
			request.setAttribute("countryId", province.getCountryid());
			provinceName = province.getProvincename();
		}
		
		StringBuilder sb = new StringBuilder();
		sb.append("<option value=\"");
		sb.append(gameresouce.getProvinceid());
		sb.append("\" selected");
		sb.append(">");
		sb.append(provinceName);
		sb.append("</option>");
		request.setAttribute("provinceidSelect", sb.toString());
		Gameinfo gameinfo = gameinfoService.queryGameinfo(gameresouce.getGameid());
		request.setAttribute("gameName", gameinfo.getGamename());
		
		return mapping.findForward("edit");
	}
	
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
	    int flag = gameresouceService.delete(Integer.parseInt(id));
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("gameresouce delete");
			out.write("1");
		}else{
			logger.info("gameresouce delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
	//调整顺序
	public ActionForward sequence(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		//列出所有机型
		List<Mobileinfo> mobileList = mobileinfoService.findAll();
		request.setAttribute("mobileList", mobileList);
		//列出所有类别
		List<Types> typeList = typesService.findAll();
		request.setAttribute("typeList", typeList);
		//列出所有位置
		List<Locationpage> listLocationpage = locationpageService.findAll();
		request.setAttribute("listLocationpage", listLocationpage);
		
		List<Country> listCountry = countryService.findAll();
		request.setAttribute("listCountry", listCountry);
		return mapping.findForward("sequence");
	}
	//获取列表
	public ActionForward sequenceList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String did = request.getParameter("did");
		String typeId = request.getParameter("typeId");
		String provinceid = request.getParameter("provinceid");
		String locationpage = request.getParameter("locationpage");
		System.out.println(did);
		System.out.println(typeId);
		System.out.println(provinceid);
		System.out.println(locationpage);
		
		if("".equals(provinceid)||provinceid==null){
			provinceid = "0";
		}
		Map map = new HashMap();
		map.put("did", did);
		map.put("typeId", typeId);
		map.put("provinceid", provinceid);
		map.put("locationpage", locationpage);
		
		List<Gameresouce> listGame = gameresouceService.findSequenceList(map);
		//可用&可显示
		List<Gameresouce> listUse = new ArrayList<Gameresouce>();
		//可用&不可显示
		List<Gameresouce> listView = new ArrayList<Gameresouce>();
		for(Gameresouce gameresouce:listGame){
			Gameinfo gameinfo = gameinfoService.queryGameinfo(gameresouce.getGameid());
			if(gameinfo!=null){
				gameresouce.setGameName(gameinfo.getGamename());
			}
			if(gameresouce.getDisable()==1){
				//可用&不可显示
				listUse.add(gameresouce);
			}else if(gameresouce.getDisable()==2){
				//可用&可显示
				listView.add(gameresouce);
			}
		}
		request.setAttribute("listGame", listGame);
		request.setAttribute("listUse", listUse);
		request.setAttribute("listView", listView);
		//列出所有机型
		List<Mobileinfo> mobileList = mobileinfoService.findAll();
		request.setAttribute("mobileList", mobileList);
		//列出所有类别
		List<Types> typeList = typesService.findAll();
		request.setAttribute("typeList", typeList);
		//列出所有位置
		List<Locationpage> listLocationpage = locationpageService.findAll();
		request.setAttribute("listLocationpage", listLocationpage);
		
		List<Country> listCountry = countryService.findAll();
		request.setAttribute("listCountry", listCountry);
		
		request.setAttribute("didSelect", did);
		request.setAttribute("typeIdSelect", typeId);
		Province province = provinceService.queryProvince(Integer.parseInt(provinceid));
		
		String provinceName = "";
		if(null!=province){
			request.setAttribute("countryId", province.getCountryid());
			provinceName = province.getProvincename();
		}
		
		StringBuilder sb = new StringBuilder();
		sb.append("<option value=\"");
		sb.append(provinceid);
		sb.append("\" selected");
		sb.append(">");
		sb.append(provinceName);
		sb.append("</option>");
		request.setAttribute("provinceidSelect", sb.toString());
		return mapping.findForward("sequence");
	}
	
	public ActionForward sequenceSave(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String viewValues = request.getParameter("values");
		String  useValues = request.getParameter("useValues");
		char[] useChars = useValues.toCharArray();
		Map useMap = new HashMap();
		for(int i=0;i<useChars.length;i++){
			useMap.put("id", Integer.parseInt(String.valueOf(useChars[i])));
			useMap.put("priority", i+1);
			useMap.put("disable", 1);
			gameresouceService.update(useMap);
		}
		//修改为可视
		char[] viewChars = viewValues.toCharArray();
		Map viewMap = new HashMap();
		for(int i=0;i<viewChars.length;i++){
			//更改优先级
			viewMap.put("id", Integer.parseInt(String.valueOf(viewChars[i])));
			viewMap.put("priority", i+1);
			viewMap.put("disable", 2);
			gameresouceService.update(viewMap);
		}
		return mapping.findForward("sequence");
	}
	
	//suitSimilar
	public ActionForward suitSimilar(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		return mapping.findForward("suitSimilar");
	}
	//
	public ActionForward findGameByDid(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String did = request.getParameter("did");
		Map map = new HashMap();
		map.put("did", did);
		List<Gameresouce> gameresouces = gameresouceService.findGameByDid(map);
		for(Gameresouce gameresouce:gameresouces){
			Gameinfo gameinfo = gameinfoService.queryGameinfo(gameresouce.getGameid());
			if(gameinfo!=null){
				gameresouce.setGameName(gameinfo.getGamename());
			}
		}
		request.setAttribute("list", gameresouces);
		return mapping.findForward("findGameByDid");
	}
	public ActionForward saveSimilar(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String did = request.getParameter("did");
		String did2 = request.getParameter("did2");
		String gameid = request.getParameter("gameid");
		//完成2步操作，第一步把did2中数据库相关数据，作为did的数据插入到数据库
		//第二步，把did2对于文件夹中的数据全部复制到对于did中的文件夹中
		String oldDid = did2.split(",")[0];
		String newDid = did.split(",")[0];
		String[] gameIds = gameid.split(",");
		//根据oldDid和gameId,查找数据
		Map map = new HashMap();
		map.put("did", oldDid);
		map.put("gameIds", gameIds);
		List<Gameresouce> Gameresouce = gameresouceService.findGameByGameAndDid(map);
		
		return mapping.findForward("saveSimilar");
	}
}
