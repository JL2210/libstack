/*
 *  Copyright © 2019 James Larrowe
 *
 *  This file is part of libstack.
 *
 *  libstack is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 2.1 of the License, or
 *  (at your option) any later version.
 *
 *  libstack is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with libstack.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef STACK_INTERNAL_H
#define STACK_INTERNAL_H 1

#if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L
# if defined(__cplusplus) && __cplusplus >= 201103L
#  define noreturn [[noreturn]]
# else
#  ifdef __GNUC__
#   define noreturn __attribute__((__noreturn__))
#  else
#   define noreturn
#  endif
# endif
#else
# include <stdnoreturn.h>
#endif

#define ugly_cast(x) (x)

struct stack {
    char *beg;
    char *cur;
    char *end;
};

noreturn void stack_error(const char *);
void stack_warn(const char *);

#endif
