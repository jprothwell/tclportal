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
			<xsl:when test="parent='0'">
				<td class="menu_title" colspan="2" width="100%" height="29" style="cursor:hand;padding-left:10;">
					<xsl:attribute name="background"><xsl:value-of select="image"/></xsl:attribute>
					<xsl:attribute name="onmouseover">
						this.className="menu_title2";
					</xsl:attribute>
					<xsl:attribute name="onmouseout">
						this.className="menu_title";
					</xsl:attribute>
					<xsl:attribute name="onclick">
						showRootMenu('<xsl:value-of select="key" />','<xsl:value-of select="child" />','<xsl:value-of select="parent" />');
					</xsl:attribute>
					<span class="glow"><xsl:value-of select="name" /></span>
				</td>
			</xsl:when>
			<xsl:otherwise>
				<td bgcolor="white" width="16" style="cursor:hand;">
					<xsl:choose>
					<xsl:when test="child='1'">
						<img src="images/menu_folder_close.gif">
							<xsl:attribute name="id">img_<xsl:value-of select="key"/></xsl:attribute>
							<xsl:attribute name="onclick">
								showsubmenu('<xsl:value-of select="key" />','<xsl:value-of select="child" />','<xsl:value-of select="link" />');
							</xsl:attribute>
						</img>
					</xsl:when>
					<xsl:otherwise>
						<xsl:choose>
						<xsl:when test="last='1'">
							<img src="images/menu_leaf_last.gif"></img>
						</xsl:when>
						<xsl:otherwise>
							<img src="images/menu_leaf.gif"></img>
						</xsl:otherwise>
						</xsl:choose>
					</xsl:otherwise>
					</xsl:choose>
				</td>
				<td height="20" class="td_listcontent_tree" style="cursor:hand;">
					<xsl:attribute name="id">td<xsl:value-of select="key"/></xsl:attribute>
					<xsl:attribute name="onclick">
						showsubmenu('<xsl:value-of select="key" />','<xsl:value-of select="child" />','<xsl:value-of select="link" />');
					</xsl:attribute>
					<xsl:value-of select="name" />
				</td>
			</xsl:otherwise>
			</xsl:choose>
			</tr>
			<xsl:if test="child='1'">
				<tr style="display:none;" id="tr00">
					<xsl:attribute name="id">tr<xsl:value-of select="key"/></xsl:attribute>
					<xsl:choose>
					<xsl:when test="parent='0'">
						<td class="sec_menu" colspan="2" width="100%" id="td000">
							<xsl:attribute name="id">td0<xsl:value-of select="key"/></xsl:attribute>
							<xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
						</td>
					</xsl:when>
					<xsl:otherwise>
						<td bgcolor="white" width="16" class="td_menu_bg"><xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text></td>
						<td class="sec_menu" width="100%" id="td000">
							<xsl:attribute name="id">td0<xsl:value-of select="key"/></xsl:attribute>
							<xsl:text disable-output-escaping="yes">&amp;nbsp;</xsl:text>
						</td>
					</xsl:otherwise>
					</xsl:choose>
				</tr>
			</xsl:if>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
