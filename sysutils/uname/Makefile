# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uname
PORTVERSION=	1
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	draco@marino.st
COMMENT=	Fake uname for raven-sysroot

LICENSE=	BSD2CLAUSE

PLIST_FILES=	bin/uname

.if defined(.MAKE.DF.VERSION)
USERVER=	${.MAKE.DF.VERSION}
.else
USERVER=	${OSVERSION}
.endif

do-extract:
	${MKDIR} ${WRKSRC}
	${SED} -e 's|@OPSYS@|${OPSYS}|g' \
		-e 's|@ARCH@|${ARCH}|g' \
		-e 's|@PLATFORM@|${ARCH}|g' \
		-e 's|@RELEASE@|${OSREL}-RAVEN|g' \
		-e 's|@USERVER@|${USERVER}|g' \
		${FILESDIR}/uname.c.in > ${WRKSRC}/uname.c

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${CC} -o uname uname.c ${CFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uname ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
