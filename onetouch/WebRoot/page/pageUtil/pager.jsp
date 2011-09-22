<%@ page contentType="text/html;charset=GBK"%>
<%@ page isELIgnored="false"%>
<%@ taglib uri="http://java.sun.com/jstl/core_rt" prefix="c"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="pagefn"%>
<%@ taglib uri="http://struts.apache.org/tags-html" prefix="html"%>
<script src="<%=request.getContextPath()%>/page/pageUtil/pager.js" type="text/javascript"></script>
<div class="pagination" style="margin: 5px;">
<div id="right-mm2" align="right" style="height: 50px;font-family: ����;font-size: 12px">
 <c:if test="${pagefn:length(pager.pageNumbers)>0}">
 	<c:if test="${pager.pageNo == 1 }">
 	  ��ҳ&nbsp;&nbsp;&nbsp;&nbsp; ��һҳ
    </c:if>
   <c:if test="${pager.pageNo != 1 }">
   	  <a href="javascript:pager.navTo(1);void(0);" class="blue">��ҳ</a>&nbsp;&nbsp;
      <a href="javascript:pager.navTo(${pager.pageNo-1});void(0);" class="blue">��һҳ</a>
   </c:if>
	&nbsp;&nbsp;
    <c:if test="${pager.pageNo == pager.maxPageNo }">
        ��һҳ&nbsp;&nbsp;β ҳ
    </c:if>
     <c:if test="${pager.pageNo != pager.maxPageNo }">
        <a href="javascript:pager.navTo(${pager.pageNo+1});void(0);" class="blue">��һҳ</a>&nbsp;&nbsp;
        <a href="javascript:pager.navTo(${pager.maxPageNo});void(0);" class="blue">βҳ</a>
     </c:if>
     &nbsp;&nbsp;
      <span style="padding: 0;margin: 0;border: 0;">
       ��ת����
      <select onchange="goPage(this)">
         <c:forEach var="i" begin="1" end="${pager.maxPageNo }">
            <option value="${i}" ${pager.pageNo==i?'selected="selected"':'' }>${i}</option>
         </c:forEach>
      </select>
      ҳ <!-- <bean:message key="front.pager.Page" />-->&nbsp;&nbsp;
      </span>
   </c:if> 
   
   <c:if test="${pagefn:length(pager.pageNumbers)<1}">
     <span style="border:1px #999999 solid;color: #999999;"> �޷�������</span>
   </c:if>
   <!--  
      ��&nbsp;<span class="red">${pager.maxPageNo }</span>&nbsp;ҳ&nbsp;<span class="red">${pager.entryCount }</span>&nbsp;��/ÿҳ&nbsp;<span class="red">${pager.pageSize}</span>&nbsp;��
   -->
      <input style="width:20px;" disabled type="hidden" value="${pager.pageSize}" id="sizeEl" />
</div>    
</div>
	<script>
		if(!window.js)
{
	var js = new Object();
}

js.Pager = function(){};

$.extend(js.Pager.prototype,
{
	initialize:function(url,method,sizeEl,pageEl,navBtnEl)
	{
		this.url = url;
		this.method = method || "doPager";
		this.sizeEl = document.getElementById(sizeEl);
		this.pageEl = document.getElementById(pageEl);
		this.navBtnEl = document.getElementById(navBtnEl);
	},
	
	buildUrl:function(page)
	{
		var url = this.url ;
		url += "&action=" + this.method;
		url += "&pageNo=" + page;
		url += "&pageSize=" + this.sizeEl.value ;
		return url;
	},
	
	navTo:function(page)
	{
		page = page || this.pageEl.value;
		var url = this.buildUrl(page)
		window.location = url;
	},
	
	setMethod:function(method)
	{
		this.method = method;
	}
}
);
	</script>
	
	<script>
	var pager = new js.Pager();
	pager.initialize('${pageContext.request.contextPath}${pager.requestUrl}','doPager','sizeEl','pageEl','navBtn');
    function goPage(obj)
    {
      pager.navTo($(obj).val());
    }
	</script>
