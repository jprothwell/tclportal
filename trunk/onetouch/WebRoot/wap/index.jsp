<%
	String did = request.getParameter("did");
	response.sendRedirect("index.do?action=index&did="+did);
%>