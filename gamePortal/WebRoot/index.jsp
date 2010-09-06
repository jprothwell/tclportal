<%
	String did = request.getParameter("did");
	response.sendRedirect("visit.do?action=visitHomePage&did="+did);
%>