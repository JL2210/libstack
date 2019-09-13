#include <stdio.h>
#include <stack.h>

int main(void)
{
    int a = 16, b = 32;
    STACK_INIT(16);
    push(a);
    push(b);
    pop(a);
    pop(b);
    printf("a=%d, b=%d\n", a, b);
    STACK_FINI();
    return a != 32 || b != 16;
}
