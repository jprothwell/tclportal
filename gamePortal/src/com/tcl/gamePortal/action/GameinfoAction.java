package com.tcl.gamePortal.action;

import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.gamePortal.domain.Comment;
import com.tcl.gamePortal.domain.Customer;
import com.tcl.gamePortal.domain.Gameinfo;
import com.tcl.gamePortal.domain.Visiteinfo;
import com.tcl.gamePortal.service.CommentService;
import com.tcl.gamePortal.service.GameinfoService;
import com.tcl.gamePortal.service.VisiteinfoService;
import com.tcl.gamePortal.util.Constants;
import com.tcl.gamePortal.util.Util;

public class GameinfoAction  extends DispatchAction{
	
	public Logger logger = Logger.getLogger(GameinfoAction.class);
	
	private GameinfoService gameinfoService;
	
	private CommentService commentService;
	
	private VisiteinfoService visiteinfoService;
	
	public void setCommentService(CommentService commentService) {
		this.commentService = commentService;
	}
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}
	
	public void setVisiteinfoService(VisiteinfoService visiteinfoService) {
		this.visiteinfoService = visiteinfoService;
	}
	public ActionForward queryGameinfo(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		//游戏id
		String gameId = request.getParameter("gameId");
		String location=request.getParameter("location");
	    String did = request.getParameter("did");
	    int pageid = Integer.parseInt(request.getParameter("pageid"));
	    int proviceid = Integer.parseInt(request.getParameter("proviceid"));
		
		int locationid=0;
		if(location!=null&&!"".equals(location)&&!"null".equals(location))locationid=Integer.parseInt(location);
		HttpSession session = request.getSession();
		String phnum =Util.getPhone(request);
		String ip=Util.getIp(request);
		//获取游戏简介
		Gameinfo gameInfo = gameinfoService.queryGameinfo(Integer.parseInt(gameId));
		request.setAttribute("obj", gameInfo);
		//request.setAttribute("imgName", "game/"+gameInfo.getId()+"/"+did+"/"+gameInfo.getImagename());
		
		//获取游戏评论
		Map map = new HashMap(2);
		map.put("did", did);
		map.put("gameId", gameId);
		List<Comment> list = commentService.findCommentById(map);
		request.setAttribute("list", list);
		int numCount = commentService.findCommentCount(map);
		request.setAttribute("numCount",numCount);
		request.setAttribute("location",location);
		request.setAttribute("did",did);
		request.setAttribute("pageid",pageid);
		request.setAttribute("proviceid",proviceid);
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
		if(pageid==2){
			return mapping.findForward("gameinfoWap2");
		}else if(pageid==3){
			return mapping.findForward("gameinfoWap3");
		}else{
			return mapping.findForward("gameinfoWap1");
		}
	}
}
