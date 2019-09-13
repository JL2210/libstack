#include <stack.h>
#include <stdlib.h>

int main(void)
{
    int err = 0;
    STACK_INIT(8);
    STACK_FINI();
    STACK_INIT(16);
    push(err);
    push(err);
    err = stack_resize(stack_global, 8);
    STACK_FINI();
    return err != 0;
}
