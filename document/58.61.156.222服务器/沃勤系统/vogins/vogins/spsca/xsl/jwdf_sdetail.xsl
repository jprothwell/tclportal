<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_edit" cellspacing="1" cellpadding="0">
			<xsl:apply-templates select="detail"/>
		</table>
	</xsl:template>
	<xsl:template match="detail">
		<xsl:for-each select="field">
			<tr>
				<td class="td_listtitle" width="20%"><xsl:value-of select="name" /></td>
				<td class="td_listcontent" width="80%"><xsl:value-of select="value" /></td>
			</tr>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
