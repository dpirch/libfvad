if BUILD_EXAMPLES
  examples_dir = examples
endif

SUBDIRS = src $(examples_dir) tests
ACLOCAL_AMFLAGS = -I m4
EXTRA_DIST = bootstrap LICENSE PATENTS README.md tools

# install pkgconfig file
pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libfvad.pc

# install public header file
include_HEADERS = include/fvad.h

