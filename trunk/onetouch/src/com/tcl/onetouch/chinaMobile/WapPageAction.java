package com.tcl.onetouch.chinaMobile;

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

import com.tcl.onetouch.domain.Gameinfo;
import com.tcl.onetouch.service.GameinfoService;
import com.tcl.onetouch.util.Constants;


/**
 * 根据机型展开界面
 * 为了将机型进行区分，需要建一个游戏和did对于的中间表。
 * 页面访问时，首先根据did获取游戏的id，然后在游戏界面里面获取游戏的详细信息。
 * @author kun.shen
 *
 */
public class WapPageAction extends DispatchAction{
	
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
		List<Gameinfo> list =null;
		//
		if(content!=null&&!"".equals(content)&&!"null".equals(content)){
			numCount = gameinfoService.findGameinfoByContentCount(map);//findGMCount(map);//总数
			list = gameinfoService.findGameinfoByContent(map);//findGM(map);
			//kindName="游戏搜索";
		}else {
			numCount = gameinfoService.findNewGameCount(map);//newGMCount(map);
			list = gameinfoService.findNewGame(map);//newGM(map);
			//kindName="最新上线游戏";
		}
		////////////////////////////////////////////////////////////
		
	    if((pagenum+1)*Constants.PAGESIZE<numCount) checkNextPage=1;
	    
	    request.setAttribute("did", did);
	    request.setAttribute("pageid", pageid);
		request.setAttribute("list",list);
		request.setAttribute("pagenum", pagenum);
		request.setAttribute("checkNextPage",checkNextPage);
		request.setAttribute("gamenum",Constants.PAGESIZE);
		request.setAttribute("numCount",numCount);
		if("2".equals(pageid)){
			pagename = "listWap2";
		}else if("3".equals(pageid)){
			pagename = "listWap3";
		}else{
			pagename="listWap1";
		}
		return mapping.findForward(pagename);
	}
}
