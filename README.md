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

## Why are we being so heavy handed

Because academic teaching of C++ is often a terrible mish-mash of old
fashioned idioms, and we don't want to get a bad reputation. There's nothing wrong
with using pointers when they are necessary, but they are dangerous.
Use them when needed, but if you're doing it because the proper way
"looks hard" don't say we told you it was OK!

