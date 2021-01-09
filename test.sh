#!/usr/bin/env bash
set -euo pipefail

dotest() {
  rm -rf build
  mkdir build && pushd build
  cmake -G "MSYS Makefiles" "$@" ..
  make
  ./dohang
  popd
}

pacman -S --needed --noconfirm \
  patch \
  make \
  mingw-w64-x86_64-cmake \
  mingw-w64-x86_64-gcc \
  mingw-w64-x86_64-libbotan

# won't hang (static lib)
dotest -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=off
# will hang (shared lib)
dotest -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=on

