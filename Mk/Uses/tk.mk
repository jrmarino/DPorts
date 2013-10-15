# $FreeBSD: Mk/Uses/tk.mk 327607 2013-09-19 09:49:52Z gahr $
#
# vim: ts=8 noexpandtab
#
#

.if ${USES:Mtcl} || ${USES:Mtcl\:*}
IGNORE= Do not set both tcl and tk in USES
.endif

.if defined(tk_ARGS)
tcl_ARGS:=	${tk_ARGS}
.endif

_TCLTK_PORT=	tk

.include "${PORTSDIR}/Mk/Uses/tcl.mk"
