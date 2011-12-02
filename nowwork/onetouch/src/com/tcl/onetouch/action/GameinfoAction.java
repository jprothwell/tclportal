package com.tcl.onetouch.action;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.imageio.ImageIO;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;
import org.apache.struts.upload.FormFile;

import com.tcl.onetouch.domain.Country;
import com.tcl.onetouch.domain.GameLanguage;
import com.tcl.onetouch.domain.Gameinfo;
import com.tcl.onetouch.domain.Language;
import com.tcl.onetouch.domain.Logs;
import com.tcl.onetouch.domain.Spinfo;
import com.tcl.onetouch.domain.Types;
import com.tcl.onetouch.domain.User;
import com.tcl.onetouch.form.GameinfoForm;
import com.tcl.onetouch.service.CountryService;
import com.tcl.onetouch.service.GameLanguageService;
import com.tcl.onetouch.service.GameinfoService;
import com.tcl.onetouch.service.LanguageService;
import com.tcl.onetouch.service.LogsService;
import com.tcl.onetouch.service.SpinfoService;
import com.tcl.onetouch.service.SystemparameterService;
import com.tcl.onetouch.service.TypesService;
import com.tcl.onetouch.service.VisiteinfoService;
import com.tcl.onetouch.util.Constants;
import com.tcl.onetouch.util.Pager;
import com.tcl.onetouch.util.PagerBuilder;

public class GameinfoAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(GameinfoAction.class);
	
	public static String smallJsp = "small.jpg";
	
	private GameinfoService gameinfoService;
	
	private SpinfoService spinfoService;
	
	private LanguageService languageService;
	
	private TypesService typesService;
	
	private SystemparameterService systemparameterService;
	
	private LogsService logsService;
	
	private VisiteinfoService visiteinfoService;
	
	private CountryService  countryService;
	
	private GameLanguageService gameLanguageService;
	
	public void setGameLanguageService(GameLanguageService gameLanguageService) {
		this.gameLanguageService = gameLanguageService;
	}

	public void setCountryService(CountryService countryService) {
		this.countryService = countryService;
	}

	public void setLogsService(LogsService logsService) {
		this.logsService = logsService;
	}
	
	public void setSystemparameterService(
			SystemparameterService systemparameterService) {
		this.systemparameterService = systemparameterService;
	}

	public void setTypesService(TypesService typesService) {
		this.typesService = typesService;
	}

	public void setSpinfoService(SpinfoService spinfoService) {
		this.spinfoService = spinfoService;
	}

	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}
	
	public void setVisiteinfoService(VisiteinfoService visiteinfoService) {
		this.visiteinfoService = visiteinfoService;
	}

	//列表，查找
	public void setLanguageService(LanguageService languageService) {
		this.languageService = languageService;
	}

	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String name = request.getParameter("name");//游戏名称
		String spid = request.getParameter("spid");//sp名称
		if(name==null){
			name = "";
		}
		if(spid==null){
			spid = "";
		}
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("name", name);
		map.put("spid", spid);
		pager.addParam("name", name);
		pager.addParam("spid", spid);
		pager.setEntryCount(gameinfoService.findCount(map));
		List<Gameinfo> list = gameinfoService.findList(map);
		for(Gameinfo gameinfo:list){
			Spinfo spinfo = spinfoService.querySpinfo(gameinfo.getSpid());
			if(spinfo!=null){
				gameinfo.setSpName(spinfo.getName());
			}
//			Language language = languageService.queryLanguage(gameinfo.getLanguage());
//			if(language!=null){
//				gameinfo.setLanguageName(language.getLanguage());
//			}
//		
//			Country country = countryService.queryCountry(gameinfo.getCountry());
//			if(country!=null){
//				gameinfo.setCountryName(country.getName());
//			}
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
		
//		List<Language> list = languageService.findAll();
//		request.setAttribute("languageList", list);
		
//		List<Country> countryList = countryService.findAll();
//		request.setAttribute("countryList", countryList);
		
		List<Types> listTypes = typesService.findAll();
		request.setAttribute("listTypes", listTypes);
		saveToken(request); 
		return mapping.findForward("add");
	}
	/**
	 * 保存
	 * 1.对于主题信息，保存在gameinfo信息表里面
	 * 2.对于不同语言，图片名，保存在gameLanguage表中
	 * 3.保存需要，分成2张表的操作，完成操作任务
	 * 4.对于添加语言，如果不选择上传图片，就是用第一上传的图片
	 * 5.对于游戏资源的目录结构为，游戏id。也就是说我们将之前的目录结构更改为只有一级目录，不论游戏图片和多个游戏机型的游戏包，都放在一个目录文件中。
	 * 	 而游戏包区分机型，可以根据更改游戏包的命名来完成。这样目录级别不会太多，并且一个游戏id的文件夹里面包含所有型号手机的适配版，图片，也不会造成
	 *   混乱，文件名得命名为一个易懂区分的名字至关重要。
	 * 6.展现时候，在每个游戏后面，有一个进入多语言版本的连接，在里面进行添加语言操作。
	 */
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String type = request.getParameter("type");
		
		GameinfoForm gameinfoForm = (GameinfoForm)form;
		Gameinfo gameinfo = new Gameinfo();
		BeanUtils.copyProperties(gameinfo,gameinfoForm);
		String imagePath = systemparameterService.queryByKey(Constants.IMAGE_PATH);	
