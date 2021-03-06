# Copyright 2011 University Corporation for Atmospheric Research
#
# This file is part of the Unidata NOAAPORT package.  See the file COPYRIGHT in
# the top-level source-directory of the package for copying and redistribution
# conditions.
#
## Process this file with automake(1) to produce file Makefile.in

LDMHOME			= @LDMHOME@

SUBDIRS			= tables
CLEANFILES		=
DISTCLEANFILES		=
BUILT_SOURCES		=

noinst_LTLIBRARIES	= lib.la
lib_la_SOURCES		= cflclos.c \
                          cflinqr.c \
                          cfliret.c \
                          cflpath.c \
                          cflropn.c \
                          cfltbnr.c \
                          cfltbop.c \
                          cfltinq.c \
                          cfltrln.c \
                          cssenvr.c \
                          cstctoi.c \
                          cstinch.c \
                          cstitoc.c \
                          cstlcuc.c \
                          cstldsp.c \
                          cstlstr.c \
                          cstncat.c \
                          cstncpy.c \
                          cstnocc.c \
                          cstrmbl.c \
                          cstrmst.c \
                          cstrpst.c \
                          cstrxbl.c \
                          cstsplit.c \
                          cstuclc.c \
                          ctbcmn.h \
                          ctbg2gnam.c \
                          ctbg2gnum.c \
                          ctbg2rdcntr.c \
                          ctbg2rdlvl.c \
                          ctbg2rdvar.c \
                          ctbg2rdvar.h \
                          ctbg2read.c \
                          decode_g2gnum.c \
                          error.h \
                          erwmsg.c \
                          gb22gem.c \
                          gb2ctim.c \
                          gb2def.h \
                          gb2fcsm.c \
                          gb2ftim.c \
                          gb2gtcntr.c \
                          gb2gtlcllvltbl.c \
                          gb2gtlclvartbl.c \
                          gb2gtvartbl.c \
                          gb2gtwmolvltbl.c \
                          gb2gtwmovartbl.c \
                          gb2param.c \
                          gb2prob.c \
                          gb2proc.c \
                          gb2sklvl.c \
                          gb2skvar.c \
                          gb2vcrd.c \
                          gb2vlev.c \
                          gbcmn.h \
                          geminc.h \
                          gemprm.h \
                          lvcord.c \
                          proto_cgemlib.h \
                          proto_gemlib.h \
                          proto.h \
                          tgitoc.c \
                          tiaddm.c \
                          tidaym.c \
                          tiitoj.c \
                          timdif.c

AM_CPPFLAGS	= -DLDMHOME='"$(LDMHOME)"' \
		  -I$(top_srcdir) \
		  -I$(top_srcdir)/grib2 \
		  -I$(top_srcdir)/log \
		  -I$(top_builddir)/protocol -I$(top_srcdir)/protocol \
		  -I$(top_builddir)/protocol2 -I$(top_srcdir)/protocol2 \
		  -I$(top_builddir)/registry -I$(top_srcdir)/registry \
		  -I$(top_builddir)/mcast_lib/ldm7

TAGS_FILES		= *.c *.h \
                          ../log/*.c ../log/*.h \
                          ../grib2/*.c ../grib2/*.h

if HAVE_OPMOCK

CLEANFILES		+= TEST-test.xml
OPMOCK_INCLUDES 	= -I/usr/lib/gcc/x86_64-redhat-linux/4.8.3/include \
			  -I/usr/include/c++/4.8.3 \
                          -I/usr/local/include \
                          -I/usr/include

CTBG2RDVAR_STUBS	= ctbg2rdvar_stub.c ctbg2rdvar_stub.h
BUILT_SOURCES		+= $(CTBG2RDVAR_STUBS)
DISTCLEANFILES		+= $(CTBG2RDVAR_STUBS)

$(CTBG2RDVAR_STUBS):	ctbg2rdvar.h
	opmock2 -i $? -o . $(AM_CPPFLAGS) $(CPPFLAGS) $(OPMOCK_INCLUDES)

# Put "*_stub.*" files in "nodist_*_SOURCES" macros because "make distcheck"
# expects "*_SOURCES" files without a "nodist_" prefix to exist.

gb2gtvartbl_test_SOURCES 	= gb2gtvartbl_test.c
nodist_gb2gtvartbl_test_SOURCES = $(CTBG2RDVAR_STUBS)
gb2gtvartbl_test_CPPFLAGS	= $(AM_CPPFLAGS) @OPMOCK_CPPFLAGS@
gb2gtvartbl_test_LDFLAGS	= @OPMOCK_LDFLAGS@
gb2gtvartbl_test_LDADD  	= $(top_builddir)/lib/libldm.la \
                                  @OPMOCK_LDADD@

check_PROGRAMS			= gb2gtvartbl_test
TESTS				= gb2gtvartbl_test

endif
