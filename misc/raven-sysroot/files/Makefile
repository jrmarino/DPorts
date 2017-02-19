# Create identical sysroot regardless of host system

all: sysroot

Libexec_DragonFly=	/libexec/ld-elf.so.2
Libexec_FreeBSD=	/libexec/ld-elf.so.1

# /bin/cat    (archivers/libarchive)
# /bin/md5    (security/sha256)
# /bin/sha256 (security/sha256)

Bin_DragonFly=	/bin/[ \
		/usr/bin/chflags \
		/bin/chmod \
		/bin/cp \
		/bin/csh \
		/bin/date \
		/bin/expr \
		/bin/hostname \
		/bin/kill \
		/bin/link \
		/bin/ln \
		/bin/ls \
		/bin/mkdir \
		/bin/mv \
		/bin/pax \
		/bin/realpath \
		/bin/rm \
		/bin/rmdir \
		/bin/sh \
		/bin/sleep \
		/bin/test \
		/bin/unlink

Bin_FreeBSD=	/bin/[ \
		/bin/chflags \
		/bin/chmod \
		/bin/cp \
		/bin/csh \
		/bin/date \
		/bin/expr \
		/bin/hostname \
		/bin/kill \
		/bin/link \
		/bin/ln \
		/bin/ls \
		/bin/mkdir \
		/bin/mv \
		/bin/pax \
		/bin/realpath \
		/bin/rm \
		/bin/rmdir \
		/bin/sh \
		/bin/sleep \
		/bin/test \
		/bin/unlink

# /usr/bin/awk    (lang/nawk)
# /usr/bin/cpio	  (archivers/libarchive)
# /usr/bin/bzip2* (archivers/bzip2)
# /usr/bin/cmp    (textproc/diffutils)
# /usr/bin/diff*  (textproc/diffutils)
# /usr/bin/grep*  (textproc/gnugrep)
# /usr/bin/fetch  (ftp/fetch)
# /usr/bin/file   (sysutils/file)
# /usr/bin/find   (misc/findutils)
# /usr/bin/flex*  (textproc/flex)
# /usr/bin/gzip*  (archivers/gzip)
# /usr/bin/xz*    (archivers/xz)
# /usr/bin/m4     (devel/m4)
# /usr/bin/make   (devel/bmake)
# /usr/bin/patch  (devel/patch)
# /usr/bin/sed    (textproc/gsed)
# /usr/bin/tar    (archivers/libarchive)
# /usr/bin/xargs  (misc/findutils)
# /usr/bin/yacc   (devel/byacc)
# TODO - rework uname

Usr_Bin_DragonFly= \
		/usr/bin/basename \
		/usr/bin/chgrp \
		/usr/sbin/chown \
		/usr/bin/comm \
		/usr/bin/cut \
		/usr/bin/dirname \
		/usr/bin/env \
		/usr/bin/head \
		/usr/bin/id \
		/usr/bin/install \
		/usr/bin/mkfifo \
		/usr/bin/mktemp \
		/usr/bin/tail \
		/usr/bin/tee \
		/usr/bin/touch \
		/usr/bin/tr \
		/usr/bin/tsort \
		/usr/bin/uname \
		/usr/bin/uniq \
		/usr/bin/wc 

Usr_Bin_FreeBSD=	${Usr_Bin_DragonFly}

static_lib_generic=	/usr/lib/libc.a \
			/usr/lib/libm.a \
			/usr/lib/libutil.a \
			/usr/lib/libpthread.a
static_lib_FreeBSD=	${static_lib_generic} \
			/usr/lib/libusb.a \
			/usr/lib/libusbhid.a
static_lib_DragonFly=	${static_lib_generic} \
			/usr/lib/libusb.a \
			/usr/lib/libusbhid.a
dynamic_generic=	/lib/${libc} \
			/lib/${libm} \
			/lib/${libutil} \
			/usr/lib/libpthread.so
dynamic_lib_FreeBSD=	${dynamic_generic} \
			/usr/lib/${libusb} \
			/usr/lib/${libusbhid}
dynamic_lib_DragonFly=	${dynamic_generic} \
			/usr/lib/libpthread.so.0 \
			/usr/lib/${libusb} \
			/usr/lib/${libusbhid}

posix_headers=		aio.h \
			arpa/inet.h \
			assert.h \
			complex.h \
			cpio.h \
			ctype.h \
			dirent.h \
			dlfcn.h \
			errno.h \
			fcntl.h \
			fenv.h \
			float.h \
			fmtmsg.h \
			fnmatch.h \
			ftw.h \
			glob.h \
			grp.h \
			iconv.h \
			inttypes.h \
			iso646.h \
			langinfo.h \
			libgen.h \
			limits.h \
			locale.h \
			math.h \
			monetary.h \
			mqueue.h \
			ndbm.h \
			net/if.h \
			netdb.h \
			netinet/in.h \
			netinet/tcp.h \
			nl_types.h \
			poll.h \
			pthread.h \
			pwd.h \
			regex.h \
			sched.h \
			search.h \
			semaphore.h \
			setjmp.h \
			signal.h \
			spawn.h \
			stdarg.h \
			stdbool.h \
			stddef.h \
			stdint.h \
			stdio.h \
			stdlib.h \
			string.h \
			strings.h \
			stropts.h \
			sys/ipc.h \
			sys/mman.h \
			sys/msg.h \
			sys/resource.h \
			sys/select.h \
			sys/sem.h \
			sys/shm.h \
			sys/socket.h \
			sys/stat.h \
			sys/statvfs.h \
			sys/time.h \
			sys/times.h \
			sys/types.h \
			sys/uio.h \
			sys/un.h \
			sys/utsname.h \
			sys/wait.h \
			syslog.h \
			tar.h \
			termios.h \
			tgmath.h \
			time.h \
			trace.h \
			ulimit.h \
			unistd.h \
			utime.h \
			utmpx.h \
			wchar.h \
			wctype.h \
			wordexp.h \
			# end

headers_FreeBSD=	${posix_headers:Nstropts.h:Ntrace.h} \
			# end
headers_DragonFly=	${posix_headers:Nstropts.h:Ntrace.h} \
			db.h \
			machine/cpumask.h \
			machine/endian.h \
			machine/fenv.h \
			machine/int_const.h \
			machine/int_limits.h \
			machine/inttypes.h \
			machine/limits.h \
			machine/setjmp.h \
			machine/stdarg.h \
			machine/stdint.h \
			machine/types.h \
			net/if_var.h \
			netinet6/in6.h \
			runetype.h \
			sys/_iovec.h \
			sys/_null.h \
			sys/_pthreadtypes.h \
			sys/_termios.h \
			sys/_timespec.h \
			sys/_timeval.h \
			sys/cdefs.h \
			sys/dirent.h \
			sys/fd_set.h \
			sys/file.h \
			sys/libkern.h \
			sys/limits.h \
			sys/lock.h \
			sys/malloc.h \
			sys/mqueue.h \
			sys/param.h \
			sys/sched.h \
			sys/signal.h \
			sys/stdint.h \
			sys/syslimits.h \
			sys/timespec.h \
			sys/ttycom.h \
			sys/ttydefaults.h \
			sys/unistd.h \
			sys/uuid.h \
			xlocale.h \
			xlocale/_ctype.h \
			xlocale/_langinfo.h \
			xlocale/_locale.h \
			xlocale/_monetary.h \
			xlocale/_stdlib.h \
			xlocale/_string.h \
			xlocale/_strings.h \
			xlocale/_time.h \
			xlocale/_wchar.h \
			# end

pcfiles_FreeBSD=	\
			# end
pcfiles_DragonFly=	libusb-0.1.pc \
			libusb-2.0.pc \
			libusb-1.0.pc \
			# end

sysroot:
	@echo "building not required"

install:
	${MKDIR} ${DESTDIR}/bin \
		${DESTDIR}/etc \
		${DESTDIR}/libexec \
		${DESTDIR}/usr/bin \
		${DESTDIR}/usr/include \
		${DESTDIR}/usr/lib/pkgconfig \
		${DESTDIR}/usr/share \
		${DESTDIR}/usr/local \
		${DESTDIR}/usr/include/arpa \
		${DESTDIR}/usr/include/sys \
		${DESTDIR}/usr/include/net \
		${DESTDIR}/usr/include/netinet \
		${DESTDIR}/usr/include/netinet6 \
		${DESTDIR}/usr/include/machine \
		${DESTDIR}/usr/include/xlocale \
		# end
.for item in ${Bin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ${item} ${DESTDIR}/bin/
.endfor
.for item in ${Usr_Bin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ${item} ${DESTDIR}/usr/bin/
.endfor
.for item in ${Libexec_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ${item} ${DESTDIR}/libexec/
.endfor
.for item in ${dynamic_lib_${OPSYS}}
	${BSD_INSTALL_LIB} ${item} ${DESTDIR}/usr/lib/
.endfor
.for item in ${static_lib_${OPSYS}}
	${BSD_INSTALL_DATA} ${item} ${DESTDIR}/usr/lib/
.endfor
	(cd ${DESTDIR}/usr/lib && \
		ln -s ${libc} libc.so && \
		ln -s ${libm} libm.so && \
		ln -s ${libutil} libutil.so)
.if ${OPSYS} == DragonFly || ${OPSYS} == FreeBSD
	(cd ${DESTDIR}/usr/lib && \
		ln -s ${libusb} libusb.so && \
		ln -s ${libusbhid} libusbhid.so)
.endif
	cp ${LOCALBASE}/bin/awk ${DESTDIR}/usr/bin/
.for item in ${dynamic_ln_${OPSYS}}
	(cd ${DESTDIR}/usr/lib
.endfor
.for item in ${pcfiles_${OPSYS}}
	${BSD_INSTALL_DATA} /usr/libdata/pkgconfig/${item} ${DESTDIR}/usr/lib/pkgconfig/
.endfor

.for item in bzip2 bunzip2 bzcat bzgrep bzegrep bzfgrep 
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}/usr/bin/
.endfor
.for item in cmp diff diff3 sdiff egrep fgrep grep fetch find file xargs
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}/usr/bin/
.endfor
	cp ${LOCALBASE}/bin/bmake   ${DESTDIR}/usr/bin/make
	cp ${LOCALBASE}/bin/bsdcat  ${DESTDIR}/bin/cat
	cp ${LOCALBASE}/bin/bsdcpio ${DESTDIR}/usr/bin/cpio
	cp ${LOCALBASE}/bin/bsdtar  ${DESTDIR}/usr/bin/tar
	cp ${LOCALBASE}/bin/md5     ${DESTDIR}/bin/
	cp ${LOCALBASE}/bin/sha256  ${DESTDIR}/bin/
.for item in flex flex++ gzip gunzip zcat zcmp zdiff zegrep zfgrep zgrep
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}/usr/bin/
.endfor
.for item in lzcat lzcmp lzdiff lzegrep lzfgrep lzgrep lzma unlzma unxz \
             xz xzcat xzcmp xzdiff xzegrep xzfgrep xzgrep
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}/usr/bin/
.endfor
.for item in m4 patch sed yacc
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}/usr/bin/
.endfor
	cp ${LOCALBASE}/lib/libdl.a ${DESTDIR}/usr/lib/
.for item in ${headers_${OPSYS}}
	${BSD_INSTALL_DATA} /usr/include/${item} ${DESTDIR}/usr/include/${item}
.endfor

extra-includes:
.for item in ${headers_${OPSYS}}
	@fgrep "#include" /usr/include/${item} || true
.endfor
