<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<jsp:useBean id="mdb" scope="session" class="cn.alcatel.wap.db.dao.mobiledb">
</jsp:useBean>
 <%
String ua_soho    =request.getParameter("ua_soho");
String java_soho  =request.getParameter("java_soho");
String ring_soho  =request.getParameter("ring_soho");
String video_soho =request.getParameter("video_soho");
cn.alcatel.wap.db.DBMap[] mobileinfo=mdb.getList(ua_soho,java_soho,ring_soho,video_soho);
%>
<link href="../../styles/dtree.css" rel="stylesheet" type="text/css" />
<script LANGUAGE="JAVASCRIPT">
function delobject(pid) {
	if (confirm("确定删除")) {
		location="del.jsp?indexid=" + pid;
		return true;
	}
        else{
                return false;
          }

}
function checkFields(){
if((document.listallform.ua_soho.value.length==0)){
	alert("查询ua不能为空！");
	document.listallform.ua_soho.focus();
	return false;
}
}
</script>
<!--处理每页的数据-->
<table width="100%" border="1" align="center" cellpadding="1" cellspacing="1" class="dtree">
  <tr>
    <td colspan="11"><a href="index.jsp">终端信息管理</a> | <a href="add.jsp">终端信息添加</a></td>
  </tr>
  <tr>
    <td colspan="11" align="center">
 <form method="POST" action="listall.jsp" name="listallform" onsubmit="return checkFields()" >
  UA:<input type="text" name="ua_soho" size="10" value="<%=ua_soho%>">
   屏幕大小:<select size="1" name="ring_soho">
  <option value='' name='ring'>选择</option>
<%
int int_ring=99;
if(ring_soho.length()>0)int_ring=Integer.parseInt(ring_soho);
for(int i=0;i<DBInfo.IMAGE_SIZE.length;i++){
if(i==int_ring){
out.println("<option value='"+i+"' name='ring' selected>"+DBInfo.IMAGE_SIZE[i]+"</option>");
}else
out.println("<option value='"+i+"' name='ring'>"+DBInfo.IMAGE_SIZE[i]+"</option>");
}
%>
  </select>
  java:<select size="1" name="java_soho">
  <%
  int int_java=88;
  if(java_soho.length()>0){
    int_java=Integer.parseInt(java_soho);
    if(int_java==1){
    out.println("<option value='' name='java'>选择</option>");
    out.println("<option value='1' name='java' selected>支持</option>");
    out.println("<option value='0' name='java'>不支持</option>");
      }else{
    out.println("<option value='' name='java'>选择</option>");
    out.println("<option value='1' name='java'>支持</option>");
    out.println("<option value='0' name='java' selected>不支持</option>");
        }
  }else {
    out.println("<option value='' name='java' selected>选择</option>");
    out.println("<option value='1' name='java'>支持</option>");
    out.println("<option value='0' name='java'>不支持</option>");
  }
  %>
  </select>
  视频:<select size="1" name="video_soho">
    <option value='' name='video'>选择</option>
    <option value="1000">不支持</option>
   <%
int int_video=99;
if(video_soho.length()>0)int_video=Integer.parseInt(video_soho);
for(int i=0;i<DBInfo.VIDEO_TYPEID.length;i++){
if(i==int_video){
out.println("<option value='"+i+"' name='video' selected>"+DBInfo.VIDEO_TYPEID[i]+"</option>");
}else
out.println("<option value='"+i+"' name='vidio'>"+DBInfo.VIDEO_TYPEID[i]+"</option>");
}
%>
  </select>
  <input type="submit" value="搜索" name="soho">
</form>
    </td>
  </tr>
  <tr>
    <td>ID</td>
    <td>手机名称	</td>
    <td>手机UA</td>
    <td>手机did</td>
    <td>wap版本</td>
    <td>网络信息</td>
    <td>屏幕尺寸</td>
    <td>铃声格式</td>
    <td>视频格式</td>
    <td>支持java</td>
    <td>操作</td>
  </tr>

