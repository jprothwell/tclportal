<%@ page contentType="text/html; charset=UTF-8" %>
<%@ include file="../../checksession.jsp"%>
<%@ page import="cn.alcatel.wap.db.DBInfo"%>
<jsp:useBean id="mdb" scope="session" class="cn.alcatel.wap.db.dao.mobiledb">
</jsp:useBean>
 <%
// pageNum存储页数
  int pageNum = 1;
  try {
// 接收url重写参数
       pageNum = Integer.parseInt(request.getParameter("page"));
  }
  catch (Exception ex) {
    pageNum = 1;
  }
  int pagestart = 0;
// 判断是否小于最小页数
  if (pageNum <= 1) {
    pagestart = 0;
    pageNum = 1;
  }
  else {
    pagestart = (pageNum-1) * mdb.pagecnt ;
  }
  int count_0 =mdb.get_pagecnt();
// 获取最大页数
// 判断是否超过最大页数
  if(pageNum >=count_0){
    if(0==count_0){
        pagestart=0;
      }
    else{
      pagestart= (count_0-1)*mdb.pagecnt;
    }
      pageNum = count_0;
  }
// 查询数据
    cn.alcatel.wap.db.DBMap[] mobileinfo=mdb.get_page_info(pagestart);
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
    <td colspan="11">终端信息管理 | <a href="add.jsp">终端信息添加</a></td>
  </tr>
  <tr>
    <td colspan="11" align="center">
 <form method="POST" action="listall.jsp" name="listallform" onsubmit="return checkFields()" >
  UA:<input type="text" name="ua_soho" size="10" value="A">
  屏幕大小:<select size="1" name="ring_soho">
  <option value='' name='ring'>选择</option>
<%
for(int i=0;i<DBInfo.IMAGE_SIZE.length;i++){
if(i==0){
out.println("<option value='"+i+"' name='ring'>"+DBInfo.IMAGE_SIZE[i]+"</option>");
}else
out.println("<option value='"+i+"' name='ring'>"+DBInfo.IMAGE_SIZE[i]+"</option>");
}
%>
  </select>
  java:<select size="1" name="java_soho">
    <option value='' name='java'>选择</option>
    <option value='1' name='java'>支持</option>
    <option value='0' name='java'>不支持</option>
  </select>
  视频:<select size="1" name="video_soho">
    <option value='' name='video'>选择</option>
    <option value="1000">不支持</option>
   <%
for(int i=0;i<DBInfo.VIDEO_TYPEID.length;i++){
if(i==0){
out.println("<option value='"+i+"' name='video'>"+DBInfo.VIDEO_TYPEID[i]+"</option>");
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
    }
%>

 <tr><td align="center" colspan="11">
    共<%=mdb.all_mobile_count()%>条
   <%=pageNum%>/<%=mdb.get_pagecnt()%>页
   <a href="index.jsp?page=0">首页</a>|
   <a href="index.jsp?page=<%=pageNum-1%>">上一页</a>|
   <a href="index.jsp?page=<%=pageNum+1%>">下一页</a>|
   <a href="index.jsp?page=<%=count_0%>">末页</a>
   </td></tr>
</table>
