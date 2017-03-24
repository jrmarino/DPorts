# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mtree
PORTVERSION=	201404
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	draco@marino.st
COMMENT=	NetBSD mtree (from FreebSD)

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	libressl>0:security/libressl
PLIST_FILES=	bin/mtree
CFLAGS=		-DUSE_SHA1 -I${LOCALBASE}/include

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/* ${WRKSRC}

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} mtree)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtree ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
