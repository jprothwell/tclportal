<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ page import="cn.funstar.wap.util.*,cn.funstar.wap.action.*" %>
<%
listAction action = new listAction(request);
String did = request.getParameter("did");
String id = request.getParameter("id");
String nid=null;
//*********************
//nid=100 MP3����==========id=56 ���ֳ��� id=59 MP3ר�� id=62 �������� id=64 mp3����
//nid=101 ��Ƶר��=========id=65 ��Ƶ���� id=68 ��Ƶ����
//nid=102 ��������=========id=61 ��������
//nid=103 ͼ���ȷ�=========id=55 ͼ���ȷ�
//nid=104 ��������=========id=57 ��������
//nid=106 �ֻ��=========id=70 �ֻ��
//nid=108 ����Ƶ��=========id=60 ����Ƶ��
//************************//
if(id.equals("56") || id.equals("59") || id.equals("62") || id.equals("64"))nid="100";
else if(id.equals("65") || id.equals("68"))nid="101";
else if(id.equals("61"))nid="102";
else if(id.equals("55"))nid="103";
else if(id.equals("57"))nid="104";
else if(id.equals("70"))nid="106";
else if(id.equals("60"))nid="108";
else nid=id;
String urlName="list.jsp?id="+nid+"&did="+did;
response.sendRedirect(urlName);
action.log();
%>
