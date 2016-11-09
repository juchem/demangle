# demangle
A C++ name demangling command-line utility

# Limitations
Only works for mangled symbols that follow GCC's ABI, like Clang and GCC

# Usage
Symbols to be demangled can be given either to `stdin` or through command-line arguments:
```
$ echo i | ./demangle
int

$ ./demangle i
int
```

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
