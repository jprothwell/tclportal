<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_list" cellspacing="1" cellpadding="0">
			<xsl:apply-templates select="feeinfo"/>
			<xsl:apply-templates select="list"/>
		</table>   
	</xsl:template>
	
	<xsl:template match="list">
		<br/>
		<tr>
			<td width="30%" class="td_listtitle" colspan="2">提示：修改好后请按回车键保存
			</td>
		</tr>
		<tr>
			<td width="30%" class="td_listtitle">前缀
			</td>
			<td width="30%" class="td_listtitle">后缀
			</td>
		</tr>
		<tr>
			<form name="newform">
		      	<td align="center" class="td_listcontent">      			
		       		<input type="text" size="30" maxlength="100" id="prefix">
						<xsl:attribute name="value"><xsl:value-of select="prefix" /></xsl:attribute>
						<xsl:attribute name="onkeypress">updatePreSuffix();</xsl:attribute>
						<xsl:attribute name="onfocus">cleanResult();</xsl:attribute>
					</input>
		      	</td>
		      	<td align="center" class="td_listcontent">      			
		       		<input type="text" size="30"  maxlength="100" id="suffix">
						<xsl:attribute name="value"><xsl:value-of select="suffix" /></xsl:attribute>
						<xsl:attribute name="onkeypress">updatePreSuffix();</xsl:attribute>
						<xsl:attribute name="onfocus">cleanResult();</xsl:attribute>
					</input>
		      	</td>
		    </form>
		 </tr>
   </xsl:template>
</xsl:stylesheet>