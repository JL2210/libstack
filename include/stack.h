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

#ifdef __cplusplus
extern "C" {
#endif

struct stack;

/* size: size of the stack to create
 * return: NULL on error, pointer to
 *         struct stack otherwise
 */
struct stack *stack_create(size_t size);
/* stack: the stack to resize
 * new_size: the new size of the stack
 * return: 0 on success, -1 on failure
 */
int stack_resize(struct stack *stack, size_t new_size);
/* stack: the stack to destroy
 * return: none
 */
void stack_destroy(struct stack *stack);
/* size: size of memory to be copied to/from the stack
 * stack: the stack to push/pop/peek to/from/into
 * return: -1 on error, 0 on success
 */
int stack_push(void *input, size_t size, struct stack *stack);
int stack_pop(void *output, size_t size, struct stack *stack);
int stack_peek(void *output, size_t size, struct stack *stack);

#ifdef __cplusplus
}
#endif

#endif
