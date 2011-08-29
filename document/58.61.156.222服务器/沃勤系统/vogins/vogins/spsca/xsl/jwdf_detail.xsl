<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table width="100%" height="100%" class="table_list" cellspacing="1" cellpadding="0">
			<xsl:apply-templates select="detail"/>
		</table>
	</xsl:template>
	<xsl:template match="detail">
		<tr>
			<td colspan="2" height="20" align="center"><b>详细信息</b></td>
		</tr>
		<xsl:for-each select="field">
			<tr>
				<td class="td_listtitle" width="20%"><xsl:value-of select="name" /></td>
				<td class="td_listcontent" width="80%"><xsl:value-of select="value" /></td>
			</tr>
		</xsl:for-each>
		<tr>
			<td class="td_listtitle1"><xsl:text> </xsl:text></td>
			<td class="td_listcontent1"><xsl:text> </xsl:text></td>
		</tr>
	</xsl:template>
</xsl:stylesheet>
