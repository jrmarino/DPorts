# Created by: Gerrit Beine <tux@pinguru.net>
# $FreeBSD$

PORTNAME=	memcache
PORTVERSION=	3.0.8
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	php70-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Memcached extension for PHP 7.0

LICENSE=	PHP30
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	EXAMPLES

CONFIGURE_ARGS=	--with-zlib-dir=/usr
IGNORE_WITH_PHP=56 71
PHP_VER=	70
USE_CSTD=	gnu89
USE_PHP=	session:build zlib:build
USES=		dos2unix php:ext

GH_ACCOUNT=	websupport-sk
GH_PROJECT=	pecl-${PORTNAME}
GH_TAGNAME=	5041d2f
USE_GITHUB=	yes

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/example.php ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
