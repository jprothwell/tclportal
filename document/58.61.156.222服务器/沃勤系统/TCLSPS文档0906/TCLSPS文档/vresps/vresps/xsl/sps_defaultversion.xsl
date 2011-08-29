<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_edit" cellspacing="1" cellpadding="0">
			<tr>
				<td width="20" class="td_listtitle"></td>
				<td class="td_listtitle" width="20%">版本编号</td>
				<td class="td_listtitle" width="10%">版本号</td>
				<td class="td_listtitle" width="10%">VRE版本号</td>
				<td class="td_listtitle" width="10%">内存大小</td>
				<td class="td_listtitle" width="10%">屏幕宽</td>
				<td class="td_listtitle" width="10%">屏幕高</td>
				<td class="td_listtitle" width="10%">输入设备</td>
				<td class="td_listtitle" width="20%">文件名</td>
			</tr>
			<xsl:apply-templates select="list"/>
		</table>
	</xsl:template>
	<xsl:template match="list">
		<xsl:for-each select="row">
			<tr>
				<td class="td_listcontent">
					<xsl:choose>
					<xsl:when test="check='0'">
						<input type="checkbox">
							<xsl:attribute name="id">chk<xsl:value-of select="key"/></xsl:attribute>
							<xsl:attribute name="onclick">
								setAppVersion('<xsl:value-of select="key" />');
							</xsl:attribute>
						</input>
					</xsl:when>
					<xsl:otherwise>
						<input type="checkbox" checked="true">
							<xsl:attribute name="id">chk<xsl:value-of select="key"/></xsl:attribute>
							<xsl:attribute name="onclick">
								setAppVersion('<xsl:value-of select="key" />');
							</xsl:attribute>
						</input>
					</xsl:otherwise>
					</xsl:choose>
				</td>
				<td class="td_listcontent">
					<xsl:value-of select="key" />
				</td>
				<td class="td_listcontent">
					<xsl:value-of select="appversion" />
				</td>
				<td class="td_listcontent">
					<xsl:value-of select="vreversion" />
				</td>
				<td class="td_listcontent">
					<xsl:value-of select="memorysize" />
				</td>
				<td class="td_listcontent">
					<xsl:value-of select="screenwidth" />
				</td>
				<td class="td_listcontent">
					<xsl:value-of select="screenheight" />
				</td>
				<td class="td_listcontent">
					<xsl:value-of select="inputdc" />
				</td>
				<td class="td_listcontent">
					<xsl:value-of select="filename" />
				</td>
			</tr>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
