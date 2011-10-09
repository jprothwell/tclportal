package com.tcl.onetouch.wap;

import java.net.URLDecoder;
import java.net.URLEncoder;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.apache.struts.Globals;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.onetouch.domain.Ad;
import com.tcl.onetouch.domain.Downloadinfo;
import com.tcl.onetouch.domain.Gameinfo;
import com.tcl.onetouch.domain.Gameresouce;
import com.tcl.onetouch.domain.Ipinfo;
import com.tcl.onetouch.domain.Mobileinfo;
import com.tcl.onetouch.domain.Types;
import com.tcl.onetouch.domain.Visiteinfo;
import com.tcl.onetouch.service.AdService;
import com.tcl.onetouch.service.DownloadinfoService;
import com.tcl.onetouch.service.GameinfoService;
import com.tcl.onetouch.service.GameresouceService;
import com.tcl.onetouch.service.IpinfoService;
import com.tcl.onetouch.service.MobileinfoService;
import com.tcl.onetouch.service.PageinfoService;
import com.tcl.onetouch.service.TypesService;
import com.tcl.onetouch.service.VisiteinfoService;
import com.tcl.onetouch.util.Constants;
import com.tcl.onetouch.util.Util;



/**
 * 用户手机登陆
 * @author kun.shen
 *
 */
