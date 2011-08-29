<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_list" cellspacing="1" cellpadding="0">
			<xsl:apply-templates select="col"/>
			<xsl:apply-templates select="list"/>
		</table>   
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
