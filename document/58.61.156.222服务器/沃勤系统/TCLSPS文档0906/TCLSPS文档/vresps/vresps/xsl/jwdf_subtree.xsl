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
							showSub('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="child" />','<xsl:value-of select="parent" />','<xsl:value-of select="name" />');
						</xsl:attribute>
						<xsl:attribute name="onContextMenu">
							showPopMenu_Tree('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="child" />','<xsl:value-of select="parent" />');return false;
						</xsl:attribute>
					</img>
				</td>
				<td class="td_listcontent">
					<xsl:attribute name="id">#areaname#td<xsl:value-of select="key"/></xsl:attribute>
					<xsl:attribute name="onclick">
						showSub('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="child" />','<xsl:value-of select="parent" />','<xsl:value-of select="name" />');
					</xsl:attribute>
					<xsl:attribute name="onContextMenu">
						showPopMenu_Tree('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="child" />','<xsl:value-of select="parent" />');return false;
					</xsl:attribute>
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
						clickLeaf('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="child" />','<xsl:value-of select="parent" />','<xsl:value-of select="name" />');
					</xsl:attribute>
					<xsl:attribute name="onContextMenu">
						showPopMenu_Tree('#areaname#','<xsl:value-of select="key" />','<xsl:value-of select="child" />','<xsl:value-of select="parent" />');return false;
					</xsl:attribute>
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
