<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<xsl:apply-templates select="list"/>
	</xsl:template>
	<xsl:template match="list">
		<xsl:for-each select="row">
			<a target='JWDFMainFrame'>
				<xsl:attribute name="href"><xsl:value-of select="link" /></xsl:attribute>
				<img width="86" height="74" border="0">
					<xsl:attribute name="src">images/<xsl:value-of select="icon" /></xsl:attribute>
				</img>
			</a>
		</xsl:for-each>
	</xsl:template>
</xsl:stylesheet>
