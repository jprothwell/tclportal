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
			<td width="25%" class="td_edittitle" align="center">Creater</td>
			<td width="75%" class="td_editcontent"><xsl:value-of select="createstaff" /></td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">Create Time</td>
			<td width="75%" class="td_editcontent"><xsl:value-of select="createtime" /></td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">Level</td>
			<td width="75%" class="td_editcontent"><xsl:value-of select="implevel" /></td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">Subject</td>
			<td width="75%" class="td_editcontent"><xsl:value-of select="subject" /></td>
		</tr>
		<tr>
			<td width="25%" class="td_edittitle" align="center">Content</td>
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
			<td width="25%" class="td_edittitle" align="center">Attachment</td>
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
									Update
								</a>
							</td>
						</tr>
					</xsl:for-each>
				</table>
			</td>
		</tr>
		<tr>
			<td class="td_editbutton" align="center" colspan="2">
				<input type="button"  value="Next Step" onclick="setHandleList();" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';"></input>　
			</td>
		</tr>
	</xsl:template>
</xsl:stylesheet>
