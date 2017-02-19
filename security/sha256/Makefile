# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sha256
PORTVERSION=	1
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	marino@FreeBSD.org
COMMENT=	MD5 and SHA-256 digest tools from DragonFly

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	libressl>0:security/libressl

PLIST_FILES=	bin/md5 bin/sha256

do-extract:
	${MKDIR} ${WRKSRC}
	cp ${FILESDIR}/* ${WRKSRC}/

.include <bsd.port.mk>
