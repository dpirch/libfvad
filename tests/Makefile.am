
check_LTLIBRARIES = libtest.la
libtest_la_SOURCES = test.h test.c
libtest_la_LIBADD = ../src/libfvad_int.la

noinst_HEADERS = vad_unittest.h

check_PROGRAMS = \
	spl_macro_unittest \
	spl_inline_unittest \
	spl_math_operations_unittest \
	spl_signal_processing_unittest \
	spl_resample_48_unittest


TESTS = $(check_PROGRAMS)

LDADD = libtest.la

spl_macro_unittest_SOURCES = signal_processing_unittest.c
spl_macro_unittest_CPPFLAGS = -DTEST_SPL_MACRO

spl_inline_unittest_SOURCES = signal_processing_unittest.c
spl_inline_unittest_CPPFLAGS = -DTEST_SPL_INLINE

spl_math_operations_unittest_SOURCES = signal_processing_unittest.c
spl_math_operations_unittest_CPPFLAGS = -DTEST_SPL_MATH_OPERATIONS

spl_signal_processing_unittest_SOURCES = signal_processing_unittest.c
spl_signal_processing_unittest_CPPFLAGS = -DTEST_SPL_SIGNAL_PROCESSING

spl_resample_48_unittest_SOURCES = signal_processing_unittest.c
spl_resample_48_unittest_CPPFLAGS = -DTEST_SPL_RESAMPLE_48

