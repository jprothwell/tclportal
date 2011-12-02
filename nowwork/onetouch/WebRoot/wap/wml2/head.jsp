<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<%@ taglib uri="http://struts.apache.org/tags-bean" prefix="bean" %>

<div class="title"> 
<!--  
   【<a href="index.do?action=menulist&amp;kindid=5&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">角色</a>】
   【<a href="index.do?action=menulist&amp;kindid=6&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">动作</a>】
   【<a href="index.do?action=menulist&amp;kindid=7&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">益智</a>】<br/>
   【<a href="index.do?action=menulist&amp;kindid=8&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">策略</a>】
   【<a href="index.do?action=menulist&amp;kindid=9&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">休闲</a>】
   【<a href="index.do?action=menulist&amp;kindid=10&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">养成</a>】<br/>
   【<a href="index.do?action=menulist&amp;kindid=11&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">射击</a>】
   【<a href="index.do?action=menulist&amp;kindid=12&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">棋牌</a>】
   【<a href="index.do?action=menulist&amp;kindid=13&amp;did=${did}&amp;pageid=${pageid}&amp;country=${country}">其他</a>】<br/>
   -->
  <form name="comment" action="index.do?action=menulist" method="post">
  <input name="content" type="text" size="6" maxlength="255" emptyok="true" value=""/>
   <input name="did" type="hidden" value="${did}"/>
   <input name="pageid" type="hidden" value="${pageid}"/>
   <input name="country" type="hidden" value="${country}"/>
  <input type="submit" value="<bean:message key="wap.head.search"/>"/>
</form>
</div>