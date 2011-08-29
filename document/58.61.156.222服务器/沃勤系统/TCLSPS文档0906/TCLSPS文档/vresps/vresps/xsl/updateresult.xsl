<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<tr>
			<td align="center" class="td_listcontent"><xsl:value-of select="info" /></td>
		</tr>
   </xsl:template>
</xsl:stylesheet>