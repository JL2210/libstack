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
#include <stdint.h>

#define cast(x) (x)

struct stack {
    uint8_t *beg;
    uint8_t *cur;
    uint8_t *end;
    size_t size;
};

struct stack *stack_create(size_t size)
{
    struct stack *ret;

    if(!size)
        return NULL;

    ret = malloc(sizeof(*ret));
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
    uint8_t *newptr;
    size_t off;

    if(!newsize)
        return -1;

    off = cast(size_t)(stack->cur - stack->beg);

    if(off > newsize)
        off = newsize;

    newptr = realloc(stack->beg, newsize);

    if(!newptr)
        return -1;

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
    if(cast(size_t)(stack->end - stack->cur) < size)
        return -1;

    memcpy(stack->cur, val, size);
    stack->cur += size;
    return 0;
}

int stack_pop(void *val, size_t size, struct stack *stack)
{
    if(cast(size_t)(stack->cur - stack->beg) < size)
        return -1;

    stack->cur -= size;
    memcpy(val, stack->cur, size);
    return 0;
}

int stack_peek(void *val, size_t size, struct stack *stack)
{
    memcpy(val, stack->cur, size);
    return 0;
}