public class LoginAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(LoginAction.class);
	
	private IpinfoService ipinfoService;
	
	private GameresouceService gameresouceService;
	
	private GameinfoService gameinfoService;
	
	private VisiteinfoService visiteinfoService;
	
	private PageinfoService pageinfoService;
	
	private TypesService typesService;
	
	private MobileinfoService mobileinfoService;
	
	private AdService adService;
	
	private DownloadinfoService downloadinfoService;
	
	public void setAdService(AdService adService) {
		this.adService = adService;
	}

	public void setTypesService(TypesService typesService) {
		this.typesService = typesService;
	}

	public void setVisiteinfoService(VisiteinfoService visiteinfoService) {
		this.visiteinfoService = visiteinfoService;
	}

	public void setIpinfoService(IpinfoService ipinfoService) {
		this.ipinfoService = ipinfoService;
	}
	
	public void setGameresouceService(GameresouceService gameresouceService) {
		this.gameresouceService = gameresouceService;
	}

	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}
	
	public void setPageinfoService(PageinfoService pageinfoService) {
		this.pageinfoService = pageinfoService;
	}
	

	public void setMobileinfoService(MobileinfoService mobileinfoService) {
		this.mobileinfoService = mobileinfoService;
	}
	
	public void setDownloadinfoService(DownloadinfoService downloadinfoService) {
		this.downloadinfoService = downloadinfoService;
	}
	
	//手机用户进入主页 
	public ActionForward index(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
//		HttpSession session = request.getSession();
//		String sessiondid = (String) session.getAttribute(Constants.DID_VALUE);	
//        if(sessiondid!=null&&!"".equals(sessiondid)&&!"null".equals(sessiondid))
//        	did=sessiondid;
		
		String did = request.getParameter("did");
        String ip = Util.getIp(request);
        String phnum = Util.getPhone(request);
        String language = Util.getAcceptLanguage(request);
        System.out.println("ip:"+ip+"phnum:"+phnum+"language:"+language);
        
        
        int pageid=1;
        String pagename="indexWap1";
        if(did!=null&&!"".equals(did)&&!"null".equals(did)){
	         //*************获取显示页面************/
        	Mobileinfo mobile = mobileinfoService.queryMobileinfo(did);
	    	//pageid = pageinfoService.queryPageName(did);
        	pageid = mobile.getPageid();
//	        session.setAttribute(Constants.DID_VALUE, did);
//	    	session.setAttribute(Constants.PAGEID_VALUE, pageid);
			//根据ip查找到国家       
			Ipinfo ipinfo = ipinfoService.queryIpinfo(ip);	
			Map map = new HashMap(2);
			map.put("did", did);
			if(ipinfo!=null){
//				session.setAttribute(Constants.PROVICEID_VALUE,ipinfo.getProviceid());
				map.put("country", ipinfo.getCountry());
				request.setAttribute("country",ipinfo.getCountry());
			}else{
				map.put("country", 1);//默认国，默认英语
				request.setAttribute("country",1);
//				session.setAttribute(Constants.PROVICEID_VALUE,0);
			}		
			//1.根据did，国家，获取游戏列表资源
			//2.从缓存中获取游戏信息，显示在界面上
			
			List<Gameresouce> gameresourceList = gameresouceService.findGameByCountryAndDid(map);
			List<Gameinfo> gameinfoList = new ArrayList<Gameinfo>();
			for(Gameresouce gr:gameresourceList){
				Gameinfo gameinfo = gameinfoService.queryGameinfo(gr.getGameid());
				gameinfo.setKindName(typesService.queryTypes(gameinfo.getKindid()).getTypevalue());
				gameinfo.setTypeid(gr.getTypeid());
				gameinfoList.add(gameinfo);
			}

//			List<Gameinfo> list = gameinfoService.findGameWap(map);
//			for(Gameinfo gameinfo:list){
//				gameinfo.setKindName(typesService.queryType(gameinfo.getKindid()));
//			}		
//			if(gameinfoList.size()==0){
//				gameinfoList = gameinfoService.findGameWap(map);	
//			}
		
//				Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
//				if(customer!=null){
//					request.setAttribute("username", customer.getUsername());
//				}else{
//					request.setAttribute("username","");
//				}
				
			//获取广告图片
		  Ad ad = adService.queryAdByDid(did);
		  
		  switch(pageid){
		    case 2:pagename="indexWap2";
		       break;
		    case 3:pagename="indexWap3";
		       break;
		    default:pagename="indexWap1";
		      break;		  
		  }
			//*********访问统计***********************/		
			Visiteinfo visiteinfo = new Visiteinfo();
			visiteinfo.setDid(did);	
			visiteinfo.setGameid(0);
			visiteinfo.setIp(ip);
			visiteinfo.setLocation(0);
			visiteinfo.setTelephone(phnum);
			visiteinfo.setTitleid(0);
			visiteinfoService.save(visiteinfo);
			//*********访问统计end***********************/
			request.setAttribute("pageid",pageid);
			request.setAttribute("did",did);
			request.setAttribute("ad",ad);
			request.setAttribute("mdid", did);//用于判断是否显示图片
			request.setAttribute("list", gameinfoList);
			return mapping.findForward(pagename);
		}else{
			//如果did不存在，根据did得到手机列表
			List<Mobileinfo> list = mobileinfoService.findAll();	
			request.setAttribute("list",list);
			return mapping.findForward("indexMeno");
		}
	}
	//手机用户进入游戏列表
	public ActionForward menulist(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
	    String kindid = request.getParameter("kindid");
	    String content = request.getParameter("content");//搜索内容
	    String did = request.getParameter("did");
	    String pageid = request.getParameter("pageid");
	    String pagn = request.getParameter("pagenum");
	    String country = request.getParameter("country");
	    int numCount=0;
	    //通过session得到did,pageid	
//	    HttpSession   session=request.getSession(false); 
//	    String did = (String) session.getAttribute(Constants.DID_VALUE);
//	    int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
	  
//	    Integer proviceid =  (Integer) session.getAttribute(Constants.PROVICEID_VALUE);
        String ip = Util.getIp(request);
        String phnum = Util.getPhone(request);
        String pagename = "listWap1";
        String kindName = "";
       if(kindid!=null&&!"".equals(kindid)&&!"null".equals(kindid)&&!"0".equals(kindid)){
    	   Types types = typesService.queryTypes(Integer.parseInt(kindid));
    	   if(types!=null){
    		   kindName = types.getTypevalue();
    	   }
       }else {
    	   kindid="0"; 
       }
        
        int checkNextPage=0;
        
        Map map = new HashMap(6);
        int pagenum = 1;//TODO
        if(pagn!=null&&!"".equals(pagn)&&!"null".equals(pagn))
        	pagenum=Integer.parseInt(pagn);
		int start = (pagenum-1) * Constants.PAGESIZE;
		int end = Constants.PAGESIZE;
		map.put("start",start);
		map.put("end", end);
		map.put("did", did);
		map.put("kindid",kindid);
		map.put("content",content);
		map.put("country",country);
		List<Gameinfo> list =null;
		//
		if(!"0".equals(kindid)){
			numCount = gameinfoService.findGameinfoByKindCount(map);//findGameMenoCount(map);//总数
			list = gameinfoService.findGameinfoByKind(map);//findGameMeno(map);
		}
		else if(content!=null&&!"".equals(content)&&!"null".equals(content)){
			numCount = gameinfoService.findGameinfoByContentCount(map);//findGMCount(map);//总数
			list = gameinfoService.findGameinfoByContent(map);//findGM(map);
			kindName="游戏搜索";
		}else {
			numCount = gameinfoService.findNewGameCount(map);//newGMCount(map);
			 list = gameinfoService.findNewGame(map);//newGM(map);
			 kindName="最新上线游戏";
		}
		////////////////////////////////////////////////////////////
		
	    if((pagenum+1)*Constants.PAGESIZE<numCount) checkNextPage=1;
	    
	    request.setAttribute("did", did);
	    request.setAttribute("pageid", pageid);
		request.setAttribute("list",list);
		request.setAttribute("kindid",kindid);
		request.setAttribute("pagenum", pagenum);
		request.setAttribute("checkNextPage",checkNextPage);
		request.setAttribute("gamenum",Constants.PAGESIZE);
		request.setAttribute("kindName",kindName);
		request.setAttribute("numCount",numCount);
		request.setAttribute("country", country);
		if("2".equals(pageid)){
			pagename = "listWap2";
		}else if("3".equals(pageid)){
			pagename = "listWap3";
		}else{
			pagename="listWap1";
		}
			  
			//*********访问统计***********************//		
				Visiteinfo visiteinfo = new Visiteinfo();
				visiteinfo.setDid(did);	
				visiteinfo.setGameid(0);
				visiteinfo.setIp(ip);
				visiteinfo.setLocation(0);
				visiteinfo.setTelephone(phnum);
				visiteinfo.setTitleid(Integer.parseInt(kindid));
				visiteinfoService.save(visiteinfo);
				//*********访问统计end***********************/
			return mapping.findForward(pagename);
	}
	//wap调用
	public ActionForward queryGameinfo(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		//游戏id
		String gameId = request.getParameter("gameId");
		String location = request.getParameter("location");
		String pageid = request.getParameter("pageid");
		String did = request.getParameter("did");
	    String country = request.getParameter("country");

		int locationid=0;
		if(location!=null&&!"".equals(location)&&!"null".equals(location))locationid=Integer.parseInt(location);
		HttpSession session = request.getSession();
		//int	pageid = (Integer) session.getAttribute(Constants.PAGEID_VALUE);
		//String did = (String) session.getAttribute(Constants.DID_VALUE);
		//int proviceid =  (Integer) session.getAttribute(Constants.PROVICEID_VALUE);
		String phnum =Util.getPhone(request);
		String ip=Util.getIp(request);
		//获取游戏简介
		Gameinfo gameInfo = gameinfoService.queryGameinfo(Integer.parseInt(gameId));
		request.setAttribute("obj", gameInfo);
		//request.setAttribute("imgName", "game/"+gameInfo.getId()+"/"+did+"/"+gameInfo.getImagename());
		
//		//获取游戏评论
//		List<Comment> list = commentService.findCommentById(Integer.parseInt(gameId));
//		request.setAttribute("list", list);
//		int numCount = commentService.findCommentCount(Integer.parseInt(gameId));
//		request.setAttribute("numCount",numCount);

		//*********访问统计***********************//		
		Visiteinfo visiteinfo = new Visiteinfo();
		visiteinfo.setDid(did);	
		visiteinfo.setGameid(Integer.parseInt(gameId));
		visiteinfo.setIp(ip);
		visiteinfo.setLocation(locationid);
		visiteinfo.setTelephone(phnum);
		visiteinfo.setTitleid(gameInfo.getKindid());
		visiteinfoService.save(visiteinfo);
		//*********访问统计end***********************/
		
		request.setAttribute("location",location);
		request.setAttribute("pageid",pageid);
		request.setAttribute("did",did);
		request.setAttribute("country",country);

		if("2".equals(pageid)){
			return mapping.findForward("gameinfoWap2");
		}else if("3".equals(pageid)){
			return mapping.findForward("gameinfoWap3");
		}else{
			return mapping.findForward("gameinfoWap1");
		}
	}
	//wap页面调用
	public ActionForward download(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		 String pagename="javaUrl";
		 String did = request.getParameter("did");
		 int pageid = Integer.parseInt(request.getParameter("pageid"));
		 //int proviceid = Integer.parseInt(request.getParameter("proviceid"));
		String gameId = request.getParameter("gameId");
		String location = request.getParameter("location");
		String country = request.getParameter("country");
		int locationid=0;
		if(location!=null&&!"".equals(location)&&!"null".equals(location))locationid=Integer.parseInt(location);
		//HttpSession session = request.getSession();
//		Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
		
		//获取游戏资源信息，取得下载信息
		Map map = new HashMap();
		map.put("gameId", gameId);
		//map.put("proviceid", proviceid);
		map.put("did", did);
		map.put("country", country);
		Gameresouce gameresouce = gameresouceService.queryGameresouce(map);
		Gameinfo gameinfo = gameinfoService.queryGameinfo(gameresouce.getGameid());
		
	
		///////////////////下载统计
		//保存下载信息
		Downloadinfo downloadinfo = new Downloadinfo();
//		if(customer!=null){
//			downloadinfo.setCustomerid(customer.getId());
//		}
		downloadinfo.setDid(did);
		downloadinfo.setDtime(new Date());
		downloadinfo.setGameid(Integer.parseInt(gameId));
		String ip=Util.getIp(request);
		String phnum =Util.getPhone(request);
		downloadinfo.setIp(ip);
		downloadinfo.setLocation(locationid);
		downloadinfo.setTitleid(gameinfo.getKindid());
		downloadinfo.setTelephone(phnum);
		downloadinfoService.save(downloadinfo);
		//////////////////下载统计结束
		request.setAttribute("type",gameresouce.getResourcetype());
		if(gameresouce.getResourcetype()==0){
			//下载
			//获取文件路径和文件名
			String filePath = "game/"+gameId+"/"+did+"/"+gameresouce.getCountryid()+"/";
			//下载文件
			String fileName = gameresouce.getJarfile();
			String fileName1 = gameresouce.getJadfile();
			//if(fileName1!=null&&!"".equals(fileName1)&&!"null".equals(fileName1))fileName=fileName1;
			////////////////////////////////
			fileName = URLDecoder.decode(fileName,"UTF-8");
			fileName = URLEncoder.encode(fileName, "UTF-8");
			fileName = filePath+fileName;
			request.setAttribute("javaPath",fileName);
		}else{
			request.setAttribute("url", gameresouce.getUrl());
		}
		
//		response.setContentType("application/txt"); 
//		response.addHeader("Content-Disposition", "attachment; filename=" + fileName);
//		//获取文件输入流和输出流
//		InputStream is = new BufferedInputStream(new FileInputStream(filePath+"\\"+fileName));
//		OutputStream os = new BufferedOutputStream(response.getOutputStream());
//		int bufferSize = 1024*8;
//		byte[] buffer = new byte[bufferSize];
//		int len = 0;
//		while((len = is.read(buffer, 0, bufferSize))!=-1){
//			os.write(buffer, 0, len);
//		}
//		is.close();
//		os.close();	
		//System.out.println("javaPath="+fileName);
		
		return mapping.findForward(pagename);
	}
	public ActionForward chooseLanguage(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String language = request.getParameter("language");
		String did = request.getParameter("did");
		if(language.equals("zh-CN")){
			request.getSession().setAttribute(Globals.LOCALE_KEY, Locale.CHINA);
		}else if(language.equals("en")){
			request.getSession().setAttribute(Globals.LOCALE_KEY, Locale.ENGLISH);
		}else{
			request.getSession().setAttribute(Globals.LOCALE_KEY, Locale.ENGLISH);
		}
		//此标志用来判断是否手动切换了语言环境
		request.getSession().setAttribute("language", "true");
		request.setAttribute("did", did);
		return mapping.findForward("chooseLanguage");
	}
	
	public ActionForward help(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		return mapping.findForward("help");
	}
	
	//////////////////////
	//手机用户搜索游戏列表
