package com.tcl.gamePortal.action;

import java.util.Date;
import java.util.List;

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
		int locationid=0;
		if(location!=null&&!"".equals(location)&&!"null".equals(location))locationid=Integer.parseInt(location);
		HttpSession session = request.getSession();
		int	pageid = (Integer) session.getAttribute(Constants.PAGEID_VALUE);
		String did = (String) session.getAttribute(Constants.DID_VALUE);
		int proviceid =  (Integer) session.getAttribute(Constants.PROVICEID_VALUE);
		String phnum =Util.getPhone(request);
		String ip=Util.getIp(request);
		//获取游戏简介
		Gameinfo gameInfo = gameinfoService.queryGameinfo(Integer.parseInt(gameId));
		request.setAttribute("obj", gameInfo);
		//request.setAttribute("imgName", "game/"+gameInfo.getId()+"/"+did+"/"+gameInfo.getImagename());
		
		//获取游戏评论
		List<Comment> list = commentService.findCommentById(Integer.parseInt(gameId));
		request.setAttribute("list", list);
		int numCount = commentService.findCommentCount(Integer.parseInt(gameId));
		request.setAttribute("numCount",numCount);
		request.setAttribute("location",location);
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
