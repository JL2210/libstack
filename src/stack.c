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
#include <stdlib.h>
#include <string.h>

#include "stack.h"

/* make casts easier to search */
#define cast(x) (x)

/* stack structure */
struct stack
{
    /* beginning */
    unsigned char *beg;
    /* current pointer */
    unsigned char *cur;
    /* self-explanatory */
    unsigned char *end;
    size_t size;
};

struct stack *stack_create(size_t size)
{
    struct stack *ret;

    /* return NULL if size is zero */
    if(!size)
        return NULL;

    ret = malloc(sizeof(*ret));
    /* if malloc returned NULL, we skip this
       and return NULL */
    if(ret)
    {
        ret->beg = ret->cur = malloc(size);

        if(!ret->beg)
        {
            free(ret);
            return NULL;
        }

        ret->size = size;
        ret->end = ret->beg + size;
    }

    return ret;
}

int stack_resize(struct stack *stack, size_t newsize)
{
    unsigned char *newptr;
    size_t off;

    /* return error if newsize is 0 */
    if(!newsize)
        return -1;

    /* calculate offset */
    off = cast(size_t)(stack->cur - stack->beg);

    /* if offset is too big truncate it */
    if(off > newsize)
        off = newsize;

    newptr = realloc(stack->beg, newsize);

    if(!newptr)
        return -1;

    /* set the remaining bytes to 0 */
    if(newsize > stack->size)
        memset(newptr + stack->size, 0, newsize - stack->size);

    stack->beg = newptr;
    stack->size = newsize;
    stack->end = stack->beg + newsize;
    stack->cur = stack->beg + off;
    return 0;
}

void stack_destroy(struct stack *stack)
{
    if(stack)
        free(stack->beg);
    free(stack);
}

int stack_push(void *val, size_t size, struct stack *stack)
{
    /* if there's not enough space left return an error */
    if(cast(size_t)(stack->end - stack->cur) < size)
        return -1;

    memcpy(stack->cur, val, size);
    stack->cur += size;
    return 0;
}

int stack_pop(void *val, size_t size, struct stack *stack)
{
    /* if there's not enough data left return an error */
    if(cast(size_t)(stack->cur - stack->beg) < size)
        return -1;

    stack->cur -= size;
    memcpy(val, stack->cur, size);
    return 0;
}

int stack_peek(void *val, size_t size, struct stack *stack)
{
    /* this function has no errors */
    memcpy(val, stack->cur, size);
    return 0;
}
