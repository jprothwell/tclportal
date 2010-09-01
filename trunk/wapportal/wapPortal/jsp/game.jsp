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
String id = (String)request.getAttribute("id");
String number = (String)request.getAttribute("number");
int per_page=new Integer(number).intValue();
String urlName=null;
uamenuDao dao=new uamenuDao();
resourceDao mdao= new resourceDao();
DBMap[] map=dao.menuList(Integer.parseInt(id));
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

<card id="card1" title="<%=map[0].get("name")%>">
<p mode="nowrap">
<%
int total_num=mdao.uagameTotalnum(lg,ua);
int page_num=8;
int total_page=0;
if((total_num % page_num)==0) total_page=total_num/page_num;
else total_page=total_num/page_num+1;
int start_num=(per_page-1)*page_num;
int last_num=per_page-1;
int next_num=per_page+1;
DBMap[]  map1=mdao.uagameList(ua,lg,start_num,page_num);
////////////////////////////////////
if(map1!=null){
for(int i=0;i<map1.length;i++){
  urlName="main?action=yewu&amp;groupid="+groupid;
  urlName=urlName+"&amp;fid="+map1[i].get("fid");
  urlName=urlName+"&amp;lg="+lg;
  urlName=urlName+"&amp;id="+id;
  urlName=urlName+"&amp;did="+did;
  urlName=urlName+"&amp;number="+number;
  out.println("<anchor>");
  out.println("<go href='"+urlName+"'/>&gt;");
  out.println(map1[i].get("name"));
  out.println("</anchor><br/>");
  }
  out.println("-------------<br/>");
 if(per_page<2){
   out.println("<anchor><go href='main?lg="+lg+"&amp;did="+did+"'/>&gt;");
   out.println(messages.getBack());
   out.println("</anchor>");
 }else {
  int per_page1=per_page-1;
   out.println("<anchor>");
   out.println("<go href='main?action=menu&amp;groupid="+groupid+"&amp;number="+per_page1+"&amp;id="+id+"&amp;lg="+lg+"&amp;did="+did+"'/>&gt;");
   out.println(messages.getBack());
   out.println("</anchor>");
 }
 if(per_page<total_page){
  int per_page2=per_page+1;
   out.println("<br/><anchor><go href='main?action=menu&amp;groupid="+groupid+"&amp;number="+per_page2+"&amp;id="+id+"&amp;lg="+lg+"&amp;did="+did+"'/>&gt;");
   out.println(messages.getNext());
   out.println("</anchor>");
 }
////////////////////////////////////
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
</wml>
