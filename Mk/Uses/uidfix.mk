# $FreeBSD: Mk/Uses/uidfix.mk 328128 2013-09-24 13:23:15Z bapt $
#
# Changes some default behaviour of build systems to allow installing as user.
#
# MAINTAINER:	bapt@FreeBSD.org
#
# Feature:	uidfix
# Usage:	USES=uidfix
# Valid ARGS:	none
#
.if !defined(_INCLUDE_USES_UIDFIX_MK)
.if ${UID} != 0
MAKE_ENV+=	BINOWN=${UID} SHAREOWN=${UID} CONFOWN=${UID}
BINOWN=	${UID}
SHAREOWN=	${UID}
WWWOWN=	${UID}
.endif
.endif
