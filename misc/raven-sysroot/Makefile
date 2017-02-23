# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	raven-sysroot
PORTVERSION=	1
CATEGORIES=	misc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	marino@FreeBSD.org
COMMENT=	System root for Ravenports

BUILD_DEPENDS=	nawk>0:lang/nawk \
		bzip2>0:archivers/bzip2 \
		diffutils>0:textproc/diffutils \
		libarchive>0:archivers/libarchive \
		sha256>0:security/sha256 \
		gnugrep>0:textproc/gnugrep \
		fetch>0:ftp/fetch \
		file>0:sysutils/file \
		findutils>0:misc/findutils \
		flex>0:textproc/flex \
		gzip>0:archivers/gzip \
		xz>0:archivers/xz \
		unzip>0:archivers/unzip \
		m4>0:devel/m4 \
		bmake>0:devel/bmake \
		patch>0:devel/patch \
		gsed>0:textproc/gsed \
		byacc>0:devel/byacc \
		libdl>0:devel/libdl \
		uname>0:sysutils/uname \
		# end

NO_BUILD=	yes
PLIST=		${WRKSRC}/package-list

Libc_DragonFly=		libc.so.8
Libm_DragonFly=		libm.so.4
Libutil_DragonFly=	libutil.so.4
Libc_FreeBSD=		libc.so.7
Libm_FreeBSD=		libm.so.5
Libutil_FreeBSD=	libutil.so.9
Libusb_DragonFly=	libusb.so.2
Libusb_FreeBSD=		libusb.so.3
Libusbhid_DragonFly=	libusbhid.so.4
Libusbhid_FreeBSD=	libusbhid.so.4

PLIST_SUB=	SONAME_LIBM=${Libm_${OPSYS}} \
		SONAME_LIBC=${Libc_${OPSYS}} \
		SONAME_LIBUTIL=${Libutil_${OPSYS}} \
		SONAME_LIBUSB=${Libusb_${OPSYS}} \
		SONAME_LIBUSBHID=${Libusbhid_${OPSYS}} \
		# end

MAKE_ENV=	OPSYS="${OPSYS}" MKDIR="${MKDIR}"
MAKE_ENV+=	libm=${Libm_${OPSYS}} \
		libc=${Libc_${OPSYS}} \
		libutil=${Libutil_${OPSYS}} \
		libusb=${Libusb_${OPSYS}} \
		libusbhid=${Libusbhid_${OPSYS}} \
		# end

do-extract:
	${MKDIR} ${WRKSRC}
	cp ${FILESDIR}/* ${WRKSRC}/
	cat ${.CURDIR}/pkg-plist ${.CURDIR}/pkg-plist.${OPSYS} > ${WRKSRC}/package-list

.include <bsd.port.mk>
