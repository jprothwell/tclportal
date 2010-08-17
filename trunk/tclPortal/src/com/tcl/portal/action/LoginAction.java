package com.tcl.portal.action;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.log4j.Logger;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;
import org.apache.struts.actions.DispatchAction;

import com.tcl.portal.domain.Resource;
import com.tcl.portal.domain.Role;
import com.tcl.portal.domain.User;
import com.tcl.portal.service.ResourceService;
import com.tcl.portal.service.RoleService;
import com.tcl.portal.service.UserService;
import com.tcl.portal.util.Constants;
import com.tcl.portal.util.MD5;


public class LoginAction extends DispatchAction{
	
//	@Override
//	protected void execute(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//		String userName=request.getParameter("username");
//		String password=request.getParameter("password");
//		
//		System.out.println("username:"+userName+" password:"+password);
//		
//		forward("/page/frame.jsp",request,response);
//	}
	
	public Logger logger = Logger.getLogger(LoginAction.class);
	
	private UserService userService;
	
	private RoleService roleService;
	
	private ResourceService resourceService;
	
	public void setUserService(UserService userService) {
		this.userService = userService;
	}
	
	public void setRoleService(RoleService roleService) {
		this.roleService = roleService;
	}

	public void setResourceService(ResourceService resourceService) {
		this.resourceService = resourceService;
	}

	//用户登录
	public ActionForward login(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String username = request.getParameter("user");
		String password = request.getParameter("pwd");
		User user = userService.getUserByName(username);
		if(user==null){
			request.setAttribute("errorMessage", new String("该用户不存在!"));
			return mapping.findForward("fail");
		}else{
			if(user.getDisabled()!=Constants.USERDISABLE){
				request.setAttribute("errorMessage", new String("该用户无效!"));
				return mapping.findForward("fail");
			}else{
				//有效用户
				if(user.getPassword().equals(MD5.getMd5Value(password))){
					//密码正确
					HttpSession session = request.getSession();
					logger.info("user:"+username+"(longin success)");
					session.setAttribute(Constants.SESSION_USER,user);
					//获取角色信息
					Role role = roleService.queryRole(String.valueOf(user.getRoleId()));
					session.setAttribute("role", role);
					session.setAttribute("roleResources", role.getResources());
					session.setAttribute("roleid", role.getId());
					//获取所有权限
					List<Resource> resources = resourceService.findAll();
					List<Resource> authres = new ArrayList<Resource>();
					String[] strRes = role.getResources().split(":");
					StringBuilder listRes = new StringBuilder();
					for(String res:strRes){
						for(Resource resource:resources){
							if(res.equals(String.valueOf(resource.getId()))){
								authres.add(resource);
								listRes.append(resource.getValue());
								listRes.append(",");
							}
						}
					}
					session.setAttribute("authres", authres);
					session.setAttribute(Constants.AUTHORIZE,listRes.toString());
					return mapping.findForward("login");
				}else{
					logger.info("user:"+username+"(longin fail,password error)");
					request.setAttribute("errorMessage", new String("输入密码不正确!"));
					return mapping.findForward("fail");
				}
			}
			
		}
	}
	//用户退出登录
	public ActionForward logout(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		HttpSession session = request.getSession();
		session.invalidate();
		return mapping.findForward("logout");
		}
	
	public ActionForward updatePassword(ActionMapping mapping, ActionForm form,
			HttpServletRequest request, HttpServletResponse response)
			throws Exception {
		
		String id = request.getParameter("id");
		String password = request.getParameter("password");
		String newPassword = request.getParameter("newPassword");
		User user = userService.queryUser(id);
		String returnInfo = "";
		if(user.getPassword().equals(MD5.getMd5Value(password))){
			user.setPassword(MD5.getMd5Value(newPassword));
			userService.update(user);
			returnInfo = "1";
		}else{
			returnInfo = "2";
		}
		response.setCharacterEncoding("UTF-8");
		response.setContentType("text/html"); 
		PrintWriter out = response.getWriter();
		out.write(returnInfo);
		out.flush();
		return null;
	}
}
