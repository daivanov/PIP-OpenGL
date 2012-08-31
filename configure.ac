AC_INIT(pip-opengl, 0.1, daniil.ivanov@gmail.com)
AC_CONFIG_SRCDIR(src/main.c)

AM_INIT_AUTOMAKE

AC_PROG_CC_C99

AC_CHECK_LIB([m], [cos])
AC_CHECK_LIB([glut], [glutInit])
AC_SUBST(GLUT_INCLUDES, $INCLUDES)
AC_SUBST(GLUT_LIBS, $LIBS)

PKG_CHECK_MODULES([GL], [gl])

AC_CONFIG_FILES(Makefile src/Makefile)
AC_OUTPUT
