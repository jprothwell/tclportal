<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_list" cellspacing="1" cellpadding="0">
			<xsl:apply-templates select="feeinfo"/>
			<xsl:apply-templates select="list"/>
		</table>   
	</xsl:template>
	
	<xsl:template match="feeinfo">
	    <tr>
		   <td width="15%" class="td_listtitle">
			<xsl:value-of select="provincename"/></td>
		   <td width="17%" class="td_listtitle">
			<xsl:value-of select="openProvincemarks"/></td>
		   <td width="17%" class="td_listtitle">
			<xsl:value-of select="secconfir"/></td>
		   <td width="17%" class="td_listtitle">
			<xsl:value-of select="daytop"/></td>
		   <td width="17%" class="td_listtitle">
			<xsl:value-of select="monthtop"/></td>
		   <td width="17%" class="td_listtitle">
			<xsl:value-of select="open2x" /></td>
		</tr>
	</xsl:template>
	
	<xsl:template match="list">
		<xsl:for-each select="row">
			<tr>
			   <xsl:attribute name="id">#areaname#tr<xsl:value-of select="num"/></xsl:attribute>
		
		       <td class="td_listtitle">
					<xsl:value-of select="provincename" />
		       </td>
		       <td align="center" class="td_listcontent">
						<xsl:choose>
							<xsl:when test="openProvincemarks='1'">
								<input type="checkbox" checked="true">
									 <!-- 关闭  -->
						             <xsl:attribute name="id">chkop<xsl:value-of select="provinceid" /></xsl:attribute>						          
						             <xsl:attribute name="onclick">clickOpenProvinceMarks('<xsl:value-of select="provinceid" />','<xsl:value-of select="feeid" />',<xsl:value-of select="openProvincemarks=1"/>);
						             </xsl:attribute>						             
								</input>
							</xsl:when>
							<xsl:when test="openProvincemarks='0'">
								<input type="checkbox">
									<!--开通-->
								 	 <xsl:attribute name="id">chkop<xsl:value-of select="provinceid" /></xsl:attribute>						          
						             <xsl:attribute name="onclick">clickOpenProvinceMarks('<xsl:value-of select="provinceid" />','<xsl:value-of select="feeid" />',<xsl:value-of select="openProvincemarks=1"/>);
						             </xsl:attribute>						             
							
								</input>
							</xsl:when>
						</xsl:choose>
			 </td>
		     <td align="center" class="td_listcontent">
						<xsl:choose>
							<xsl:when test="secconfir='1'">
								<input type="checkbox" checked="true">
								<!-- 关闭  -->
						             <xsl:attribute name="id">chkop<xsl:value-of select="provinceid" /></xsl:attribute>						          
						             <xsl:attribute name="onclick">clickSecConfir('<xsl:value-of select="provinceid" />','<xsl:value-of select="feeid" />',<xsl:value-of select="secconfir=1"/>);
						             </xsl:attribute>		
								</input>
							</xsl:when>
							<xsl:when test="secconfir='2'">
								<input type="checkbox">
								  <xsl:attribute name="id">chkop<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          <xsl:attribute name="onclick">clickSecConfir('<xsl:value-of select="provinceid" />','<xsl:value-of select="feeid" />',<xsl:value-of select="secconfir=1"/>);
						          </xsl:attribute>
								</input>
							</xsl:when>
						</xsl:choose>
		    </td>
		    <td align="center" class="td_listcontent">
					<input type="text" size="5"  id="daytop">
						<xsl:attribute name="id">daytop<xsl:value-of select="provinceid" /></xsl:attribute>
						<xsl:attribute name="value"><xsl:value-of select="daytop" /></xsl:attribute>
						<xsl:attribute name="onkeypress">
								updateDayTop('<xsl:value-of select="provinceid" />','<xsl:value-of select="feeid" />');
						 </xsl:attribute>
					</input>
		   </td>
		   <td align="center" class="td_listcontent">
					<input type="text" size="5" id="monthtop">
						<xsl:attribute name="id">monthtop<xsl:value-of select="provinceid" /></xsl:attribute>
						<xsl:attribute name="value"><xsl:value-of select="monthtop" /></xsl:attribute>
						<xsl:attribute name="onkeypress">
								updateMonthTop('<xsl:value-of select="provinceid" />','<xsl:value-of select="feeid" />');
						 </xsl:attribute>
					</input>
		   </td>
		     <td align="center" class="td_listcontent">
						<xsl:choose>
							<xsl:when test="open2x='1'">
								<input type="checkbox" checked="true">
								<!-- 关闭  -->
						             <xsl:attribute name="id">chkop<xsl:value-of select="provinceid" /></xsl:attribute>						          
						             <xsl:attribute name="onclick">clickOpen2x('<xsl:value-of select="provinceid" />','<xsl:value-of select="feeid" />',<xsl:value-of select="open2x=1"/>);
						             </xsl:attribute>		
								</input>
							</xsl:when>
							<xsl:when test="open2x='0'">
								<input type="checkbox">
								 <xsl:attribute name="id">chkop<xsl:value-of select="provinceid" /></xsl:attribute>						          
						             <xsl:attribute name="onclick">clickOpen2x('<xsl:value-of select="provinceid" />','<xsl:value-of select="feeid" />',<xsl:value-of select="open2x=1"/>);
						             </xsl:attribute>				
								</input>
							</xsl:when>
						</xsl:choose>
			 </td>	
		 </tr>
	 </xsl:for-each>
   </xsl:template>
</xsl:stylesheet>
