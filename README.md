# CPP4Researchers-Pointers
Pointers in C++: why, how and also why not

Using and manipulating so-called "bare pointers", which can be thought of as roughly a memory address,
is not something we should often do in modern C++.
However, they do come up in some places - codes that are very C-like, Cuda code,
code that links with Fortran or with Python wrappers, and some old codes, so we may have no choice.

This workshop and repository covers what pointers are, and where you might see them.
It shows the proper modern C++ ways to do the jobs pointers used to be needed for,
and it explains how these mitigate many of the risks associated with them.

Because we are including both recommended ways to do things, and necessary
evils for some situations, we place a comment at the top of all code files
so there can be no doubt.
This will be:
* /\* UP TO DATE \*/ - compliant with the latest C++ spirit
* /\* OLD SCHOOL \*/ - uses old fashioned, C like style
* /\* PLAIN WRONG \*/ - uses stuff that just will not work in general

## Why are we being so heavy handed

Because academic teaching of C++ is often a terrible mish-mash of old
fashioned idioms, and we don't want to get a bad reputation. There's nothing wrong
with using pointers when they are necessary, but they are dangerous.
Use them when needed, but if you're doing it because the proper way
"looks hard" don't say we told you it was OK!

## Why do some of your codes work when you say they don't?

Undefined behaviour is... undefined. Since it can do anything, sometimes
the thing it does is exactly what you'd want and expect.
This is a very BAD THING because it means we can invoke undefined behaviour
and not notice it. So if you run our examples, sometimes the things we
say are wrong might seem to be right. If you can, try some different
compilers, or different operating systems. Change the optimisation level,
particularly up to O2 or O3. We promise they will go wrong eventually, but
compiler writers aren't _trying_ to make strange things happen. They just happen
as a consequence of complicated combinations.

