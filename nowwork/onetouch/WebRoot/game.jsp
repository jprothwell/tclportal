<%
	String serviceId = request.getParameter("serviceId");
	String channelId = request.getParameter("channelId");
	String key = request.getParameter("key");
	String userUA = request.getParameter("userUA");
	String cpId = request.getParameter("cpId");
	String chInfo = request.getParameter("chInfo");
	String userId = request.getParameter("userId");
	//response.sendRedirect("index.do?action=index&did="+did);
	//china mobile game
	response.sendRedirect("mobileGame.do?action=getGameinfo&serviceId="+serviceId+"&channelId="+channelId
		+"&key="+key+"&userUA="+userUA+"&cpId="+cpId+"&chInfo="+chInfo+"&userId="+userId);
%>