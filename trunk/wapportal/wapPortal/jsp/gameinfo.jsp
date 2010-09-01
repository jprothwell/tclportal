<?xml version="1.0" encoding="utf-8"?>
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
DBMap[] map=dao.gameInfo(Integer.parseInt(fid));
%>
<card id="card1" title="<%=map[0].get("name")%>">
<p>
<%
if(map!=null){
  //////////////////////////////////////////
  String urlName="main?action=download&amp;groupid="+groupid;
  urlName=urlName+"&amp;spname="+map[0].get("sp_name");
  urlName=urlName+"&amp;resourcename="+map[0].get("name");
  String urlName1=urlName+"&amp;urlname=objectsdw/games/"+lg+"/"+map[0].get("file1");
  String urlName2=urlName+"&amp;urlname=objectsdw/games/"+lg+"/"+map[0].get("file2");
  ////////////////////////////////////////
  if(map[0].get("images")!=null && map[0].get("images").toString().length()>0)out.println("<img  src='objectsdw/games/"+lg+"/view/"+map[0].get("images")+"' /><br/>");
  out.println("<anchor>");
  out.println("<go href='"+urlName2+"'/>");
  out.println("JAD</anchor>");
  out.println("<anchor>");
  out.println("<go href='"+urlName1+"'/>");
  out.println("JAR</anchor><br/>");
  out.println(map[0].get("info"));
  out.println("<br/><anchor>");
  out.println("<go href='"+urlName2+"'/>");
  out.println("JAD</anchor>");
  out.println("<anchor>");
  out.println("<go href='"+urlName1+"'/>");
  out.println("JAR</anchor><br/>");
  out.println("-------------<br/>");
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
