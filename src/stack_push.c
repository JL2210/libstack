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

void stack_push(void *val, size_t size, struct stack *stack)
{
    if(ugly_cast(size_t)(stack->cur - stack->beg) < size)
    {
        stack_error("pushing past stack boundaries");
    }
    stack->cur -= size;
    memcpy(stack->cur, val, size);
}
