# demangle
A C++ name demangling command-line utility

# Limitations
Only works for mangled symbols that follow GCC's ABI, like Clang and GCC

# Usage
Symbols to be demangled can be given through `stdin`:
```sh
$ echo 'i N3foo3barIJidEEE' | demangle
int
foo::bar<int, double>
```

Multiple symbols can be passed as multiple lines in `stdin`:
```sh
$ echo -e 'i\nN3foo3barIJidEEE' | demangle
int
foo::bar<int, double>
```

Symbols can be passed as command line arguments:
```sh
$ demangle i N3foo3barIJidEEE
int
foo::bar<int, double>
```

Demangle can be used in mixed text by filtering out error messages:
```sh
cat some_log_with_mangled_symbols.txt | demangle 2> /dev/null
```

# Requirements
GCC or Clang compiler, any version compatible with C++11

# Install

## Easy mode
Provided you have `cmake` installed, run `./build.sh install_directory`.

Example:
```sh
./build.sh /usr/local
```

## `cmake`
```sh
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIRECTORY
make install
```

# Build

## `cmake`
```sh
mkdir out
cmake ..
make
```

## Manual build
Assuming `$OUT_DIR` is the destination directory for the binary:
```sh
g++ -Wall -std=c++11 -O3 src/demangle.cpp -o $OUT_DIR/demangle
```
or
```sh
clang++ -Wall -std=c++11 -O3 src/demangle.cpp -o $OUT_DIR/demangle
```
