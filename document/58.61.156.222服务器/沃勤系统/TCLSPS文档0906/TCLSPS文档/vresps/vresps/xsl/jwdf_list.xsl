<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_list" cellspacing="1" cellpadding="0">
			<xsl:apply-templates select="col"/>
			<xsl:apply-templates select="list"/>
			<xsl:apply-templates select="page"/>
		</table>   
	</xsl:template>
	<xsl:template match="page">
		<tr>
			<td class="td_listpage">
				<xsl:attribute name="colspan">
					<xsl:value-of select="colcount" />
				</xsl:attribute>
				<table width="100%" border="0" style="font-size:9pt;">
					<tr>
						<td width="60%">
							<xsl:if test="pagesize>0">
								<xsl:if test="index>1">
									<a href="#"><xsl:attribute name="onclick">openPage('#areaname#','1');return false;</xsl:attribute>首页</a><xsl:text> </xsl:text>
									<a href="#"><xsl:attribute name="onclick">openPage('#areaname#','<xsl:value-of select="front" />');return false;</xsl:attribute>上一页</a><xsl:text> </xsl:text>
								</xsl:if>
								<xsl:if test="pagecount>index">
									<a href="#"><xsl:attribute name="onclick">openPage('#areaname#','<xsl:value-of select="after" />');return false;</xsl:attribute>下一页</a><xsl:text> </xsl:text>
									<a href="#"><xsl:attribute name="onclick">openPage('#areaname#','<xsl:value-of select="pagecount" />');return false;</xsl:attribute>尾页</a>
								</xsl:if>
								<xsl:if test="pagecount>1">
							　跳至<input class="input_edit" style="width:25;" type="text" name="PageIndex" onKeyDown="pageEnterUnsigned();"></input>
							页<input type="button"  value="确认" class="button" onmouseover="this.className='buttonover';"  onmouseout="this.className='button';">
								<xsl:attribute name="onclick">
									openEnterPage('#areaname#',document.all['PageIndex'].value,'<xsl:value-of select="pagecount"/>');
								</xsl:attribute>
							</input>
								</xsl:if>
							</xsl:if>
						</td>
						<td width="40%" align="right">
							共<xsl:value-of select="reccount"/>条记录　第<xsl:value-of select="index"/>/<xsl:value-of select="pagecount"/>页
						</td>
					</tr>
				</table>
			</td>
		</tr>
	</xsl:template>
	<xsl:template match="col">
		<tr>
			<xsl:for-each select="field">
				<td class="td_listtitle">
					<xsl:attribute name="width">
						<xsl:value-of select="./@width" />
					</xsl:attribute>
					<xsl:value-of select="." />
				</td>
			</xsl:for-each>
		</tr>
	</xsl:template>
	<xsl:template match="list">
		<xsl:for-each select="row">
			<tr>
				<xsl:attribute name="id">#areaname#tr<xsl:value-of select="num"/></xsl:attribute>
				<xsl:attribute name="onclick">
					clickRow('#areaname#','<xsl:value-of select="num" />','<xsl:value-of select="key" />');
				</xsl:attribute>
				<xsl:attribute name="ondblclick">
					showDetail('#areaname#','<xsl:value-of select="key" />');
				</xsl:attribute>
				<xsl:attribute name="onContextMenu">
					showPopMenu_List('#areaname#','<xsl:value-of select="num" />','<xsl:value-of select="key" />');return false;
				</xsl:attribute>
				<xsl:for-each select="field">
					<td class="td_listcontent">
						<xsl:choose>
							<xsl:when test="./@align='center'">
								<xsl:attribute name="align">
									<xsl:value-of select="./@align" />
								</xsl:attribute>
							</xsl:when>
							<xsl:when test="./@align='right'">
								<xsl:attribute name="align">
									<xsl:value-of select="./@align" />
								</xsl:attribute>
							</xsl:when>
						</xsl:choose>
						<xsl:value-of select="." />
					</td>
				</xsl:for-each>
			</tr>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
