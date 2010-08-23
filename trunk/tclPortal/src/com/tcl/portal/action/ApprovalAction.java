package com.tcl.portal.action;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.commons.beanutils.BeanUtils;
import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.portal.domain.Approval;
import com.tcl.portal.domain.User;
import com.tcl.portal.form.ApprovalForm;
import com.tcl.portal.service.ApprovalService;
import com.tcl.portal.service.UserService;
import com.tcl.portal.util.Constants;
import com.tcl.portal.util.Pager;
import com.tcl.portal.util.PagerBuilder;

public class ApprovalAction extends DispatchAction{
	
	public Logger logger = Logger.getLogger(ApprovalAction.class);
	
	private ApprovalService approvalService;
	
	private UserService userService;
	
	public void setUserService(UserService userService) {
		this.userService = userService;
	}

	public void setApprovalService(ApprovalService approvalService) {
		this.approvalService = approvalService;
	}

	//列表，查找
	public ActionForward findList(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		//获取用户，根据用户获取审批信息
		HttpSession session = request.getSession();
		User user = (User)session.getAttribute(Constants.SESSION_USER);
		Pager pager = PagerBuilder.build(request);
		Map map = new HashMap();
		int start = (pager.getPageNo()-1) * pager.getPageSize();
		int end = pager.getPageSize();
		map.put("start",start);
		map.put("end", end);
		map.put("roleId", user.getRoleId());
		pager.setEntryCount(approvalService.findCount(map));
		List<Approval> list = approvalService.findList(map);
		for(Approval approval:list){
			approval.setProposerName(userService.queryUser(String.valueOf(approval.getProposer())).getName());
		}
		request.setAttribute("list", list);
		request.setAttribute("roleId", user.getRoleId());
		return mapping.findForward("list");
	}
	
	//增加页面以及初始化数据
	public ActionForward add(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		return mapping.findForward("add");
	}
	//保存
	public ActionForward save(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		HttpSession session = request.getSession();
		User user = (User)session.getAttribute(Constants.SESSION_USER);
		ApprovalForm approvalForm = (ApprovalForm)form;
		Approval approval = new Approval();
		BeanUtils.copyProperties(approval,approvalForm);
		//roleId 1基本 2运营 3主管
		//对应基本状态1为提交，2为初审，3为审批结束
		if(user.getRoleId()==1){
			approval.setStatus(1);
		}
		if(user.getRoleId()==2){
			approval.setStatus(2);
		}
		approval.setProposer(user.getId());
		approvalService.save(approval);
		logger.info("approval save");
		return mapping.findForward("save");
	}
	
	//更新
	public ActionForward update(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		ApprovalForm approvalForm = (ApprovalForm)form;
		Approval approval = new Approval();
		BeanUtils.copyProperties(approval,approvalForm);
		
		approvalService.update(approval);
		logger.info("approval update");
		return mapping.findForward("update");
	}
	//编辑
	public ActionForward edit(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		String tag = request.getParameter("tag");
		Approval approval = approvalService.queryApproval(Integer.parseInt(id));
		ApprovalForm approvalForm = new ApprovalForm();
		BeanUtils.copyProperties(approvalForm,approval);
		request.setAttribute("obj",approvalForm );
		if(tag.equals("1")){
			//修改
			return mapping.findForward("edit");
		}else if(tag.equals("2")){
			//审核
			return mapping.findForward("next");
		}else if(tag.equals("3")){
			//终审
			return mapping.findForward("last");
		}else{
			//查看
			return mapping.findForward("view");
		}
	}
}
