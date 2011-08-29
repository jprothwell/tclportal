<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_tree" cellspacing="0" cellpadding="0">
			<xsl:apply-templates select="sub"/>
		</table>   
	</xsl:template>
	<xsl:template match="sub">
		<xsl:for-each select="leaf">
			<tr>
				<td width="16" style="cursor:hand;" class="td_listcontent">
					<xsl:choose>
					<xsl:when test="acctype='0'">
						<input type="checkbox">
							<xsl:attribute name="id">chk<xsl:value-of select="key"/></xsl:attribute>
							<xsl:attribute name="onclick">
								doServletAcc('<xsl:value-of select="key" />','<xsl:value-of select="name" />','<xsl:value-of select="acctype" />');
							</xsl:attribute>
						</input>
					</xsl:when>
					<xsl:otherwise>
						<input type="checkbox" checked="true">
							<xsl:attribute name="id">chk<xsl:value-of select="key"/></xsl:attribute>
							<xsl:attribute name="onclick">
								doServletAcc('<xsl:value-of select="key" />','<xsl:value-of select="name" />','<xsl:value-of select="acctype" />');
							</xsl:attribute>
						</input>
					</xsl:otherwise>
					</xsl:choose>
				</td>
				<td class="td_listcontent">
					<xsl:choose>
					<xsl:when test="acctype='1'">
						<font color="#008000">■</font>
					</xsl:when>
					<xsl:when test="acctype='2'">
						<font color="#00ff00">■</font>
					</xsl:when>
					<xsl:otherwise>
						<font color="red">■</font>
					</xsl:otherwise>
					</xsl:choose>
					<xsl:value-of select="optname" />［<xsl:value-of select="name" />］
				</td>
			</tr>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
