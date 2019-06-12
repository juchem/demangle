#!/bin/sh

if [ -z "$1" ]; then
  echo "usage: $0 install_prefix"
  exit 1
fi

set -e

install_prefix="$1"
version_hash="`git log -1 --pretty=format:%H`"
build_dir="/tmp/demangle-${version_hash}.build"
source_dir="`pwd`"

if [ ! -d "$build_dir" ]; then
  mkdir -p "$build_dir"
fi

cmake -B "$build_dir" "$source_dir" "-DCMAKE_INSTALL_PREFIX=$install_prefix"
cmake --build "$build_dir" --target install
