<%
	String token = request.getParameter("token");
	String path =request.getContextPath();
	response.sendRedirect(path+"/business.do?action=moblieConfirm&token="+token);
%>