//		if("0".equals(type)){
			//添加语言
			//游戏语言信息
			//上传
//			FormFile formFileOne = gameinfoForm.getFileOne();
//			
//			GameLanguage gameLanguage = new GameLanguage();
//			gameLanguage.setName(gameinfo.getGamename());
//			gameLanguage.setGameId(gameinfo.getId());
//			gameLanguage.setBrief(gameinfo.getBrief());
//			gameLanguage.setDetailinfo(gameinfo.getDetailinfo());
			//首先默认为游戏的图片是不改变的，因为这种可能比较小。如果有需要就开放此功能。
//			if(formFileOne!=null){
//				//如果说上传了图片，那么就需要保存
//				gameLanguage.setImagename(formFileOne.getFileName());
//				gameLanguage.setIcon("small_"+formFileOne.getFileName());
//				uploadFile(imagePath,gameinfo.getId(),formFileOne);
//			}else{
//				//没有上传图片，就为默认的图片
//				gameLanguage.setImagename(gameinfo.getImagename());
//				gameLanguage.setIcon(gameinfo.getIcon());
////			}
//			gameLanguageService.save(gameLanguage);
//		}else{
			//游戏第一次添加
			//上传
			FormFile formFileOne = gameinfoForm.getFileOne();
//			FormFile formFileTwo = gameinfoForm.getFileTwo();
//			List<FormFile> formFiles = new ArrayList<FormFile>();
//			formFiles.add(formFileOne);
//			formFiles.add(formFileTwo);
			gameinfo.setImagename(formFileOne.getFileName());
			gameinfo.setIcon(smallJsp);
			int id = gameinfoService.save(gameinfo);//保存gameid，并且获取这个id
			logger.info("gameinfo save");
			
			uploadFile(imagePath,id,formFileOne);
//			//游戏语言信息
//			GameLanguage gameLanguage = new GameLanguage();
//			gameLanguage.setName(gameinfo.getGamename());
//			gameLanguage.setGameId(id);
//			gameLanguage.setBrief(gameinfo.getBrief());
//			gameLanguage.setDetailinfo(gameinfo.getDetailinfo());
//			gameLanguage.setImagename(formFileOne.getFileName());
//			gameLanguage.setIcon("small_"+formFileOne.getFileName());
//			gameLanguageService.save(gameLanguage);
//			}
			
//		}
		 
		//记录日志
		HttpSession session = request.getSession();
		User user = (User)session.getAttribute(Constants.SESSION_USER);
		Logs log = new Logs();
		log.setUserid(user.getId());
		log.setLtime(new Date());
		log.setDosomthing("add game:"+gameinfo.getGamename());
		logsService.save(log);
		return mapping.findForward("save");  
	}
	
	private void uploadFile(String imagePath, int id, FormFile formFileOne) throws IOException {
		File file = new File(imagePath+File.separatorChar+id);
		//不存在文件夹，创建
		if(!file.isDirectory()){
			file.mkdir();
		}
//		for(FormFile formFile:formFiles){
			InputStream is = formFileOne.getInputStream();
			OutputStream os = new FileOutputStream(imagePath+File.separatorChar+id+File.separatorChar+formFileOne.getFileName());
			 int bufferSize = 1024*4;
			 byte[] buffer = new byte[bufferSize];
			 int len = 0;
			 while((len = is.read(buffer, 0,bufferSize))!=-1){
				 os.write(buffer, 0, len);
			 }
			 os.flush();
			 os.close();
			 is.close();
			 //压缩小图标
			 OutputStream osSmall = new FileOutputStream(imagePath+File.separatorChar+id+File.separatorChar+smallJsp);
			 File srcfile = new File(imagePath+File.separatorChar+id+File.separatorChar+formFileOne.getFileName());
			 BufferedImage src = ImageIO.read(srcfile);
			 //原宽
			 int width = src.getWidth();
			 //原高
			 int height = src.getHeight();
			 //改变后的宽度
			 int smallWidth = 60;
			 //根据改变后的宽度计算该表后的宽度
			 int smallHeight = 60*height/width;
			 Image image = src.getScaledInstance(smallWidth, smallHeight,Image.SCALE_DEFAULT);
			 BufferedImage tag = new BufferedImage(smallWidth, smallHeight,BufferedImage.TYPE_INT_RGB);
			 Graphics g = tag.getGraphics();
			 g.drawImage(image, 0, 0, null);
			 g.dispose();
			 ImageIO.write(tag, "JPEG",osSmall);
			 osSmall.flush();
			 osSmall.close();
		
	}

	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		GameinfoForm gameinfoForm = (GameinfoForm)form;
		Gameinfo gameinfo = new Gameinfo();
		BeanUtils.copyProperties(gameinfo,gameinfoForm);
		String imagePath = systemparameterService.queryByKey(Constants.IMAGE_PATH);
		//获取原对象
		Gameinfo gameinfoOrig = gameinfoService.queryGameinfo(gameinfo.getId());
		//上传
		FormFile formFileOne = gameinfoForm.getFileOne();
