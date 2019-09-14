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

#ifndef STACK_H
#define STACK_H 1

#include <stddef.h>

#define stack_op(var, op) stack_##op(&(var), sizeof(var), stack_global)
#define stack_op_r(var, op, stack) stack_##op(&(var), sizeof(var), (stack))

#define push(var) stack_op(var, push)
#define pop(var) stack_op(var, pop)
#define peek(var) stack_op(var, peek)
#define push_r(var, stack) stack_op_r(var, push, stack)
#define pop_r(var, stack) stack_op_r(var, pop, stack)
#define peek_r(var, stack) stack_op_r(var, peek, stack)

#define STACK_INIT(size) \
do { \
    STACK_FINI(); \
    stack_global = stack_create(size); \
} while(0)
#define STACK_INIT_R(size, name) \
do { \
    STACK_FINI_R(name); \
    name = stack_create(size); \
} while(0)
#define STACK_FINI() stack_destroy(stack_global)
#define STACK_FINI_R(name) stack_destroy(name)

#ifdef __cplusplus
extern "C" {
#endif

extern struct stack *stack_global;

extern struct stack *stack_create(size_t);
extern int stack_resize(struct stack *, size_t);
extern void stack_destroy(struct stack *);
extern void stack_push(void *, size_t, struct stack *);
extern void stack_pop(void *, size_t, struct stack *);
extern void stack_peek(void *, size_t, struct stack *);

#ifdef __cplusplus
}
#endif

#endif
