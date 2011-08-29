<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table id="tb_new" class="table_edit" cellpadding="0" cellspacing="0" align="center">
		<tr>
			<td>
				<table class="table_detaillist" cellpadding="0" cellspacing="1" align="center">
					<xsl:apply-templates select="type"/>
					<xsl:apply-templates select="list"/>
					<xsl:apply-templates select="attachs"/>
					<xsl:apply-templates select="subs"/>
				</table>
			</td>
		</tr>
		</table>   
	</xsl:template>
	<xsl:template match="type">
		<tr>
			<td height="20" colspan="2">
				<b>《<xsl:value-of select="typename"/>》</b>
				<input type="hidden" name="FlowId">
					<xsl:attribute name="value"><xsl:value-of select="flowid" /></xsl:attribute>
				</input>
			</td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">创建人</td>
			<td width="75%" class="td_editcontent"><xsl:value-of select="createstaff" /></td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">创建时间</td>
			<td width="75%" class="td_editcontent"><xsl:value-of select="createtime" /></td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">重要级别</td>
			<td width="75%" class="td_editcontent"><xsl:value-of select="implevel" /></td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">标题</td>
			<td width="75%" class="td_editcontent"><xsl:value-of select="subject" /></td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">内容</td>
			<td width="75%" class="td_editcontent">
				<textarea class="content_textarea" readonly="true" style="width:100%;height:100;background-color:#ece9d8;"><xsl:value-of select="content" /></textarea>
				</td>
		</tr>
	</xsl:template>
	<xsl:template match="list">
		<xsl:for-each select="row">
		<tr>
			<xsl:choose>
			<xsl:when test="datatype='SHORTSTRING'">
				<td width="25%" class="td_edittitle" align="center"><xsl:value-of select="showname" /></td>
				<td width="75%" class="td_editcontent"><xsl:value-of select="fieldvalue" /></td>
			</xsl:when>
			<xsl:when test="datatype='STRING'">
				<td width="25%" class="td_edittitle" align="center"><xsl:value-of select="showname" /></td>
				<td width="75%" class="td_editcontent"><xsl:value-of select="fieldvalue" /></td>
			</xsl:when>
			<xsl:when test="datatype='TEXT'">
				<td width="25%" class="td_edittitle" align="center"><xsl:value-of select="showname" /></td>
				<td width="75%" class="td_editcontent">
					<textarea class="content_textarea" readonly="true" style="height:50;">
						<xsl:value-of select="fieldvalue" />
					</textarea>
				</td>
			</xsl:when>
			<xsl:when test="datatype='DATE'">
				<td width="25%" class="td_edittitle" align="center"><xsl:value-of select="showname" /></td>
				<td width="75%" class="td_editcontent"><xsl:value-of select="fieldvalue" /></td>
			</xsl:when>
			<xsl:when test="datatype='SELECT'">
				<td width="25%" class="td_edittitle" align="center"><xsl:value-of select="showname" /></td>
				<td width="75%" class="td_editcontent"><xsl:value-of select="fieldvalue" /></td>
			</xsl:when>
			<xsl:otherwise>
			</xsl:otherwise>
			</xsl:choose>
		</tr>
		</xsl:for-each>
	</xsl:template>
	<xsl:template match="attachs">
		<tr>
			<td width="25%" class="td_edittitle" align="center">附件</td>
			<td width="75%" class="td_editcontent">
				<table style="width:100%;font-size:9pt;">
					<xsl:for-each select="attach">
						<tr>
							<td>
								<a href="#">
									<xsl:attribute name="onclick">downAttach('<xsl:value-of select="key" />');</xsl:attribute>
									<xsl:value-of select="name" />
								</a>[size:<xsl:value-of select="size" />]　　
								<a href="#">
									<xsl:attribute name="onclick">updateAttach('<xsl:value-of select="key" />');</xsl:attribute>
									修改
								</a>
							</td>
						</tr>
					</xsl:for-each>
				</table>
			</td>
		</tr>
	</xsl:template>
	<xsl:template match="subs">
		<xsl:for-each select="sub">
			<tr>
				<td valign="middle" width="25%" class="td_edittitle" align="center">
				第<xsl:value-of select="seqno" />步<br/>
				<xsl:value-of select="subname" />
				</td>
				<td width="75%" class="td_editcontent">
					<table style="width:100%;font-size:9pt;">
						<tr>
							<td width="25%">处理人</td>
							<td width="75%"><xsl:value-of select="staff" /></td>
						</tr>
						<tr>
							<td>处理结果</td>
							<td><xsl:value-of select="resultname" /></td>
						</tr>
						<tr>
							<td>处理时间</td>
							<td><xsl:value-of select="time" /></td>
						</tr>
						<tr>
							<td>处理意见</td>
							<td>
								<textarea class="content_textarea" readonly="true" style="height:50;background-color:#ece9d8;"><xsl:value-of select="opinion" /></textarea>
							</td>
						</tr>
					</table>
				</td>
			</tr>
		</xsl:for-each>
		<tr>
			<td class="td_editbutton" align="center" colspan="2">
				<xsl:choose>
					<xsl:when test="app='1'">
						<input type="button"  value="下一步" onclick="doSetHandle1();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';"></input>　
					</xsl:when>
					<xsl:otherwise>
						<input type="button"  value="下一步" onclick="showHandle();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';"></input>　
					</xsl:otherwise>
				</xsl:choose>
			</td>
		</tr>
	</xsl:template>
</xsl:stylesheet>
