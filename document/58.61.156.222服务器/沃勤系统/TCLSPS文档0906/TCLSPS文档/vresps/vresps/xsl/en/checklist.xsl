<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_edit" cellspacing="1" cellpadding="0">
			<tr>
				<td class="td_listcontent">
					<xsl:apply-templates select="list"/>
				</td>
			</tr>
		</table>   
	</xsl:template>
	<xsl:template match="list">
		<input type="checkbox">
			<xsl:attribute name="id">chk_0</xsl:attribute>
			<xsl:attribute name="onclick">
				clickCheck('0','Default');
			</xsl:attribute>
		</input>Default<br/>
		<xsl:for-each select="row">
			<input type="checkbox">
				<xsl:attribute name="id">chk_<xsl:value-of select="key" /></xsl:attribute>
				<xsl:attribute name="onclick">
					clickCheck('<xsl:value-of select="key" />','<xsl:value-of select="field" />');
				</xsl:attribute>
			</input><xsl:value-of select="field" /><br/>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
