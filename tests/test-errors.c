#include <stack.h>

int main(void)
{
#if defined PUSH_PAST_BOUNDS
    int a = 9;
    STACK_INIT(16);
    push(a);
    push(a);
    push(a);
    push(a);
    push(a);
    STACK_FINI(); /* unreachable */
#elif defined POP_PAST_BOUNDS
    int a;
    STACK_INIT(16);
    pop(a);
    STACK_FINI(); /* unreachable */
#elif defined CREATE_ZERO_SIZE
    STACK_INIT(0);
    STACK_FINI(); /* unreachable */
#elif defined RESIZE_ZERO_SIZE
    STACK_INIT(16);
    stack_resize(stack_global, 0);
    STACK_FINI(); /* unreachable */
#else
# error Please choose an error to test. \
        Options are one of: PUSH_PAST_BOUNDS, \
        POP_PAST_BOUNDS, CREATE_ZERO_SIZE, \
        RESIZE_ZERO_SIZE
#endif
}
