<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
				<form method="POST" action="" name="NewForm">
					<xsl:apply-templates select="handle"/>
				</form>
				</table>
			</td>
		</tr>
		</table>   
	</xsl:template>
	<xsl:template match="handle">
		<tr>
			<td height="20" colspan="2">
				<b>请审批	第<xsl:value-of select="seqno" />步：
				<xsl:value-of select="subname" /></b>
			</td>
		</tr>
		<input type="hidden" name="FlowId">
			<xsl:attribute name="value"><xsl:value-of select="flowid" /></xsl:attribute>
		</input>
		<input type="hidden" name="SubId">
			<xsl:attribute name="value"><xsl:value-of select="key" /></xsl:attribute>
		</input>
		<input type="hidden" name="NodeType">
			<xsl:attribute name="value"><xsl:value-of select="nodetype" /></xsl:attribute>
		</input>
		<input type="hidden" name="ReAppoint">
			<xsl:attribute name="value"><xsl:value-of select="trust" /></xsl:attribute>
		</input>
		<tr>
			<td width="25%" class="td_edittitle" align="center">处理结果</td>
			<td  width="75%" class="td_editcontent">
				<xsl:choose>
				<xsl:when test="nodetype='4'">
					<select name="HandleResult">
						<option value="2">完成</option>
					</select>
				</xsl:when>
				<xsl:when test="nodetype='5'">
					<select name="HandleResult">
						<option value="2">完成</option>
					</select>
				</xsl:when>
				<xsl:otherwise>
					<select name="HandleResult">
						<option value="2">同意</option>
						<option value="3">不同意</option>
					</select>
				</xsl:otherwise>
				</xsl:choose>
			</td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">处理意见</td>
			<td width="75%" class="td_editcontent">
				<textarea class="content_textarea" name="HandleOpinion" style="height:50;"></textarea>
			</td>
		</tr>
			<xsl:if test="nodetype='5'">
			<tr>
				<td width="25%" class="td_edittitle" align="center">是否归档</td>
				<td width="75%" class="td_editcontent">
					<select name="Pigeonhole"><option value="0">不归档</option><option value="1">归档</option></select>
				</td>
			</tr>
			<tr>
				<td width="25%" class="td_edittitle" align="center">归档类别名称</td>
				<td width="75%" class="td_editcontent">
					<input class="input_edit" style="width:100%;" type="text" name="DocType" value=""></input>
				</td>
			</tr>
			<tr>
				<td width="25%" class="td_edittitle" align="center">保存位置</td>
				<td width="75%" class="td_editcontent">
					<input class="input_edit" style="width:100%;" type="text" name="StorePosition" value=""></input>
				</td>
			</tr>
		</xsl:if>
		<tr>
			<td class="td_editbutton" align="center" colspan="2">
				<xsl:choose>
					<xsl:when test="app='1'">
						<input type="button"  value="上一步" onclick="doSetHandle1();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';"></input>　
					</xsl:when>
					<xsl:otherwise>
						<input type="button"  value="上一步" onclick="openWF();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';"></input>　
					</xsl:otherwise>
				</xsl:choose>
				<input type="button"  value="提交" onclick="doHandle();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';"></input>　
				<input type="button"  value="取消" onclick="doCancel();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';"></input>
				<xsl:if test="trust='1'">
				　<input type="button"  value="委托" onclick="doTrust();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">
					<xsl:attribute name="onclick">doTrust('<xsl:value-of select="key" />');</xsl:attribute>
					</input>
				</xsl:if>
			</td>
		</tr>
	</xsl:template>
</xsl:stylesheet>
