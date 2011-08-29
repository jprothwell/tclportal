<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_list" cellspacing="1" cellpadding="0">
	 	  <tr>	
	 	  		 <xsl:apply-templates select="feeinfo"/>
				 <xsl:apply-templates select="list"/>
				 <td></td><td></td><td></td><td></td>		
				 <td align="right">
				 共<xsl:apply-templates select="count"/>条记录</td>
			</tr>	
		</table>   
	</xsl:template>

	<xsl:template match="feeinfo">
	    <tr>
	       <td width="10%" class="td_listtitle">
			<xsl:value-of select="appname"/></td>
		   <td width="10%" class="td_listtitle">
			<xsl:value-of select="province"/></td>
		   <td width="25%" class="td_listtitle">
			<xsl:value-of select="mfname"/></td>
		   <td width="15%" class="td_listtitle">
			<xsl:value-of select="mobilename"/></td>
		   <td width="15%" class="td_listtitle">
			<xsl:value-of select="operator"/></td>
		</tr>
	</xsl:template>
	
	<xsl:template match="list">
		<xsl:for-each select="row">
			<tr>
				<xsl:attribute name="id">#areaname#tr<xsl:value-of select="num"/></xsl:attribute>
				<xsl:attribute name="onclick">
					clickRow('#areaname#','<xsl:value-of select="num" />','<xsl:value-of select="recid" />');
				</xsl:attribute>

					  <td align="center" width="10%" class="td_listcontent">
						<xsl:value-of select="appname"/></td>
						
		   			  <td align="center" width="20%" class="td_listcontent">
					  	<xsl:value-of select="province"/></td>
					  	
		   			  <td align="center" width="25%" class="td_listcontent">
						<xsl:value-of select="mfname"/></td>
						
		 			  <td align="center" width="25%" class="td_listcontent">
						<xsl:value-of select="mobilename"/></td>

		  			 <td align="center" width="10%" class="td_listcontent">		
		  			  <xsl:choose>
							<xsl:when test="operator='1'">中国移动</xsl:when>
							<xsl:when test="operator='2'">中国联通</xsl:when>
		 				</xsl:choose>
					</td>	
		    </tr>					
		</xsl:for-each>	
   </xsl:template>
</xsl:stylesheet>