#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([aXe], [2.6], [help@stsci.edu])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_SRCDIR([config.h.in])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])

# Checks for programs.
AC_PROG_CC
AC_PROG_LIBTOOL

# Checks for libraries.
#AC_ARG_WITH(gsl, [AS_HELP_STRING([--with-gsl], [path to gsl])])
#AC_ARG_WITH(cfitsio, [AS_HELP_STRING([--with-cfitsio], [path to cfitsio])])
PKG_CHECK_MODULES([GSL], [gsl >= 1])
PKG_CHECK_MODULES([CFITSIO], [cfitsio >= 1])

AC_ARG_WITH(wcstools, [AS_HELP_STRING([--with-wcstools], [path to wcstools])])
AS_IF([test "x$with_wcstools" != "xno"], [
       if test ! -d "$withval"; then
           AC_MSG_ERROR([--with-wcstools requires a directory prefix])
       fi

       WCSTOOLS="$withval"
       ])

if test "x$WCSTOOLS" != "x"; then
     WCSTOOLS_LIBS="-L$WCSTOOLS/lib -lwcs"
     WCSTOOLS_CFLAGS="-I$WCSTOOLS/include"
     CFLAGS="$CFLAGS $WCSTOOLS_CFLAGS"
     LIBS="$LIBS $WCSTOOLS_LIBS"
dnl     AC_SEARCH_LIBS([wcsininit], [wcs], [], [
dnl                     AC_MSG_ERROR([unable to find wcsinit() function])
dnl                     ])
dnl     AC_CHECK_HEADERS([wcslib.h wcs.h])
else
    AC_MSG_ERROR([wtf happened])
fi

# Checks for header files.
AC_CHECK_HEADERS([limits.h stddef.h stdlib.h string.h unistd.h gsl.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_CHECK_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_STRTOD
AC_CHECK_FUNCS([floor pow rint sqrt strchr strdup strstr strtol])

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
