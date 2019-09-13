#include <stdio.h>
#include <stack.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 16

int main(void)
{
    int a[SIZE], b[SIZE], c;
    for(c = 0; c < SIZE; c++)
        a[c] = rand() & (SIZE-1);
    STACK_INIT(SIZE*sizeof(int));
    push(a);
    pop(b);
    for(c = 0; c < SIZE; c++)
        printf("a[c]=%d, b[c]=%d\n", a[c], b[c]);
    STACK_FINI();
    return memcmp(a, b, sizeof(a));
}
