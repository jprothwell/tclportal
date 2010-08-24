package com.tcl.portal.filter;

import java.io.IOException;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.tcl.portal.domain.User;
import com.tcl.portal.util.Constants;


public class SessionFilter implements Filter{

	
	public void destroy() {
		// TODO Auto-generated method stub
		
	}

	
	public void doFilter(ServletRequest request, ServletResponse response,
			FilterChain chain) throws IOException, ServletException {
		HttpServletRequest req = (HttpServletRequest)request;
		HttpServletResponse resp = (HttpServletResponse)response;
		
		HttpSession session = req.getSession();
		User cbuser = (User)session.getAttribute(Constants.SESSION_USER);
		
		if(cbuser==null){
			if(req.getServletPath().equals(Constants.LOGIN_ACTION)){				
				chain.doFilter(req, resp);
			} else {
				resp.sendRedirect(req.getContextPath() + Constants.LOGIN_FAILE);
			}
		} else {
			if(req.getServletPath().equals(Constants.LOGIN_ACTION)){				
				chain.doFilter(req, resp);
			}else{
				boolean bool = false;
				String[] strs = ((String)session.getAttribute(Constants.AUTHORIZE)).split(","); 
				for(String path:strs){
					if(req.getServletPath().equals(path)){
						bool = true;
					}
				}
				if(bool){
					chain.doFilter(request, response);
				}else{
					//chain.doFilter(request, response);
					resp.sendRedirect(req.getContextPath() + Constants.LOGIN_FAILE);
				}
			}
			
		}
		
	}

	
	public void init(FilterConfig arg0) throws ServletException {
		// TODO Auto-generated method stub
		
	}

}