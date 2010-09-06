package com.tcl.gamePortal.action;

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
import com.tcl.gamePortal.domain.Gameinfo;
import com.tcl.gamePortal.service.CommentService;
import com.tcl.gamePortal.service.GameinfoService;
import com.tcl.gamePortal.util.Constants;

public class GameinfoAction  extends DispatchAction{
	
	public Logger logger = Logger.getLogger(GameinfoAction.class);
	
	private GameinfoService gameinfoService;
	
	private CommentService commentService;
	
	public void setCommentService(CommentService commentService) {
		this.commentService = commentService;
	}
	public void setGameinfoService(GameinfoService gameinfoService) {
		this.gameinfoService = gameinfoService;
	}
	public ActionForward queryGameinfo(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		//游戏id
		String gameId = request.getParameter("gameId");
		HttpSession session = request.getSession();
		int pageid =  (Integer) session.getAttribute(Constants.PAGEID_VALUE);
		String did = (String) session.getAttribute(Constants.DID_VALUE);
		int proviceid =  (Integer) session.getAttribute(Constants.PROVICEID_VALUE);
		//获取游戏简介
		Gameinfo gameInfo = gameinfoService.queryGameinfo(Integer.parseInt(gameId));
		request.setAttribute("obj", gameInfo);
		
		//获取游戏评论
		List<Comment> list = commentService.findCommentById(Integer.parseInt(gameId));
		request.setAttribute("list", list);
		request.setAttribute("listSize", list.size());
		if(pageid==2){
			return mapping.findForward("gameinfoWap2");
		}else if(pageid==3){
			return mapping.findForward("gameinfoWap3");
		}else{
			return mapping.findForward("gameinfoWap1");
		}
	}
}
