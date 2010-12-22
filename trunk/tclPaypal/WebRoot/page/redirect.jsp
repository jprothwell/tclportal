<%
	String token = request.getParameter("token");
	String path =request.getContextPath();
	response.sendRedirect(path+"/business.do?action=confirm&token="+token);
%>
