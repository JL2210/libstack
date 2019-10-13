AC_DEFUN([CHECK_CFLAG], [
AC_MSG_CHECKING(whether the C compiler understands $1)
old_AM_CFLAGS="$AM_CFLAGS"
AM_CFLAGS="$AM_CFLAGS $1"
old_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS $AM_CFLAGS"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],[])],
  AC_MSG_RESULT(yes)
  CFLAGS="$old_CFLAGS",
  AC_MSG_RESULT(no)
  CFLAGS="$old_CFLAGS"
  AM_CFLAGS="$old_AM_CFLAGS")])

