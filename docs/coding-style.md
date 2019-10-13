Coding style
---

The preferred coding style for this project includes the following:

spacing
---

  * 4 spaces of indentation

        if(x)
        {
            y(x);
        }
        while(z)
        {
            y(z--);
        }

  * no spaces directly after the keywords `if` and `while`.

    see above example

  * no spaces inside `if` or `while` unless there are multiple conditions

        if(x == y) { ... }

    and

        if( x == y && y < z ) { ... }

  * spaces inside for loops and after every semicolon

        for( x = 0; x < y; x++ )

  * when using labels, indent the label one less than the current indentation.

        int func(void)
        {
            bar(42);
        label:
            baz(bar(43));
            goto label;
        }

bracing
---

  * braces associated with control statements on next line except for

    `do { ... } while(...)`

    i.e.

        do {
            magic();
        } while(is_magical);
        if(is_magical)
        {
            confusion('?');
        }

  * function braces always on next line

        int foo(int bar)
        {
            return baz(bar);
        }

naming
---

  * `snake_case` is imperative. No 'if's, 'and's, or 'but's.

        int long_func_name(long parameter_name)
        {
            return parameter_name % INT_MAX;
        }

casting
---

  * casts must be done by using `cast` like so

        cast(type)expression

    or

        cast(type)(expressions)

preprocessor
---

  * files to be `#include`d are listed in order of length

        #include <stdio.h>
        #include <stack.h>
        #include <unistd.h>
        #include <string.h>
        #include <sys/mman.h>
        #include <sys/types.h>

  * indent nested preprocessor conditionals by one space.

        #if IS_AWESOME(preprocessor)
        # define THE_PREPROCESSOR_IS_AWESOME
        # ifdef THE_PREPROCESSOR_IS_NOT_AWESOME
        #  undef THE_PREPROCESSOR_IS_NOT_AWESOME
        # endif
        #endif

line length
---

  * maximum 80 characters

        iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii *= \
        shrt;
