Cube
=====
Cube solver.

Code guide:

assembler.cpp: assembles cube face rotations into robot moves
cube.cpp: engine for simulating rubiks cubes
optimizer.cpp: pre computed optimizations for converting high level to low level
serial.cpp: serial comms
solution.cpp: solution algorithm
trie.cpp: implementation of a string->string radix tree


everything else: random tests, gui stuff, etc.  mostly undocumented, can be safely ignored.

NOTE
======
Since on OSX the gcc and g++ commands actually link to clang, for cross-platform compatibility, make sure code works in both clang and gcc