//	public ActionForward findlist(ActionMapping mapping, ActionForm form,
//			HttpServletRequest request, HttpServletResponse response)
//			throws Exception {
//		
//		String content = request.getParameter("content");
//
//	    //通过session得到did,pageid	
//	    HttpSession   session=request.getSession(false); 
//	    String did = (String) session.getAttribute(Constants.DID_VALUE);
//	    int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
//	    String pagn=request.getParameter("pagenum");
//	    Integer proviceid =  (Integer) session.getAttribute(Constants.PROVICEID_VALUE);
//        String ip=Util.getIp(request);
//        String phnum =Util.getPhone(request);
//        String pagename="listWap1";
//        String kindName="游戏搜索";
//        int checkNextPage=0;
//        
//        Map map = new HashMap(5);
//        int pagenum=1;//TODO
//        if(pagn!=null&&!"".equals(pagn)&&!"null".equals(pagn))pagenum=Integer.parseInt(pagn);
//		int start = (pagenum-1) * Constants.PAGESIZE;
//		int end = Constants.PAGESIZE;
//		map.put("start",start);
//		map.put("end", end);
//		map.put("did", did);
//		map.put("content",content);
//		map.put("provinceid",proviceid);
//		
//		int numCount = gameinfoService.findGMCount(map);//总数
//	    if((pagenum+1)*Constants.PAGESIZE<numCount)checkNextPage=1;
//		List<Gameinfo> list = gameinfoService.findGM(map);
//		request.setAttribute("list",list);
//		request.setAttribute("content",content);
//		request.setAttribute("pagenum", pagenum);
//		request.setAttribute("checkNextPage",checkNextPage);
//		request.setAttribute("gamenum",Constants.PAGESIZE);
//		request.setAttribute("kindName",kindName);
//		request.setAttribute("numCount",numCount);
//		request.setAttribute("bzhi",1);
//		switch(pageid){
//			  case 2:pagename="listWap2";
//			       break;
//			  case 3:pagename="listWap3";
//			       break;
//			  default:pagename="listWap1";
//			      break;		  
//			 }
//			  
//			//*********访问统计***********************//		
//				Visiteinfo visiteinfo = new Visiteinfo();
//				visiteinfo.setDid(did);	
//				visiteinfo.setGameid(0);
//				visiteinfo.setIp(ip);
//				visiteinfo.setLocation(0);
//				visiteinfo.setTelephone(phnum);
//				visiteinfo.setTitleid(0);
//				visiteinfoService.save(visiteinfo);
//				//*********访问统计end***********************/
//			return mapping.findForward(pagename);
//	}
//	//手机用户最新游戏列表
//	public ActionForward newlist(ActionMapping mapping, ActionForm form,
//			HttpServletRequest request, HttpServletResponse response)
//			throws Exception {
//
//	    //通过session得到did,pageid	
//	    HttpSession   session=request.getSession(false); 
//	    String did = (String) session.getAttribute(Constants.DID_VALUE);
//	    int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
//	    String pagn=request.getParameter("pagenum");
//	    Integer proviceid =  (Integer) session.getAttribute(Constants.PROVICEID_VALUE);
//        String ip=Util.getIp(request);
//        String phnum =Util.getPhone(request);
//        String pagename="listWap1";
//        String kindName="最新上线游戏";
//        int checkNextPage=0;
//        
//        Map map = new HashMap(5);
//        int pagenum=1;//TODO
//        if(pagn!=null&&!"".equals(pagn)&&!"null".equals(pagn))pagenum=Integer.parseInt(pagn);
//		int start = (pagenum-1) * Constants.PAGESIZE;
//		int end = Constants.PAGESIZE;
//		map.put("start",start);
//		map.put("end", end);
//		map.put("did", did);
//		map.put("provinceid",proviceid);
//		
//		int numCount = gameinfoService.newGMCount(map);//总数
//	    if((pagenum+1)*Constants.PAGESIZE<numCount)checkNextPage=1;
//		List<Gameinfo> list = gameinfoService.newGM(map);
//		request.setAttribute("list",list);
//		request.setAttribute("pagenum", pagenum);
//		request.setAttribute("checkNextPage",checkNextPage);
//		request.setAttribute("gamenum",Constants.PAGESIZE);
//		request.setAttribute("kindName",kindName);
//		request.setAttribute("numCount",numCount);
//		request.setAttribute("bzhi",2);
//		switch(pageid){
//			  case 2:pagename="listWap2";
//			       break;
//			  case 3:pagename="listWap3";
//			       break;
//			  default:pagename="listWap1";
//			      break;		  
//			 }
//			  
//			//*********访问统计***********************//		
//				Visiteinfo visiteinfo = new Visiteinfo();
//				visiteinfo.setDid(did);	
//				visiteinfo.setGameid(0);
//				visiteinfo.setIp(ip);
//				visiteinfo.setLocation(0);
//				visiteinfo.setTelephone(phnum);
//				visiteinfo.setTitleid(0);
//				visiteinfoService.save(visiteinfo);
//				//*********访问统计end***********************/
//			return mapping.findForward(pagename);
//	}
}
