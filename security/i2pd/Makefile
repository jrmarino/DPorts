# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i2pd
PORTVERSION=	2.11.0
PORTREVISION=	4
CATEGORIES=	security net-p2p

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	C++ implementation of I2P client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

BROKEN_powerpc64=	does not build

USE_GITHUB=	yes
GH_ACCOUNT=	PurpleI2P

USES=		cmake compiler:c++11-lib ssl
CMAKE_SOURCE_PATH=${WRKSRC}/build
USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	*

USERS=		_i2pd
GROUPS=		_i2pd

PLIST_SUB=	USER="${USERS}" GROUP="${GROUPS}"
SUB_LIST=	USER="${USERS}" GROUP="${GROUPS}"
SUB_FILES=	i2pd.newsyslog.conf

OPTIONS_DEFINE=	AESNI UPNP DOCS

AESNI_DESC=		Use AES-NI instructions set
AESNI_CMAKE_BOOL=	WITH_AESNI
UPNP_DESC=		Include support for UPnP client
UPNP_CMAKE_BOOL=	WITH_UPNP
UPNP_LIB_DEPENDS=	libminiupnpc.so:net/miniupnpc

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mlibressl*}
BROKEN=		does not build with LibreSSL (boost libressl compatibility problems)
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/debian/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${WRKDIR}/i2pd.newsyslog.conf ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/i2pd.conf
	@${MKDIR} ${STAGEDIR}/var/run/i2pd
	@${MKDIR} ${STAGEDIR}/var/log/i2pd
	@${MKDIR} ${STAGEDIR}/var/db/i2pd

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/configuration.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.post.mk>
