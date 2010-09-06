package com.tcl.gamePortal.action;

import java.util.Date;

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
import com.tcl.gamePortal.service.CommentService;
import com.tcl.gamePortal.util.Constants;

public class CommentActioin  extends DispatchAction{
	
	public Logger logger = Logger.getLogger(CommentActioin.class);
	
	private CommentService  commentService;
	
	public void setCommentService(CommentService commentService) {
		this.commentService = commentService;
	}

	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String gameId = request.getParameter("gameId");
		String content = request.getParameter("content");
		HttpSession session = request.getSession();
		Customer customer = (Customer)session.getAttribute(Constants.SESSION_CUSTOMER);
		Comment comment = new Comment();
		comment.setGameid(Integer.parseInt(gameId));
		comment.setCtime(new Date());
		comment.setContent(content);
		if(customer!=null){
			comment.setMobileuserid(customer.getId());
		}
		comment.setDisable(0);//默认不显示
		commentService.save(comment);
		return mapping.findForward("save");
	}
}
