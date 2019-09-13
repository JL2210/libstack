#include <stdio.h>
#include <stack.h>

int main(void)
{
    int a = 16, b = 32;
    struct stack *stack = 0;
    STACK_INIT_R(32, stack);
    push_r(a, stack);
    push_r(b, stack);
    pop_r(a, stack);
    pop_r(b, stack);
    printf("a=%d, b=%d\n", a, b);
    STACK_FINI_R(stack);
    return a != 32 || b != 16;
}
