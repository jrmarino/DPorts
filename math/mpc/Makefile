# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	mpc
PORTVERSION=	1.0.3
CATEGORIES=	math devel
MASTER_SITES=	http://www.multiprecision.org/mpc/download/

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	Library of complex numbers with arbitrarily high precision

BUILD_DEPENDS=	gmp>0:math/gmp \
		mpfr>0:math/mpfr

PORTSCOUT=	site:http://www.multiprecision.org/index.php?prog=mpc&page=download

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE} \
		--enable-shared=no
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

INFO=		mpc
PLIST_FILES=	include/mpc.h \
		lib/libmpc.a

regression-test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check)

.include <bsd.port.mk>