<%
    if(null!=mobileinfo){
      for(int j=0;j<mobileinfo.length;j++){
    //for(int count=mobileinfo.length;count>0;count--){
%>
   <tr>
    <td><%=mobileinfo[j].get("id")%></td>
    <td><%=mobileinfo[j].get("na")%></td>
    <td><%=mobileinfo[j].get("ua")%></td>
    <td><%=mobileinfo[j].get("did")%></td>
    <td>
<%
         if(null==mobileinfo[j].get("wapinfo")){
           out.print("无信息</td>");
           }
          else{
             int wapinfo = Integer.parseInt(mobileinfo[j].get("wapinfo").toString());
               for(int i=0;i<DBInfo.WAP_INFO.length;i++)
                  if(i==wapinfo)out.println(DBInfo.WAP_INFO[i]);
          }
%>
    </td>
    <td><%
         if(null==mobileinfo[j].get("netinfo")){
             out.print("无信息</td>");
           }
         else{
            int netinfo=Integer.parseInt(mobileinfo[j].get("netinfo").toString());
            for(int i=0;i<DBInfo.NET_INFO.length;i++)
            if(i==netinfo)out.println(DBInfo.NET_INFO[i]);
         }
    %></td>
    <td><%
           if(null==mobileinfo[j].get("screen")){
             out.print("无信息</td>");
           }
         else{
             int screen=Integer.parseInt(mobileinfo[j].get("screen").toString());
             for(int i=0;i<DBInfo.IMAGE_SIZE.length;i++)
             if(i==screen)out.println(DBInfo.IMAGE_SIZE[i]);
         }
        %></td>
    <td>
<%
       if(0==mobileinfo[j].get("ringformat").toString().length()){
             out.print("无信息</td>");
           }
      else{
        String   ringformat=mobileinfo[j].get("ringformat").toString();
        String ring[]=ringformat.split(",");
        int temp;
        int tempi=0;
        int tempcyc=0;
        int ringlen=0;
        for(int i=0;i<DBInfo.RING_TYPEID.length;){
             temp=0;
             tempi=i;
           ringlen=ring.length;
     while(temp<ringlen){
          if(Integer.parseInt(ring[temp])==tempi){
              out.print(DBInfo.RING_TYPEID[i]);
              if(temp<ringlen-1)out.print(",");
              tempcyc=1;
              break;
            }
         temp++;
       }
       i++;
}
      }
%></td>
    <td>
<%
    if(mobileinfo[j].get("videoformat").toString().equals("888")){
             out.print("不支持</td>");
           }
      else{
        String   videoformat=mobileinfo[j].get("videoformat").toString();
        String video[]=videoformat.split(",");
        int tempvideo;
        int tempivideo=0;
        int tempcycvideo=0;
        int videolen=0;
        for(int i=0;i<DBInfo.VIDEO_TYPEID.length;){
             tempvideo=0;
             tempivideo=i;
           videolen=video.length;
     while(tempvideo<videolen){
          if(Integer.parseInt(video[tempvideo])==tempivideo){
              out.print(DBInfo.VIDEO_TYPEID[i]);
              if(tempvideo<videolen-1)out.print(",");
              tempcycvideo=1;
              break;
            }
         tempvideo++;
       }
       i++;
}
 }
%></td>
    <td>
<%
    if(null==mobileinfo[j].get("javasupport")){
       out.print("无信息</td>");
      }
   else{
    int javasupport=Integer.parseInt(mobileinfo[j].get("javasupport").toString());
    if(javasupport==1){
      out.print("支持java");
    }
    else{
      out.print("不支持java");
      }
   }
  %></td>
    <td>
      <a href="edit.jsp?indexid=<%=mobileinfo[j].get("id")%>">修改</a>|
      <a href="del.jsp?indexid=<%=mobileinfo[j].get("id")%>" onclick="return delobject('indexid')">删除</a>
      </td>
  </tr>
<%
 }
    }else{
   out.print("<tr><td colspan='11' align='center'>没有此查询数据</td></tr>");
      }
%>
</table>
