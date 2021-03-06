# Created by: db
# $FreeBSD$

PORTNAME=	libfec
PORTVERSION=	3.0.1
PORTREVISION=	2
CATEGORIES=	comms astro hamradio math
MASTER_SITES=	http://www.ka9q.net/code/fec/ \
		LOCAL/db
DISTNAME=	fec-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Several forward error correction (FEC) decoders

LICENSE=	LGPL21

MAKEFILE=	makefile

GNU_CONFIGURE=	yes
USES=		autoreconf gmake tar:bzip2
USE_LDCONFIG=	yes
PLIST_FILES=	include/fec.h		\
		lib/libfec.so		\
		lib/libfec.a		\
		man/man3/dsp.3.gz	\
		man/man3/rs.3.gz	\
		man/man3/simd-viterbi.3.gz

.include <bsd.port.pre.mk>

.if ${ARCH} == "x86_64"
CFLAGS+=	-fPIC
.endif

post-patch:
	@${CP} ${FILESDIR}/cpu_mode.c ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${MAN3PREFIX}/man/man3
	${INSTALL_DATA} ${WRKSRC}/fec.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libfec.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libfec.so ${STAGEDIR}${PREFIX}/lib
.for _man in dsp.3 simd-viterbi.3 rs.3
	${INSTALL_MAN} ${WRKSRC}/${_man} ${STAGEDIR}${MAN3PREFIX}/man/man3
.endfor

.include <bsd.port.post.mk>
