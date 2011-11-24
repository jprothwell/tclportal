<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<div class="title"> 
  <form name="comment" action="index.do?action=menulist" method="post">
  <input name="searchName" type="text" size="6" maxlength="255" emptyok="true" value=""/>
   <input name="did" type="hidden" value="${did}"/>
   <input name="pageid" type="hidden" value="${pageid}"/>
  <input type="submit" value="搜游戏"/>
</form>
</div>