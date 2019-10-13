libstack
---

This is a stack abstraction written in ANSI C<sup>1</sup>.

It allows you to

  * create,

  * resize,

  * destroy,

  * push to,

  * pop from, and

  * peek into

a stack.

Documentation is located in `docs/`.

To build, use the usual idiom:

    $ ./configure
    $ make
    $ make install

libstack is licensed under the LGPLv2.1+.

 <sup>1</sup> Some features are only available with C99,
such as pushing constants to the stack.
