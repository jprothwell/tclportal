<?xml version="1.0" encoding="UTF-8"?>
<%@ page contentType="text/vnd.wap.wml"%>
<%@ page import="java.util.*,cn.alcatel.wap.db.*" %>
<%@ page import="java.util.*,cn.alcatel.wap.db.dao.*" %>
<%
response.setContentType("text/vnd.wap.wml; charset=UTF-8");
Messages messages = (Messages)request.getAttribute(Messages.Id);
String groupid = (String)request.getAttribute("groupid");
String number = (String)request.getAttribute("number");
String lg = (String)request.getAttribute("lg");
String did = (String)request.getParameter("did");
String id = (String)request.getAttribute("id");
String fid = (String)request.getAttribute("fid");
%>
<!DOCTYPE wml PUBLIC "-//WAPFORUM//DTD WML 1.1//EN" "http://www.wapforum.org/DTD/wml_1.1.xml">

<wml>
  <head>
    <meta forua="true" http-equiv="Pragma" content="no-cache"/>
    <meta forua="true" http-equiv="Expires" content="0"/>
    <meta forua="true" http-equiv="Cache-Control" content="no-cache"/>
  </head>
  <template>
    <do type="prev" label="<%=messages.getBack()%>">
      <prev/>
    </do>
  </template>
<%
if(fid!=null && fid.length()>0){
 resourceDao dao= new resourceDao();
DBMap[] map=dao.newsInfo(Integer.parseInt(fid));
%>
<card id="card1" title="<%=map[0].get("name")%>">
<p>
<%
if(map!=null){
  //////////////////////////////////////////
  out.print(map[0].get("name"));
  out.println("<br/>-------------<br/>");
  if(map[0].get("images")!=null && map[0].get("images").toString().length()>0)out.println("<img  src='objectsdw/news/images/"+map[0].get("images")+"' /><br/>");
   out.println(dao.display_convert(map[0].get("info").toString()));
   out.println("<br/>-------------<br/>");
   out.println("<do type='prev' label='"+messages.getBack()+"'><prev/></do>");
////////////////////////////////
  }else{
    out.print("Sorry ,No Data...<br/>");
    out.println("-------------<br/>");
   out.println("<anchor><go href='main?lg="+lg+"&amp;did="+did+"'/>&gt;");
   out.println(messages.getBack());
   out.println("</anchor>");
    }
%>
</p>
</card>
<%
}else{
   out.print("<card id='card1' title='My-onetouch'><p>");
   out.print("Sorry ,No Data...<br/>");
   out.println("-------------<br/>");
   out.println("<anchor><go href='main?lg="+lg+"&amp;did="+did+"'/>&gt;");
   out.println(messages.getBack());
   out.println("</anchor>");
   out.println("</p></card>");
  }
%>
</wml>
