#include <stdio.h>
#include <stack.h>

int main(void)
{
    int a = 16;
    STACK_INIT(16);
/* XXX: Doesn't work.
 *      Using compount literal for now.
    push(16);
 */
    push((int){' '});
    pop(a);
    printf("a=%d\n", a);
    STACK_FINI();
    return a == 16;
}
