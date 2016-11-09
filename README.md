# demangle
A C++ name demangling command-line utility

# Requirements
GCC or Clang compiler, any version compatible with C++11

# Build
Assuming `$OUT_DIR` is the destination directory for the binary:
```
g++ -Wall -std=c++11 -O3 src/demangle.cpp -o $OUT_DIR/demangle
```
or
```
clang++ -Wall -std=c++11 -O3 src/demangle.cpp -o $OUT_DIR/demangle
```
