<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
	<xsl:template match="result">
		<table class="table_list" cellspacing="1" cellpadding="0">
			<xsl:apply-templates select="feeinfo"/>
			<xsl:apply-templates select="list"/>
		</table>   
	</xsl:template>
	
	<xsl:template match="feeinfo">
	    <tr><!--
	        <td width="10%" class="td_listtitle">
			<xsl:value-of select="provinceid"/></td>
		   --><td width="10%" class="td_listtitle">
			<xsl:value-of select="provincename"/></td>
		   <td width="25%" class="td_listtitle">
			<xsl:value-of select="secconfig"/></td>
		   <td width="15%" class="td_listtitle">
			<xsl:value-of select="msecconfig"/></td>
		   <td width="15%" class="td_listtitle">
			<xsl:value-of select="overtime"/></td>
		</tr>
	</xsl:template>
	
	<xsl:template match="list">
		<xsl:for-each select="row">
			<tr>
			<form name="newform">
			   <xsl:attribute name="id">#areaname#tr<xsl:value-of select="num"/></xsl:attribute><!--
		
					<td class="td_listtitle">
						<xsl:value-of select="provinceid" />
		       		</td>
		      	 	-->
		      	 	<td class="td_listtitle">
						<xsl:value-of select="provincename" />
		       		</td>
		       		  <td align="center" class="td_listcontent">	       		  
		       		  	 <xsl:choose>
							<xsl:when test="secconfig='2'">
								<input type="radio" value="2" checked="true">
										 <xsl:attribute name="name">ra<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          		 <xsl:attribute name="onclick">clickSecconfig('<xsl:value-of select="provinceid" />',2);
						             	 </xsl:attribute>开通						             	
								</input>
								<input type="radio" value="1">
										 <xsl:attribute name="name">ra<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          		 <xsl:attribute name="onclick">clickSecconfig('<xsl:value-of select="provinceid" />',1);
						             	 </xsl:attribute>半开通
								</input>
								<input type="radio" value="0">
										 <xsl:attribute name="name">ra<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          		 <xsl:attribute name="onclick">clickSecconfig('<xsl:value-of select="provinceid" />',0);
						             	 </xsl:attribute>关闭
								</input>
							</xsl:when>
							<xsl:when test="secconfig='1'">
								<input type="radio" value="2">
										 <xsl:attribute name="name">ra<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          		 <xsl:attribute name="onclick">clickSecconfig('<xsl:value-of select="provinceid" />',2);
						             	 </xsl:attribute>开通						             	
								</input>
								<input type="radio" value="1" checked="true">
										 <xsl:attribute name="name">ra<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          		 <xsl:attribute name="onclick">clickSecconfig('<xsl:value-of select="provinceid" />',1);
						             	 </xsl:attribute>半开通
								</input>
								<input type="radio" value="2">
										 <xsl:attribute name="name">ra<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          		 <xsl:attribute name="onclick">clickSecconfig('<xsl:value-of select="provinceid" />',0);
						             	 </xsl:attribute>关闭							
								</input>
							</xsl:when>
							<xsl:when test="secconfig='0'">
								<input type="radio" value="2">
										 <xsl:attribute name="name">ra<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          		 <xsl:attribute name="onclick">clickSecconfig('<xsl:value-of select="provinceid" />',2);
						             	 </xsl:attribute>开通						             	
								</input>
								<input type="radio" value="1">
										 <xsl:attribute name="name">ra<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          		 <xsl:attribute name="onclick">clickSecconfig('<xsl:value-of select="provinceid" />',1);
						             	 </xsl:attribute>半开通		
								</input>
								<input type="radio" value="0" checked="true">
										 <xsl:attribute name="name">ra<xsl:value-of select="provinceid" /></xsl:attribute>						          
						          		 <xsl:attribute name="onclick">clickSsecconfig('<xsl:value-of select="provinceid" />',0);
						             	 </xsl:attribute>关闭
								</input>
							</xsl:when>
				</xsl:choose>
					 </td>
			
		      		 <td align="center" class="td_listcontent">
						<xsl:choose>
							<xsl:when test="msecconfig='1'">
								<input type="checkbox" checked="true">
									<!--开通-->
								 	 <xsl:attribute name="id">chkop<xsl:value-of select="provinceid" /></xsl:attribute>						          
						             <xsl:attribute name="onclick">clickMsecconfig('<xsl:value-of select="provinceid" />',<xsl:value-of select="msecconfig=1"/>);
						             </xsl:attribute>						             	
								</input>
							</xsl:when>
							<xsl:when test="msecconfig='0'">
								<input type="checkbox">
									<!--开通-->
								 	 <xsl:attribute name="id">chkop<xsl:value-of select="provinceid" /></xsl:attribute>						          
						             <xsl:attribute name="onclick">clickMsecconfig('<xsl:value-of select="provinceid" />',<xsl:value-of select="msecconfig=1"/>);
						             </xsl:attribute>						             			
								</input>
							</xsl:when>
						</xsl:choose>
					 </td>
		      		 
		      		  <td align="center" class="td_listcontent">      			
		       			<input type="text" size="5"  id="overtime">
							<xsl:attribute name="id">overtime<xsl:value-of select="provinceid" /></xsl:attribute>
							<xsl:attribute name="value"><xsl:value-of select="overtime" /></xsl:attribute>
							<xsl:attribute name="onkeypress">updateOvertime('<xsl:value-of select="provinceid" />');</xsl:attribute>
						</input>
		      		 </td>
		      		 </form>
		 </tr>
	 </xsl:for-each>
   </xsl:template>
</xsl:stylesheet>