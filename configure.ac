#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libnspire], [0.01], [tangrs@tangrs.id.au])
AC_CONFIG_SRCDIR([src/init.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.
PKG_CHECK_MODULES(USB, libusb-1.0 >= 1.0.0)
AC_SUBST(USB_CFLAGS)
AC_SUBST(USB_LIBS)

# Checks for header files.
AC_CHECK_HEADERS([inttypes.h stddef.h stdint.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T

AC_C_BIGENDIAN(
	[AC_DEFINE([ENDIAN_BIG], [], [Define for big endian machines])],
	[AC_DEFINE([ENDIAN_LITTLE], [], [Define for little endian machines])],
	[AC_ERROR([Unknown endian])])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memchr memmove memset])

AC_CONFIG_FILES([Makefile src/Makefile src/api/Makefile libnspire.pc])
AC_OUTPUT
