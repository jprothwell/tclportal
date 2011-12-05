package com.tcl.onetouch.chinaMobile;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.onetouch.action.AdAction;
import com.tcl.onetouch.domain.Gameinfo;
import com.tcl.onetouch.domain.MobileGame;
import com.tcl.onetouch.service.GameinfoService;
import com.tcl.onetouch.util.Constants;
import com.tcl.onetouch.util.Dom4jProxy;
import com.tcl.onetouch.util.HttpClientProxy;
import com.tcl.onetouch.util.TemplateConfiguration;


/**
 * 根据机型展开界面
 * 为了将机型进行区分，需要建一个游戏和did对于的中间表。
 * 页面访问时，首先根据did获取游戏的id，然后在游戏界面里面获取游戏的详细信息。
 * @author kun.shen
 *
 */
public class WapPageAction extends DispatchAction{
	
	private String UA = "Alcatel-OT-800";
	
	public Logger logger = Logger.getLogger(WapPageAction.class);
	
	private GameinfoService gameinfoService;
	
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}


	//手机用户进入游戏列表
	public ActionForward gameList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
	    String content = request.getParameter("content");//搜索内容
	    String did = request.getParameter("did");
	    String pageid = request.getParameter("pageid");
	    String pagn = request.getParameter("pagenum");
	    int numCount=0;
	 
        String pagename = "listWap1";
       
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
		map.put("content",content);
		//获取游戏，机型对照表中的所有数据
		List<MobileGame> mobileGames = gameinfoService.findMobileGameByDid(did);
		List<Gameinfo> showGame = new ArrayList<Gameinfo>();//显示的game
		for(MobileGame mobileGame:mobileGames){
			Gameinfo gameinfo = gameinfoService.queryGameinfoNoCache(mobileGame.getGameId());
			showGame.add(gameinfo);
		}
		numCount = showGame.size();
//		List<Gameinfo> list =null;
//		//
//		if(content!=null&&!"".equals(content)&&!"null".equals(content)){
//			numCount = gameinfoService.findGameinfoByContentCount(map);//findGMCount(map);//总数
//			list = gameinfoService.findGameinfoByContent(map);//findGM(map);
//			//kindName="游戏搜索";
//		}else {
//			numCount = gameinfoService.findNewGameCount(map);//newGMCount(map);
//			list = gameinfoService.findNewGame(map);//newGM(map);
//			//kindName="最新上线游戏";
//		}
		////////////////////////////////////////////////////////////
		
	    if((pagenum+1)*Constants.PAGESIZE<numCount) checkNextPage=1;
	    
	    request.setAttribute("did", did);
		request.setAttribute("list",showGame);
		request.setAttribute("pagenum", pagenum);
		request.setAttribute("checkNextPage",checkNextPage);
		request.setAttribute("gamenum",Constants.PAGESIZE);
		request.setAttribute("numCount",numCount);
