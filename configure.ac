AC_INIT([libfvad],[1.0],[dpirch@gmail.com],[],[http://example.com/TODO])
AC_CONFIG_SRCDIR([src/fvad.c])
AC_CONFIG_AUX_DIR([ac-aux])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([
    -Wall -Wno-extra-portability foreign subdir-objects
    tar-pax no-dist-gzip dist-xz
])

AC_PROG_CC
AX_APPEND_COMPILE_FLAGS([-std=c11 -Wall -Wpedantic])
AC_PROG_CC_STDC

LT_INIT([disable-static pic-only])

### output ###
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile libfvad.pc])
AC_OUTPUT
