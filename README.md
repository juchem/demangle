# demangle
A C++ name demangling command-line utility

# Limitations
Only works for mangled symbols that follow GCC's ABI, like Clang and GCC

# Usage
Symbols to be demangled can be given either to `stdin` or through command-line arguments:
```
$ echo 'i N3foo3barIJidEEE' | ./demangle
int
foo::bar<int, double>

$ echo -e 'i\nN3foo3barIJidEEE' | ./demangle
int
foo::bar<int, double>

$ ./demangle i N3foo3barIJidEEE
int
foo::bar<int, double>
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
