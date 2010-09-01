<%@ page contentType="text/vnd.wap.wml;charset=UTF-8"%>
<%@ page import="cn.funstar.wap.search.* " %>
<%@page import="java.net.*"%>
URLEncoder.encode(key,"UTF-8")
<%
  request.setCharacterEncoding("UTF-8");
  String did = request.getParameter("did");
  if(did==null||did.length()==0){
    did="0";
  }
  String key= request.getParameter("k");
  String type=request.getParameter("t");
  String url = "http://wap.vcoon.cn/?did="+did;
  if("ring".equals(type)){
  url="http://pweb.sensky.com/wap/trans.jsp?from=21296&keyword="+URLEncoder.encode(key,"UTF-8")+"&did="+did;
  }else if("video".equals(type)){          url="http://pweb.sensky.com/wap/trans.jsp?from=21295&keyword="+URLEncoder.encode(key,"UTF-8")+"&did="+did;
  }else if("book".equals(type)){
  url="http://pweb.sensky.com/wap/trans.jsp?from=21294&keyword="+URLEncoder.encode(key,"UTF-8")+"&did="+did;
  }else if("pic".equals(type)){
  url="http://wap.chinam.com/nz.jsp?c=180&t=2&s=movie3&dirid=sou&did="+did+"&s2="+URLEncoder.encode(key,"UTF-8");
  }else if("pic".equals(type)){
  url="http://wap.chinam.com/nz.jsp?c=180&t=2&s=movie3&dirid=sou&did="+did+"&s2="+URLEncoder.encode(key,"UTF-8");
  }else if("baidu".equals(type)){
  url="http://wap.baidu.com/baidu?tn=wisewml&rn=5&ie=unicode&cl=2&vit=uni&from=530d&word="+URLEncoder.encode(key,"UTF-8");
  }
  SearchLog log = new SearchLog();
  log.log(key,type,did,url);
  response.sendRedirect(url);
%>
