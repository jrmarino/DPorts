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
		/bin/date \
		/bin/expr \
		/bin/hostname \
		/bin/kill \
		/bin/link \
		/bin/ln \
		/usr/share/initrd/bin/ls \
		/bin/mkdir \
		/bin/mv \
		/bin/pax \
		/bin/realpath \
		/bin/rm \
		/bin/rmdir \
		/usr/share/initrd/bin/sh \
		/bin/sleep \
		/bin/test \
		/bin/unlink

Bin_FreeBSD=	/bin/[ \
		/bin/chflags \
		/bin/chmod \
		/bin/cp \
		/bin/date \
		/bin/expr \
		/bin/hostname \
		/bin/kill \
		/bin/link \
		/bin/ln \
		/rescue/ls \
		/bin/mkdir \
		/bin/mv \
		/bin/pax \
		/bin/realpath \
		/bin/rm \
		/bin/rmdir \
		/rescue/sh \
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
# /usr/bin/uname  (sysutils/uname)
# /usr/bin/unzip  (archivers/unzip)
# /usr/bin/xz*    (archivers/xz)
# /usr/bin/m4     (devel/m4)
# /usr/bin/make   (devel/bmake)
# /usr/bin/patch  (devel/patch)
# /usr/bin/sed    (textproc/gsed)
# /usr/bin/tar    (archivers/libarchive)
# /usr/bin/xargs  (misc/findutils)
# /usr/bin/yacc   (devel/byacc)
# /usr/bin/less*  (sysutils/less)
# /usr/bin/mtree  (sysutils/mtree)
# /usr/bin/sort   (sysutils/coreutils)
# /usr/bin/pkg-static (ports-mgmt/pkg)

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
		/usr/bin/ldd \
		/usr/bin/mkfifo \
		/usr/bin/mktemp \
		/usr/bin/printenv \
		/usr/bin/readlink \
		/usr/bin/stat \
		/usr/bin/tail \
		/usr/bin/tee \
		/usr/bin/touch \
		/usr/bin/tr \
		/usr/bin/tsort \
		/usr/bin/uniq \
		/usr/bin/wc \
		/usr/bin/which \
		# end

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
			/usr/lib/libusbhid.a \
			/usr/lib/crt1.o \
			/usr/lib/crti.o \
			/usr/lib/crtn.o
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
			libutil.h \
			pthread_np.h \
			usb.h \
			usbhid.h \
			# end
headers_DragonFly=	${posix_headers:Nstropts.h:Ntrace.h} \
			libutil.h \
			pthread_np.h \
			usb.h \
			usbhid.h \
			ar.h \
			db.h \
			err.h \
			cpu/atomic.h \
			cpu/types.h \
			machine/cpumask.h \
			machine/endian.h \
			machine/fenv.h \
			machine/int_const.h \
			machine/int_limits.h \
			machine/inttypes.h \
			machine/limits.h \
			machine/setjmp.h \
			machine/signal.h \
			machine/stdarg.h \
			machine/stdint.h \
			machine/trap.h \
			machine/types.h \
			machine/ucontext.h \
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
			sys/ucontext.h \
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
	${MKDIR} ${DESTDIR}${BASE}/bin \
		${DESTDIR}${BASE}/libexec \
		${DESTDIR}${BASE}/usr/bin \
		${DESTDIR}${BASE}/usr/include \
		${DESTDIR}${BASE}/usr/lib/pkgconfig \
		${DESTDIR}${BASE}/usr/share \
		${DESTDIR}${BASE}/usr/local \
		${DESTDIR}${BASE}/usr/include/arpa \
		${DESTDIR}${BASE}/usr/include/cpu \
		${DESTDIR}${BASE}/usr/include/sys \
		${DESTDIR}${BASE}/usr/include/net \
		${DESTDIR}${BASE}/usr/include/netinet \
		${DESTDIR}${BASE}/usr/include/netinet6 \
		${DESTDIR}${BASE}/usr/include/machine \
		${DESTDIR}${BASE}/usr/include/xlocale \
		# end
.for item in ${Bin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ${item} ${DESTDIR}${BASE}/bin/
.endfor
.for item in ${Usr_Bin_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
.for item in ${Libexec_${OPSYS}}
	${BSD_INSTALL_PROGRAM} ${item} ${DESTDIR}${BASE}/libexec/
.endfor
.for item in ${dynamic_lib_${OPSYS}}
	${BSD_INSTALL_LIB} ${item} ${DESTDIR}${BASE}/usr/lib/
.endfor
.for item in ${static_lib_${OPSYS}}
	${BSD_INSTALL_DATA} ${item} ${DESTDIR}${BASE}/usr/lib/
.endfor
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s ${libc} libc.so && \
		ln -s ${libm} libm.so && \
		ln -s ${libutil} libutil.so)
.if ${OPSYS} == DragonFly || ${OPSYS} == FreeBSD
	(cd ${DESTDIR}${BASE}/usr/lib && \
		ln -s ${libusb} libusb.so && \
		ln -s ${libusbhid} libusbhid.so)
.endif
	cp ${LOCALBASE}/bin/awk ${DESTDIR}${BASE}/usr/bin/
.for item in ${dynamic_ln_${OPSYS}}
	(cd ${DESTDIR}${BASE}/usr/lib
.endfor
.for item in ${pcfiles_${OPSYS}}
	${BSD_INSTALL_DATA} /usr/libdata/pkgconfig/${item} ${DESTDIR}${BASE}/usr/lib/pkgconfig/
.endfor

.for item in bzip2 bunzip2 bzcat bzgrep bzegrep bzfgrep 
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
.for item in cmp diff diff3 sdiff grep fetch find file xargs
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
	cp ${LOCALBASE}/bin/bmake   ${DESTDIR}${BASE}/usr/bin/make
	cp ${LOCALBASE}/bin/bsdcpio ${DESTDIR}${BASE}/usr/bin/cpio
	cp ${LOCALBASE}/bin/bsdtar  ${DESTDIR}${BASE}/usr/bin/tar
	cp ${LOCALBASE}/bin/md5     ${DESTDIR}${BASE}/bin/
	cp ${LOCALBASE}/bin/sha256  ${DESTDIR}${BASE}/bin/
.for item in flex flex++ gzip gunzip zcat zcmp zdiff zegrep zfgrep zgrep
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
.for item in lzcat lzcmp lzdiff lzegrep lzfgrep lzgrep lzma unlzma unxz \
             xz xzcat xzcmp xzdiff xzegrep xzfgrep xzgrep
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
.for item in m4 patch sed yacc uname unzip less vi mtree bsdcat
	cp ${LOCALBASE}/bin/${item} ${DESTDIR}${BASE}/usr/bin/
.endfor
	cp ${LOCALBASE}/lib/libdl.a ${DESTDIR}${BASE}/usr/lib/
	cp ${LOCALBASE}/bin/less    ${DESTDIR}${BASE}/usr/bin/more
.for item in ${headers_${OPSYS}}
	${BSD_INSTALL_DATA} /usr/include/${item} ${DESTDIR}${BASE}/usr/include/${item}
.endfor
	cp ${LOCALBASE}/share/misc/terminfo.db.default ${DESTDIR}${BASE}/usr/share/terminfo.db
	cp ${LOCALBASE}/bin/gsort ${DESTDIR}${BASE}/usr/bin/sort
	cp ${LOCALBASE}/bin/gcat  ${DESTDIR}${BASE}/bin/cat
	cp ${LOCALBASE}/sbin/pkg-static ${DESTDIR}${BASE}/usr/bin/
	sed -e 's|/usr/local|/usr|g' ${LOCALBASE}/bin/egrep > ${DESTDIR}${BASE}/usr/bin/egrep
	sed -e 's|/usr/local|/usr|g' ${LOCALBASE}/bin/fgrep > ${DESTDIR}${BASE}/usr/bin/fgrep
	chmod 755 ${DESTDIR}${BASE}/usr/bin/egrep ${DESTDIR}${BASE}/usr/bin/fgrep

extra-includes:
.for item in ${headers_${OPSYS}}
	@fgrep "#include" /usr/include/${item} || true
.endfor
