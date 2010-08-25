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

import com.tcl.portal.domain.Gameinfo;
import com.tcl.portal.domain.Language;
import com.tcl.portal.domain.Spinfo;
import com.tcl.portal.domain.Types;
import com.tcl.portal.form.GameinfoForm;
import com.tcl.portal.service.GameinfoService;
import com.tcl.portal.service.LanguageService;
import com.tcl.portal.service.SpinfoService;
import com.tcl.portal.service.TypesService;
import com.tcl.portal.util.Constants;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class GameinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(GameinfoAction.class);
	
	private GameinfoService gameinfoService;
	
	private SpinfoService spinfoService;
	
	private LanguageService languageService;
	
	private TypesService typesService;
	
	public void setTypesService(TypesService typesService) {
		this.typesService = typesService;
	}

	public void setSpinfoService(SpinfoService spinfoService) {
		this.spinfoService = spinfoService;
	}

	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}
	
	
	//列表，查找
	public void setLanguageService(LanguageService languageService) {
		this.languageService = languageService;
	}

	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String gamename = request.getParameter("gamename");//游戏名称
		String spid = request.getParameter("spid");//sp名称
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("gamename", gamename);
		map.put("spid", spid);
		pager.addParam("gamename", gamename);
		pager.addParam("spid", spid);
		pager.setEntryCount(gameinfoService.findCount(map));
		List<Gameinfo> list = gameinfoService.findList(map);
		for(Gameinfo gameinfo:list){
			Spinfo spinfo = spinfoService.querySpinfo(gameinfo.getSpid());
			if(spinfo!=null){
				gameinfo.setSpName(spinfo.getName());
			}
			Language language = languageService.queryLanguage(gameinfo.getLanguage());
			if(language!=null){
				gameinfo.setLanguageName(language.getLanguage());
			}
			Types types = typesService.queryTypes(gameinfo.getKindid());
			if(types!=null){
				gameinfo.setTypeName(types.getTypevalue());
			}
		}
		request.setAttribute("list", list);
		List<Spinfo> spinfoList =  spinfoService.findAll();
		request.setAttribute("spinfoList", spinfoList);
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
		
		List<Language> list = languageService.findAll();
		request.setAttribute("languageList", list);
		
		List<Types> listTypes = typesService.findAll();
		request.setAttribute("listTypes", listTypes);
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		GameinfoForm gameinfoForm = (GameinfoForm)form;
		Gameinfo gameinfo = new Gameinfo();
		BeanUtils.copyProperties(gameinfo,gameinfoForm);
		
		String imagePath = Constants.IMAGE_PATH;
		
		File file = new File(imagePath);
		//不存在文件夹，创建
		if(!file.isDirectory()){
			file.mkdir();
		}
		//上传
		FormFile formFileOne = gameinfoForm.getFileOne();
		FormFile formFileTwo = gameinfoForm.getFileTwo();
		List<FormFile> formFiles = new ArrayList<FormFile>();
		formFiles.add(formFileOne);
		formFiles.add(formFileTwo);
		gameinfo.setImagename(formFileOne.getFileName());
		gameinfo.setIcon(formFileTwo.getFileName());
		
		for(FormFile formFile:formFiles){
			InputStream is = formFileOne.getInputStream();
			OutputStream os = new FileOutputStream(imagePath+File.separatorChar+formFile.getFileName());
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
		
		gameinfoService.save(gameinfo);
		logger.info("gameinfo save");
		return mapping.findForward("save");
	}
	
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		GameinfoForm gameinfoForm = (GameinfoForm)form;
		Gameinfo gameinfo = new Gameinfo();
		BeanUtils.copyProperties(gameinfo,gameinfoForm);
		
		String imagePath = Constants.IMAGE_PATH;
		//获取原对象
		Gameinfo gameinfoOrig = gameinfoService.queryGameinfo(gameinfo.getId());
		//上传
		FormFile formFileOne = gameinfoForm.getFileOne();
		FormFile formFileTwo = gameinfoForm.getFileTwo();
		String image = formFileOne.getFileName().trim();
		String icon = formFileTwo.getFileName().trim();
		List<FormFile> formFiles = new ArrayList<FormFile>();
		if(!image.equals("")){
			//删除原有的图片文件
			File file = new File(imagePath+File.separatorChar+gameinfoOrig.getImagename());
			file.delete();
			formFiles.add(formFileOne);
			gameinfo.setImagename(image);
			gameinfo.setIcon(gameinfoOrig.getIcon());
		}
		if(!icon.equals("")){
			//删除原有的jad文件
			File file = new File(imagePath+File.separatorChar+gameinfoOrig.getIcon());
			file.delete();
			formFiles.add(formFileTwo);
			gameinfo.setImagename(gameinfoOrig.getImagename());
			gameinfo.setIcon(icon);
		}
		
	for(FormFile formFile:formFiles){
			InputStream is = formFile.getInputStream();
			OutputStream os = new FileOutputStream(imagePath+File.separatorChar+""+formFile.getFileName());
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

		gameinfoService.update(gameinfo);
		logger.info("gameinfo update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Gameinfo gameinfo  = gameinfoService.queryGameinfo(Integer.parseInt(id));
		GameinfoForm gameinfoForm = new GameinfoForm();
		BeanUtils.copyProperties(gameinfoForm,gameinfo);
		request.setAttribute("obj",gameinfoForm );
		
		List<Spinfo> spinfoList =  spinfoService.findAll();
		request.setAttribute("spinfoList", spinfoList);
		
		List<Language> list = languageService.findAll();
		request.setAttribute("languageList", list);
		
		List<Types> listTypes = typesService.findAll();
		request.setAttribute("listTypes", listTypes);
		return mapping.findForward("edit");
	}
	//选择
	public ActionForward findListChoice(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		pager.setEntryCount(gameinfoService.findCount(map));
		List<Gameinfo> list = gameinfoService.findList(map);
		for(Gameinfo gameinfo:list){
			Spinfo spinfo = spinfoService.querySpinfo(gameinfo.getSpid());
			if(spinfo!=null){
				gameinfo.setSpName(spinfo.getName());
			}
			Language language = languageService.queryLanguage(gameinfo.getLanguage());
			if(language!=null){
				gameinfo.setLanguageName(language.getLanguage());
			}
		}
		request.setAttribute("list", list);
	
		return mapping.findForward("listChoice");
	}
	
	//ajax根据id查找游戏记录
	public ActionForward queryGame(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Gameinfo gameinfo  = gameinfoService.queryGameinfo(Integer.parseInt(id));
		StringBuilder sb = new StringBuilder("");
		sb.append(gameinfo.getId());
		sb.append(",");
		sb.append(gameinfo.getGamename());
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		out.write(sb.toString());
		out.flush();
		return null;
	}
}
