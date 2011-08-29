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
			<xsl:choose>
			<xsl:when test="child='1'">
				<td width="16" style="cursor:hand;">
						<img src="../images/folderclosed.gif">
							<xsl:attribute name="id">img_<xsl:value-of select="key"/></xsl:attribute>
							<xsl:attribute name="onclick">
								showsubmenu('<xsl:value-of select="key" />');
							</xsl:attribute>
						</img>
				</td>
				<td class="td_listcontent">
					<xsl:attribute name="id">td<xsl:value-of select="key"/></xsl:attribute>
					<xsl:attribute name="onclick">
						showsubmenu('<xsl:value-of select="key" />');
					</xsl:attribute>
					<xsl:value-of select="name" />
				</td>
			</xsl:when>
			<xsl:otherwise>
				<td width="16" style="cursor:hand;">
						<img src="../images/file.gif"></img>
				</td>
				<td class="td_listcontent">
					<xsl:attribute name="id">td<xsl:value-of select="key"/></xsl:attribute>
					<xsl:attribute name="onclick">
						clickmenu('<xsl:value-of select="key" />','<xsl:value-of select="name" />');
					</xsl:attribute>
					<xsl:value-of select="name" />
				</td>
			</xsl:otherwise>
			</xsl:choose>
			</tr>
			<xsl:if test="child='1'">
				<tr style="display:none;">
					<xsl:attribute name="id">tr<xsl:value-of select="key"/></xsl:attribute>
					<td><xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text></td>
					<td>
						<xsl:attribute name="id">td0<xsl:value-of select="key"/></xsl:attribute>
						<xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
					</td>
				</tr>
			</xsl:if>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
