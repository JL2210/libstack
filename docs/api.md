# FUNCTIONS

`stack_create`
---

    struct stack *stack_create(size_t size)

`stack_create` creates a new `stack` structure with an
internal buffer of size `size`.

On failure, this function returns `NULL`; otherwise, it returns
a pointer to the `stack` structure created.

This function fails if:

  1. `size` is zero, or

  2. allocation fails.

`stack_resize`
---

    int stack_resize(struct stack *stack, size_t newsize)

`stack_resize` resizes `stack` to `newsize`.

On failure, this function returns `-1`; otherwise, it
returns `0`.

This function fails if:

  1. `newsize` is zero, or

  2. allocation fails.

If the offset into the stack is greater than the size of
the stack after the resize it is truncated to the size of
the stack.

If `newsize` is greater than the previous size of the stack,
this function will set the remaining bytes in the stack to zero.

`stack_destroy`
---

    void stack_destroy(struct stack *stack)

`stack_destroy` destroys `stack`.

It frees the internal buffer inside `stack` and `stack` itself.

Do *not* attempt to access `stack` after calling this function!

`stack_push`
---

    int stack_push(void *val, size_t size, struct stack *stack)

`stack_push` pushes `size` bytes from `val` onto `stack`.

On error, this function returns `-1`; otherwise, it returns `0`.

This function fails if there is not enough space left in `stack`
to satisfy the request.

`stack_pop`
---

    int stack_pop(void *val, size_t size, struct stack *stack)

`stack_push` pops `size` bytes from `stack` into `val`.

On error, this function returns `-1`; otherwise, it returns `0`.

This function fails if there is not enough data left in `stack`
to satisfy this request.

`stack_peek`
---

    int stack_peek(void *val, size_t size, struct stack *stack)

`stack_peek` copies `size` bytes from `stack` into `val`.

This function always returns `0`. It returns a value to
maintain signature compatibility with `stack_push` and
`stack_pop`.

This function does not modify `stack`.

# MISCELLANEOUS

To push a constant to the stack, use compund literals.

        stack_push((var[1]){constant}, sizeof(constant), stack);
