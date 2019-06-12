# demangle
A C++ name demangling command-line utility.

# Limitations
Only works for mangled symbols that follow the [Itanium C++ ABI](https://itanium-cxx-abi.github.io/cxx-abi/abi.html#mangling), like Clang and GCC.

# Usage
Symbols to be demangled can be given to `stdin` or as command line arguments.

Default output follows the format `mangled\tdemangled`:
```sh
3fooIJiEE	foo<int>
```

# Examples:
Symbol passed to `stdin`.
```sh
$ echo 'N3foo3barIJidEEE' | demangle
N3foo3barIJidEEE	foo::bar<int, double>
```

Symbol passed as command line argument:
```sh
$ demangle N3foo3barIJidEEE
N3foo3barIJidEEE	foo::bar<int, double>
```

Multiple symbols passed to `stdin`:
```sh
$ echo 'i N3foo3barIJidEEE' | demangle
i	int
N3foo3barIJidEEE	foo::bar<int, double>
```

Multiple symbols passed as command line arguments:
```sh
$ demangle i N3foo3barIJidEEE
i	int
N3foo3barIJidEEE	foo::bar<int, double>
```

Filtering error messages when demangling symbols mixed with other text:
```sh
$ echo 'i N3foo3barIJidEEE this_is_not_a_valid_symbol' | demangle 2> /dev/null
i	int
N3foo3barIJidEEE	foo::bar<int, double>
```

# Build requirements
GCC or Clang compiler, any version compatible with C++11.

# Installation instructions

## Easy mode
Provided you have `cmake` installed, run `./build.sh install_directory`.
```sh
./build.sh /usr/local
```

## `cmake`
Replace `$INSTALL_DIRECTORY` below with the install directory of your choice.
```sh
cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIRECTORY
make install
```

# Build instructions

## `cmake`
```sh
mkdir out && cd out
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
