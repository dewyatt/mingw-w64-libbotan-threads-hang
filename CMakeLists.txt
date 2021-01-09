cmake_minimum_required(VERSION 3.14)

project(botanhang
  LANGUAGES C CXX
)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules")

add_compile_options(
  #-fstack-protector
  -fopenmp
)
link_libraries(
  #-fstack-protector
  -fopenmp
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_definitions(-D_GNU_SOURCE)

find_package(Botan2 2.14.0 REQUIRED)

add_library(libhang
  libhang.cpp
)

target_link_libraries(libhang
  PRIVATE
    Botan2::Botan2
)

if (NOT BUILD_SHARED_LIBS)
  target_compile_definitions(libhang PUBLIC LIBHANG_STATIC)
endif()

set_target_properties(libhang
  PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    PREFIX "lib"
    OUTPUT_NAME "libhang"
)

add_executable(dohang
  dohang.cpp
)
target_link_libraries(dohang
  PRIVATE libhang
)

