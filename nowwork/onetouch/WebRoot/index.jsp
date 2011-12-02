<%
	String did = request.getParameter("did");
	//response.sendRedirect("index.do?action=index&did="+did);
	//china mobile game
	response.sendRedirect("mobileGame.do?action=gameList&did="+did);
%>