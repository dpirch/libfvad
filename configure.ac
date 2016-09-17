AC_INIT([libfvad],[1.0],[dpirch@gmail.com],[],[https://github.com/dpirch/libfvad])
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

# optional examples, requires libsndfile
AC_ARG_ENABLE([examples],
    [AS_HELP_STRING([--enable-examples],
        [build the fvadwav example program; requires libsndfile @<:@default=no@:>@])])

AS_IF([test "x$enable_examples" = xyes],
    [PKG_CHECK_MODULES([sndfile], [sndfile])],
    [enable_examples=no])

AM_CONDITIONAL([BUILD_EXAMPLES], [test "x$enable_examples" = xyes])

### output ###
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile examples/Makefile tests/Makefile libfvad.pc])
AC_OUTPUT

AC_MSG_RESULT([
    $PACKAGE $VERSION
    ===========

    source code location:   $srcdir
    installation prefix:    $prefix
    compiler:               $CC
    cflags:                 $CFLAGS

    build examples:         $enable_examples
])