//		FormFile formFileTwo = gameinfoForm.getFileTwo();
		String image = formFileOne.getFileName().trim();
//		String icon = formFileTwo.getFileName().trim();
//		List<FormFile> formFiles = new ArrayList<FormFile>();
		if(!image.equals("")){
			//删除原有的图片文件
			File file = new File(imagePath+File.separatorChar+gameinfoOrig.getImagename());
			file.delete();
//			formFiles.add(formFileOne);
			gameinfo.setImagename(image);
			gameinfo.setIcon(gameinfoOrig.getIcon());
			
			InputStream is = formFileOne.getInputStream();
			OutputStream os = new FileOutputStream(imagePath+File.separatorChar+gameinfo.getId()+File.separatorChar+formFileOne.getFileName());
			 int bufferSize = 1024*4;
			 byte[] buffer = new byte[bufferSize];
			 int len = 0;
			 while((len = is.read(buffer, 0,bufferSize))!=-1){
				 os.write(buffer, 0, len);
			 }
			 os.flush();
			 os.close();
			 is.close();
			 
			 //压缩小图标
			 OutputStream osSmall = new FileOutputStream(imagePath+File.separatorChar+gameinfo.getId()+File.separatorChar+smallJsp);
			 File srcfile = new File(imagePath+File.separatorChar+gameinfo.getId()+File.separatorChar+formFileOne.getFileName());
			 BufferedImage src = ImageIO.read(srcfile);
			 //原宽
			 int width = src.getWidth();
			 //原高
			 int height = src.getHeight();
			 //改变后的宽度
			 int smallWidth = 60;
			 //根据改变后的宽度计算该表后的宽度
			 int smallHeight = 60*height/width;
			 Image newImage = src.getScaledInstance(smallWidth, smallHeight,Image.SCALE_DEFAULT);
			 BufferedImage tag = new BufferedImage(smallWidth, smallHeight,BufferedImage.TYPE_INT_RGB);
			 Graphics g = tag.getGraphics();
			 g.drawImage(newImage, 0, 0, null);
			 g.dispose();
			 ImageIO.write(tag, "JPEG",osSmall);
			 osSmall.flush();
			 osSmall.close();
		}
		gameinfo.setIcon(smallJsp);
//		if(!icon.equals("")){
//			//删除原有的jad文件
//			File file = new File(imagePath+File.separatorChar+gameinfoOrig.getIcon());
//			file.delete();
//			formFiles.add(formFileTwo);
//			gameinfo.setImagename(gameinfoOrig.getImagename());
//			gameinfo.setIcon(icon);
//		}
		
//	for(FormFile formFile:formFiles){
		
		
//		}

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
//		
//		List<Language> list = languageService.findAll();
//		request.setAttribute("languageList", list);
//		
//		List<Country> countryList = countryService.findAll();
//		request.setAttribute("countryList", countryList);
//		
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
//		map.put("start",start);
//		map.put("end", end);
//		pager.setEntryCount(gameinfoService.findCount(map));
//		List<Gameinfo> list = gameinfoService.findList(map);
		List<Gameinfo> list = gameinfoService.findUseGameInfo();
		for(Gameinfo gameinfo:list){
			Spinfo spinfo = spinfoService.querySpinfo(gameinfo.getSpid());
			if(spinfo!=null){
				gameinfo.setSpName(spinfo.getName());
			}
//			Language language = languageService.queryLanguage(gameinfo.getLanguage());
//			if(language!=null){
//				gameinfo.setLanguageName(language.getLanguage());
//			}
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
	
	//删除
	public ActionForward delete(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Gameinfo gameinfo = gameinfoService.queryGameinfo(Integer.parseInt(id));
	    int flag = gameinfoService.delete(Integer.parseInt(id));
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("gameinfo delete");
			out.write("1");
			//记录日志
			HttpSession session = request.getSession();
			User user = (User)session.getAttribute(Constants.SESSION_USER);
			Logs log = new Logs();
			log.setUserid(user.getId());
			log.setLtime(new Date());
			log.setDosomthing("add game:"+gameinfo.getGamename());
			logsService.save(log);
		}else{
			logger.info("gameinfo delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
	//增加语言
	
	public ActionForward addLanguage(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		Gameinfo gameinfo  = gameinfoService.queryGameinfo(Integer.parseInt(id));
		GameinfoForm gameinfoForm = new GameinfoForm();
		BeanUtils.copyProperties(gameinfoForm,gameinfo);
		request.setAttribute("obj",gameinfoForm );
		
		List<Language> list = languageService.findAll();
		request.setAttribute("languageList", list);
		
		return mapping.findForward("addLanguage");
	}
}
