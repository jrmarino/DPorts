# Created by: Torsten Zuehlsdorff <ports@toco-domains.de>
# $FreeBSD$

PORTNAME=	premailer
PORTVERSION=	1.9.2
CATEGORIES=	mail rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Improve the rendering of HTML emails

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-css_parser>=1.4.8:textproc/rubygem-css_parser \
		rubygem-htmlentities>=4.0.0:textproc/rubygem-htmlentities

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/premailer

.include <bsd.port.mk>
