# FUNCTIONS

stack_create
---

    struct stack *stack_create(size_t size)

`stack_create` creates a new `stack` structure with an
internal buffer of size `size`.

On success, this function returns a pointer to the `stack`
structure created.

On failue, this function returns `NULL`.

If `size` is zero, this function will emit a runtime error and abort.

If `size` is less than 16, this function will emit a runtime warning.

stack_resize
---

    int stack_resize(struct stack *stack, size_t newsize)

`stack_resize` resizes `stack` to `newsize`.

This function returns `0` on success and `-1` on failure.

If `newsize` is zero, this function will emit a runtime error and abort.

If `newsize` is less than 16, this function will emit a runtime warning.

If `newsize` is less than the previous
size of the stack, then this function will
emit a runtime warning.

If the previous offset of the pointer into the stack was greater
than the new size of the stack, this function will emit a runtime
warning and truncate the offset into the stack to the new size.

If `newsize` is greater than the previous size of the stack,
this function will set the remaining bytes in the stack to zero.

stack_destroy
---

    void stack_destroy(struct stack *stack)

`stack_destroy` destroys `stack`.

It also frees the internal buffer inside
`stack` if `stack` is not a `NULL` pointer.

stack_push
---

    int stack_push(void *val, size_t size, struct stack *stack)

`stack_push` pushes `size` bytes from `val` onto `stack`.

If there is not enough space left in `stack` to satisfy this request,
this function will emit a runtime error and abort.

This function first subtracts `size` bytes from the internal buffer
contained within `stack` and then copies `size` bytes from `val` to
the new value of the buffer.

stack_pop
---

    int stack_pop(void *val, size_t size, struct stack *stack)

`stack_push` pops `size` bytes from `stack` into `val`.

If there is not enough data left in `stack` to satisfy this request,
this function will return -1.

This function first copies `size` bytes from the internal buffer
contained within `stack` to `val` and then adds `size` bytes to
the internal buffer contained within `stack`.

stack_peek
---

    int stack_peek(void *val, size_t size, struct stack *stack)

`stack_peek` copies `size` bytes from `stack` into `val`.

This function always returns 0.

This stack copies `size` bytes from the internal buffer
contained within `stack`. `stack` is not modified.

# MISCELLANEOUS

You currently cannot push a constant to the stack.
As a workaround, use C99's compund literals.

invalid:

        stack_push((var)constant, sizeof(constant), stack);

valid:

        stack_push((var[1]){constant}, sizeof(constant), stack);
