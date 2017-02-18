# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fetch
PORTVERSION=	1
CATEGORIES=	ftp
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Tools to retrieve a file by Uniform Resource Locator

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	libressl>0:security/libressl

PLIST_FILES=	bin/fetch

do-extract:
	${MKDIR} ${WRKSRC}
	cp ${FILESDIR}/* ${WRKSRC}/

.include <bsd.port.mk>
