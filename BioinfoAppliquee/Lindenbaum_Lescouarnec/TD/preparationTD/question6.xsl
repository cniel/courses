<?xml version='1.0' encoding="UTF-8"?>
<xsl:stylesheet version='1.0'
	xmlns:xsl='http://www.w3.org/1999/XSL/Transform' >
<xsl:output method='xml' />
 
<xsl:template match="/">
	<html>
		<xsl:apply-templates select="eInfoResult"/>
	</html>
</xsl:template>

<xsl:template match="eInfoResult">
	<body>
		<xsl:apply-templates select="DbList"/>
	</body>
</xsl:template>

<xsl:template match="DbList">
	<ul>
		<xsl:apply-templates select="DbName"/>
	</ul>
</xsl:template>

<xsl:template match="DbName">
	<li>
		<a>
			<xsl:attribute name="href">
			<xsl:text>#</xsl:text>
			</xsl:attribute>
			<xsl:value-of select="."/>
		</a>
	</li>
</xsl:template>

</xsl:stylesheet>
