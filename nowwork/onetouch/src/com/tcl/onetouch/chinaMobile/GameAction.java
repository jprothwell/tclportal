package com.tcl.onetouch.chinaMobile;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
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

import com.tcl.onetouch.domain.Gameinfo;
import com.tcl.onetouch.domain.Logs;
import com.tcl.onetouch.domain.MobileGame;
import com.tcl.onetouch.domain.Mobileinfo;
import com.tcl.onetouch.domain.User;
import com.tcl.onetouch.form.GameinfoForm;
import com.tcl.onetouch.service.GameinfoService;
import com.tcl.onetouch.service.GameresouceService;
import com.tcl.onetouch.service.MobileinfoService;
import com.tcl.onetouch.service.SystemparameterService;
import com.tcl.onetouch.util.Constants;
import com.tcl.onetouch.util.Pager;
import com.tcl.onetouch.util.PagerBuilder;

/**
 * 游戏的信息维护
 * @author kun.shen
 *	由于游戏基地的业务比现有业务对于游戏方面简单些，所以这部分页面重新写。
 */
public class GameAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(GameAction.class);
	
	private GameinfoService gameinfoService;
	
	private SystemparameterService systemparameterService;
	
	private MobileinfoService mobileinfoService;
	
	private GameresouceService gameresouceService;
	
	public void setGameresouceService(GameresouceService gameresouceService) {
		this.gameresouceService = gameresouceService;
	}

	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}

	public void setSystemparameterService(
			SystemparameterService systemparameterService) {
		this.systemparameterService = systemparameterService;
	}

	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}

	public static String smallJsp = "small.jpg";
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String name = request.getParameter("name");//游戏名称
		if(name==null){
			name = "";
		}
		
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("name", name);
		pager.addParam("name", name);
		pager.setEntryCount(gameinfoService.findCount(map));
		List<Gameinfo> list = gameinfoService.findList(map);
		
		request.setAttribute("list", list);
		return mapping.findForward("list");
	}
	
	//增加页面以及初始化数据
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		Date date = new Date();
		request.setAttribute("date", date);
		return mapping.findForward("add");
	}
	
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		GameinfoForm gameinfoForm = (GameinfoForm)form;
		Gameinfo gameinfo = new Gameinfo();
		BeanUtils.copyProperties(gameinfo,gameinfoForm);
		String imagePath = systemparameterService.queryByKey(Constants.IMAGE_PATH);	
		FormFile formFileOne = gameinfoForm.getFileOne();
		gameinfo.setImagename(formFileOne.getFileName());
		gameinfo.setIcon(smallJsp);
		int id = gameinfoService.saveChinaMobileGame(gameinfo);//保存gameid，并且获取这个id
		logger.info("gameinfo save");
			
		uploadFile(imagePath,id,formFileOne);

		return mapping.findForward("save");  
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

		gameinfoService.updateMobileGame(gameinfo);
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
		return mapping.findForward("edit");
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
	
	//游戏手机匹配信息
	//调整顺序
	public ActionForward sequence(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		//列出所有机型
		List<Mobileinfo> mobileList = mobileinfoService.findAll();
		request.setAttribute("mobileList", mobileList);
		return mapping.findForward("sequence");
	}
	//获取列表
	public ActionForward sequenceList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String did = request.getParameter("did");
		
//		if("".equals(provinceid)||provinceid==null){
//			provinceid = "0";
//		}
		Map map = new HashMap();
		map.put("did", did);
		
	
		//获取游戏，机型对照表中的所有数据
		List<MobileGame> mobileGames = gameinfoService.findMobileGameByDid(did);
		List<Gameinfo> showGame = new ArrayList<Gameinfo>();//显示的game
		List<Gameinfo> notShowGame = gameinfoService.findAllNoCache();//不显示的game,初始为所有游戏;
		
		for(MobileGame mobileGame:mobileGames){
			Gameinfo gameinfo = gameinfoService.queryGameinfoNoCache(mobileGame.getGameId());
			showGame.add(gameinfo);
			for(int i=0;i<notShowGame.size();i++){
				if(notShowGame.get(i).getId().intValue()==mobileGame.getGameId().intValue()){
					notShowGame.remove(i);
				}
			}
			}
		request.setAttribute("showGame", showGame);
		request.setAttribute("notShowGame", notShowGame);
		
		//列出所有机型
		List<Mobileinfo> mobileList = mobileinfoService.findAll();
		request.setAttribute("mobileList", mobileList);

		request.setAttribute("didSelect", did);
		return mapping.findForward("sequence");
	}
	
	public ActionForward sequenceSave(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String viewValues = request.getParameter("values");

		if(!"".equals(viewValues)){
			//修改为可视
			String[] viewChars = viewValues.split(":");
			for(int i=0;i<viewChars.length;i++){
				Map viewMap = new HashMap();
				//更改优先级
				viewMap.put("id", Integer.parseInt(viewChars[i]));
				viewMap.put("priority", i+1);
				gameinfoService.updateMobileGame(viewMap);
			}
		}
		
		return mapping.findForward("sequence");
	}
	
	//删除
	public ActionForward delMobileGame(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String did = request.getParameter("did");
		String gameId = request.getParameter("gameId");
		Map<String,String> map = new HashMap<String,String>();
		map.put("did", did);
		map.put("gameId", gameId);
	    int flag = gameinfoService.delMobileGame(map);
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("gameinfo delete");
			out.write("1");
		}else{
			logger.info("gameinfo delete fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
	//增加
	public ActionForward saveMobileGame(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String did = request.getParameter("did");
		String gameId = request.getParameter("gameId");
		Map<String,String> map = new HashMap<String,String>();
		map.put("did", did);
		map.put("gameId", gameId);
	    int flag = gameinfoService.addMobileGame(map);
		
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		if(flag==1){
			logger.info("gameinfo save");
			out.write("1");
		}else{
			logger.info("gameinfo save fail");
			out.write("0");
		}
		out.flush();
		return null;
	}
}
