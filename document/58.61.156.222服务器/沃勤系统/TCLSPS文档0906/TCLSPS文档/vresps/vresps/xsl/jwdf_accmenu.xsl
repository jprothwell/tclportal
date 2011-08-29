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
							<xsl:attribute name="id">#areaname#img_<xsl:value-of select="key"/></xsl:attribute>
							<xsl:attribute name="onclick">
								showSub('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="name" />','<xsl:value-of select="acctype" />');
							</xsl:attribute>
						</img>
				</td>
				<td class="td_listcontent">
					<xsl:attribute name="id">#areaname#td<xsl:value-of select="key"/></xsl:attribute>
					<xsl:attribute name="onclick">
						showSub('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="name" />','<xsl:value-of select="acctype" />');
					</xsl:attribute>
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
					<xsl:value-of select="name" />
				</td>
			</xsl:when>
			<xsl:otherwise>
				<td width="16" style="cursor:hand;">
						<img src="../images/file.gif"></img>
				</td>
				<td class="td_listcontent">
					<xsl:attribute name="id">#areaname#td<xsl:value-of select="key"/></xsl:attribute>
					<xsl:attribute name="onclick">
						clickLeaf('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="name" />','<xsl:value-of select="acctype" />');
					</xsl:attribute>
					<xsl:attribute name="ondblclick">
						showLeafDetail('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="name" />','<xsl:value-of select="acctype" />');
					</xsl:attribute>
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
					<xsl:value-of select="name" />
				</td>
			</xsl:otherwise>
			</xsl:choose>
			</tr>
			<xsl:if test="child='1'">
				<tr style="display:none;">
					<xsl:attribute name="id">#areaname#tr<xsl:value-of select="key"/></xsl:attribute>
					<td><xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text></td>
					<td>
						<xsl:attribute name="id">#areaname#td0<xsl:value-of select="key"/></xsl:attribute>
						<xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
					</td>
				</tr>
			</xsl:if>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
