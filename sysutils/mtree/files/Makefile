SRCS=		compare.c create.c excludes.c misc.c mtree.c spec.c \
		verify.c crc.c
OBJS=		${SRCS:.c=.o}

.SUFFIXES:	.o .c

.c.o:
	${CC} ${_${.IMPSRC:T}_FLAGS} ${CFLAGS} -c ${.IMPSRC}

mtree:	${OBJS}
		${CC} ${CFLAGS} ${.ALLSRC} -o ${.TARGET}
