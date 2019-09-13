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

#include <stdio.h>
#include <stack.h>
#include <stdlib.h>
#include <string.h>

#include "stack_internal.h"

int stack_resize(struct stack *stack, size_t newsize)
{
    char *newptr;
    size_t oldsize, off;

    oldsize = ugly_cast(size_t)(stack->end - stack->beg);
    off = ugly_cast(size_t)(stack->cur - stack->beg);

    if(!newsize)
        stack_error("resizing stack to size 0");
    else if(newsize < 16)
        stack_warn("resizing stack to size less than 16");

    if(newsize < oldsize)
    {
        stack_warn("truncating stack");
    }
    if(off > newsize)
    {
        stack_warn("truncating offset into stack to new size");
        off = newsize;
    }

    newptr = realloc(stack->beg, newsize);

    if(!newptr)
    {
        free(stack->beg);
        return -1;
    }

    if(newsize > oldsize)
        memset(newptr + oldsize, 0, oldsize - newsize);

    stack->beg = newptr;
    stack->end = stack->beg + newsize;
    stack->cur = stack->beg + off;
    return 0;
}
