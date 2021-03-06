# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdb
PORTVERSION=	7.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	GNU GDB of newer version than comes with the system

LICENSE=	GPLv3

TEST_DEPENDS=	runtest:misc/dejagnu

TEST_TARGET=	check
USES=		cpe iconv gmake libtool tar:xz
USE_CSTD=	gnu89
CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIGURED_M4=m4 CONFIGURED_BISON=byacc
CONFIGURE_ARGS=	--program-suffix=${PORTVERSION:S/.//g} \
		--enable-targets=all --enable-64-bit-bfd \
		--with-gdb-datadir=${PREFIX}/share/gdb${PORTVERSION:S/.//g} \
		--with-separate-debug-dir=/usr/lib/debug \
		${ICONV_CONFIGURE_ARG} \
		--with-expat=yes --with-libexpat-prefix=${LOCALBASE} \
		--without-libunwind-ia64
CFLAGS:=	${CFLAGS:C/ +$//}	# blanks at EOL creep in sometimes
CFLAGS+=	-DRL_NO_COMPAT -Wno-unused-function -Wno-unused-variable
EXCLUDE=	dejagnu expect sim texinfo intl
EXTRACT_AFTER_ARGS=	${EXCLUDE:S/^/--exclude /}
EXTRA_PATCHES=	${FILESDIR}/commit-387360daf9 \
		${FILESDIR}/commit-b268007c68
LIB_DEPENDS+=	libexpat.so:textproc/expat2

VER=		${PORTVERSION:S/.//g}
PLIST_SUB=	VER=${VER}

ONLY_FOR_ARCHS=	i386 amd64 powerpc powerpc64 armv6 mips	# untested elsewhere, might work

OPTIONS_DEFINE=	DEBUG GDB_LINK GUILE KGDB PYTHON TUI

OPTIONS_DEFAULT=	GDB_LINK PYTHON TUI PORT_READLINE

OPTIONS_SINGLE=	READLINE
OPTIONS_SINGLE_READLINE=	BUNDLED_READLINE PORT_READLINE

GDB_LINK_DESC=		Create ${PREFIX}/bin/gdb symlink
KGDB_DESC=		Kernel Debugging Support
BUNDLED_READLINE_DESC=	from gdb distfile
PORT_READLINE_DESC=	from devel/readline port
TUI_DESC=		Text User Interface enabled

OPTIONS_SUB=	yes

BUNDLED_READLINE_CONFIGURE_OFF=	--with-system-readline
DEBUG_CFLAGS=		-g
GUILE_CONFIGURE_WITH=	guile
GUILE_USES=		pkgconfig
GUILE_LIB_DEPENDS=	libguile-2.0.so:lang/guile2
PORT_READLINE_USES=	readline:port
PYTHON_CONFIGURE_ON=	--with-python=${PYTHON_CMD}
PYTHON_CONFIGURE_OFF=	--without-python
PYTHON_USES=		python:2
TUI_CONFIGURE_ENABLE=	tui

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MBUNDLED_READLINE}
EXCLUDE+=	readline
.endif

# Wow c++ smth.c too on gdb, gcc wasn't enough? throw helpers for c-- and try to kill it
CFLAGS+=	-D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS
CONFIGURE_ARGS+=	--disable-build-with-cxx

post-patch:
	@${REINPLACE_CMD} -e 's|$$| [GDB v${PORTVERSION} for ${OPSYS}]|' \
		${WRKSRC}/gdb/version.in

post-patch-KGDB-on:
	@${CP} -r ${FILESDIR}/kgdb/*.[ch] ${WRKSRC}/gdb/
	@${PATCH} -d ${PATCH_WRKSRC} ${PATCH_ARGS} < ${FILESDIR}/extrapatch-kgdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${STAGEDIR}${PREFIX}/bin/gdb${VER}
	${INSTALL_MAN} ${WRKSRC}/gdb/doc/gdb.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/gdb${VER}.1
	(cd ${WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-syscalls )

do-install-KGDB-on:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/kgdb \
		${STAGEDIR}${PREFIX}/bin/kgdb${VER}

do-install-TUI-on:
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdbtui${VER}

do-install-GDB_LINK-on:
	${LN} -sf gdb${VER} ${STAGEDIR}${PREFIX}/bin/gdb
.if ${PORT_OPTIONS:MKGDB}
	${LN} -sf kgdb${VER} ${STAGEDIR}${PREFIX}/bin/kgdb
.endif

dfly-patch:
	${CP} ${DFLY_FILESDIR}/dfly64.mh ${WRKSRC}/gdb/config/i386/
	${CP} ${DFLY_FILESDIR}/dfly-nat.* ${WRKSRC}/gdb/
	${CP} ${DFLY_FILESDIR}/i386* ${WRKSRC}/gdb/
	${CP} ${DFLY_FILESDIR}/amd64* ${WRKSRC}/gdb/
.if ${PORT_OPTIONS:MKGDB}
	${PATCH} ${PATCH_ARGS} < ${DFLY_FILESDIR}/extrapatch-kgdb
.endif

do-install-PYTHON-on:
	(cd ${WRKSRC}/gdb; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
	(cd ${WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-python )
. for f in gdb gdb/command gdb/function gdb/printer
	@(cd ${STAGEDIR}${PREFIX}/share/gdb${VER}/python/${f} ; ${CHMOD} 644 *.py* )
. endfor

do-install-GUILE-on:
	(cd ${WRKSRC}/gdb; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )
	(cd ${WRKSRC}/gdb/data-directory ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-guile )

.include <bsd.port.mk>
