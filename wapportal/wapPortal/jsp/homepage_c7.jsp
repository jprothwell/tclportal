<?xml version="1.0" encoding="utf-8"?>
<%@ page contentType="text/vnd.wap.wml"%>
<%@ page import="java.util.*,cn.alcatel.wap.db.*" %>
<%@ page import="java.util.*,cn.alcatel.wap.db.dao.*" %>
<%
response.setContentType("text/vnd.wap.wml; charset=UTF-8");
Messages messages = (Messages)request.getAttribute(Messages.Id);
String groupid = (String)request.getAttribute("groupid");
String lg = (String)request.getAttribute("lg");
String ua = (String)request.getAttribute("ua");
String did = (String)request.getParameter("did");
String urlName=null;
int group_id=0;
uamenuDao dao=new uamenuDao();
DBMap[] map = null;
DBMap[] map1 = null;
 if (groupid==null){
   map=dao.uamenuList(lg,ua);
 }
 else {
   group_id=Integer.parseInt(groupid);
   map=dao.uamenuList(lg,ua,group_id);
 }
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
<card id="card1" title="<%=messages.getTitle()%>">
<p mode="nowrap">
  <img alt="Alcatel Logo.." align="bottom" src="objectspr/images/alcatel_n_0.gif" /><br />
<%
  if(map != null){
    for(int i = 0; i < map.length; i++){
    urlName="action=menu";
  if((Integer.parseInt(map[i].get("rel").toString())==1) && (map[i].get("contentid") != null)){
     String contentid=map[i].get("contentid").toString();
     String[] k=contentid.split(",");
     urlName="action=yewu&amp;fid="+k[0];
    }
%>
<anchor>
      <go href="main?<%=urlName%>&amp;groupid=<%=map[i].get("groupid")%>&amp;number=1&amp;id=<%=map[i].get("menuid")%>&amp;lg=<%=lg%>&amp;did=<%=did%>"/>
        &gt;<%=map[i].get("name")%></anchor>
 <%
if(Integer.parseInt(map[i].get("new_r").toString())==1)out.println("<img src='objectspr/images/new_0.gif' />");
if(Integer.parseInt(map[i].get("new_r").toString())==2) out.println("<img src='objectspr/images/hot_0.gif' />");
out.println("<br/>");
if(Integer.parseInt(map[i].get("menuid").toString())==35 || Integer.parseInt(map[i].get("menuid").toString())==34){
 map1=dao.uagameList(ua,lg);
 if(map1 != null){
 for(int j=0;j<map1.length;j++){
  urlName="main?action=yewu&amp;groupid=3";
  urlName=urlName+"&amp;fid="+map1[j].get("fid");
  urlName=urlName+"&amp;lg="+lg;
  urlName=urlName+"&amp;id="+map1[j].get("id");
  urlName=urlName+"&amp;did="+did;
  urlName=urlName+"&amp;number=1";
  out.println("*<anchor>");
  out.println("<go href='"+urlName+"'/>");
  out.println(map1[j].get("name"));
  out.println("</anchor><br/>");
   }
}
  }
%>
      <%}}%>
</p>
</card>
</wml>
