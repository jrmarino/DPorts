# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xml2
PORTVERSION=	1.0.0
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Parse XML

LICENSE=	GPLv2+

BUILD_DEPENDS=	R-cran-Rcpp>=0.11.4.6:devel/R-cran-Rcpp \
		R-cran-BH>0:devel/R-cran-BH
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=	cran:auto-plist,compiles
USE_GNOME=	libxml2

post-patch:
	@${REINPLACE_CMD} -e 's|bin/bash|bin/sh|' ${WRKSRC}/configure

.include <bsd.port.mk>
