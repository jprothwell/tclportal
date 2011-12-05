<%
	String userUA = request.getParameter("userUA");
	String chInfo = request.getParameter("chInfo");
	//response.sendRedirect("index.do?action=index&did="+did);
	//china mobile game
	//response.sendRedirect("mobileGame.do?action=getUA&userUA="+userUA+"&chInfo="+chInfo);
	response.sendRedirect("mobileGame.do?action=checkInfo&userUA="+userUA+"&chInfo="+chInfo);
%>