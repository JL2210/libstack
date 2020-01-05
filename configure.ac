AC_INIT([libstack], [1.0.0])
AC_CONFIG_MACRO_DIRS([m4])
AC_CONFIG_AUX_DIR([build-aux])

AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AM_PROG_AR

m4_include([m4/check_cflag.m4])

CHECK_CFLAG([-Wall])
CHECK_CFLAG([-Wextra])
CHECK_CFLAG([-Werror])
CHECK_CFLAG([-Wshadow])
CHECK_CFLAG([-Wrestrict])
CHECK_CFLAG([-Wformat=2])
CHECK_CFLAG([-Wlogical-op])
CHECK_CFLAG([-Wduplicated-cond])
CHECK_CFLAG([-Wdouble-promotion])
CHECK_CFLAG([-Wjump-misses-init])
CHECK_CFLAG([-Wnull-dereference])
CHECK_CFLAG([-Wduplicated-branches])
CHECK_CFLAG([-std=c89])
CHECK_CFLAG([-pedantic])

AC_SUBST([AM_CFLAGS])

LT_INIT

AC_CONFIG_FILES([
  Makefile
  src/Makefile
  include/Makefile
])

AC_OUTPUT