//		if("2".equals(pageid)){
//			pagename = "listWap2";
//		}else if("3".equals(pageid)){
//			pagename = "listWap3";
//		}else{
//			pagename="listWap1";
//		}
		return mapping.findForward("listPage");
	}
	
	//获取单个游戏
	public ActionForward gameinfo(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String id = request.getParameter("gameId");
//		Gameinfo gameinfo = gameinfoService.queryGameinfoNoCache(Integer.parseInt(id));
//		request.setAttribute("obj", gameinfo);
		//===========
//		String path = request.getSession().getServletContext().getRealPath("/WEB-INF/htmlTemplate");
//		Map param = new HashMap();
//		param.put("userName", "tcl");
//		param.put("pwd", "abcd1234");
//		param.put("channelCode", "10010000");
//		param.put("insertType", "00");
//		String xmlString = TemplateConfiguration.getTemplateContextOutString(param,path,"/validateInsert.ftl");
//		//接入接口
//		String returnXml = HttpClientProxy.postMethodXML("http://gmpbeta.g188.net/channelSyscment/validateInsert",xmlString);
//		Map map = Dom4jProxy.parseXml(returnXml);
//		String tokenPwd = (String)map.get("tokenPwd");
//		String channelCode = (String)map.get("channelCode");
//		//业务鉴权接口
//		String url = "http://gmpbeta.g188.net/channelSyscment/serviceValidate?serviceType=1" +
//				"&channelcode=" +channelCode+
//				"&tokenPwd=" +tokenPwd+
//				"&gameId=110223972000";
//		log.info("gameinfo:::::"+url);
//		response.sendRedirect(url);

	//=============================
//		String returnURL = HttpClientProxy.getMethodNoRedirect(url);
//		request.setAttribute("url", url);
//		request.setAttribute("statu", returnURL);
		//获取UA接口
		response.sendRedirect("http://gmpbeta.g188.net/channelSyscment/GetUAServlet?channelId=10010000");
		return null;
		//return mapping.findForward("result");
		//return mapping.findForward("gameinfo");
	}
	public ActionForward checkInfo(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String userUA = request.getParameter("userUA");
		String chInfo = request.getParameter("chInfo");
		logger.info("userUA:"+userUA+",chInfo:"+chInfo);
		
		String path = request.getSession().getServletContext().getRealPath("/WEB-INF/htmlTemplate");
		Map param = new HashMap();
		param.put("userName", "tcl");
		param.put("pwd", "abcd1234");
		param.put("channelCode", "10010000");
		param.put("insertType", "00");
		String xmlString = TemplateConfiguration.getTemplateContextOutString(param,path,"/validateInsert.ftl");
		//接入接口
		String returnXml = HttpClientProxy.postMethodXML("http://gmpbeta.g188.net/channelSyscment/validateInsert",xmlString);
		Map map = Dom4jProxy.parseXml(returnXml);
		String tokenPwd = (String)map.get("tokenPwd");
		String channelCode = (String)map.get("channelCode");
		//业务鉴权接口
		String url = "http://gmpbeta.g188.net/channelSyscment/serviceValidate?serviceType=1" +
				"&channelcode=" +channelCode+
				"&tokenPwd=" +tokenPwd+
				"&gameId=110223972000";
		log.info("gameinfo:::::"+url);
		response.sendRedirect(url);
		return null;
	}
	/**
	 * 获取UA的接口
	 * @param mapping
	 * @param form
	 * @param request
	 * @param response
	 * @return
	 * @throws Exception
	 */
	public ActionForward getUA(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String userUA = request.getParameter("userUA");
		String chInfo = request.getParameter("chInfo");
		
		logger.info("userUA:"+userUA+",chInfo:"+chInfo);
		
		request.setAttribute("userUA", userUA);
		request.setAttribute("chInfo", chInfo);
		return mapping.findForward("result");
	}
	
	//获取单个游戏
	public ActionForward getGameinfo(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String id = request.getParameter("gameId");
		Gameinfo gameinfo = gameinfoService.queryGameinfoNoCache(31);
		request.setAttribute("obj", gameinfo);
		return mapping.findForward("gameinfo");
	}
	
	//下载接口，是由game.jsp跳转过来的，game.jsp已经在移动那边绑定
	public ActionForward download(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		String serviceId = request.getParameter("serviceId");
		String channelId = request.getParameter("channelId");
		String key = request.getParameter("key");
		String userUA = request.getParameter("userUA");
		String cpId = request.getParameter("cpId");
		String chInfo = request.getParameter("chInfo");
		String userId = request.getParameter("userId");
		//cpServiceId是游戏id
		String url = "http://gmpbeta.g188.net/channelSyscment/ServiceDownServletValidate?sender=202&channelId=10010000&cpId=" +cpId
				+"&cpServiceId=110223972000"
				+"&key=" +key
				+"&uaStr="+userUA;
		log.info("download:::::"+url);
		response.sendRedirect(url);
		return null;
	}
}
