<%@ page contentType="text/vnd.wap.wml;charset=UTF-8" %>
<div class="title"> 
   【<a href="index.do?action=menulist&amp;kindid=5&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">角色</a>】
   【<a href="index.do?action=menulist&amp;kindid=6&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">动作</a>】
   【<a href="index.do?action=menulist&amp;kindid=7&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">益智</a>】<br/>
   【<a href="index.do?action=menulist&amp;kindid=8&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">策略</a>】
   【<a href="index.do?action=menulist&amp;kindid=9&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">休闲</a>】
   【<a href="index.do?action=menulist&amp;kindid=10&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">养成</a>】<br/>
   【<a href="index.do?action=menulist&amp;kindid=11&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">射击</a>】
   【<a href="index.do?action=menulist&amp;kindid=12&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">棋牌</a>】
   【<a href="index.do?action=menulist&amp;kindid=13&amp;did=${did}&amp;pageid=${pageid}&amp;proviceid=${proviceid}">其他</a>】<br/>
  <form name="comment" action="index.do?action=menulist" method="post">
  <input name="searchName" type="text" size="6" maxlength="255" emptyok="true" value=""/>
   <input name="did" type="hidden" value="${did}"/>
   <input name="pageid" type="hidden" value="${pageid}"/>
   <input name="proviceid" type="hidden" value="${proviceid}"/>
  <input type="submit" value="搜游戏"/>
</form>
</div>