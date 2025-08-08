cmake_minimum_required(VERSION 3.22)
project(tinygpsplus)

add_compile_options(-Wall -Wextra -Wpedantic -Werror)
include_directories(src)

add_subdirectory(src)

# Disable build testing by default
if(NOT DEFINED BUILD_TESTING)
  set(BUILD_TESTING OFF)
endif(NOT DEFINED BUILD_TESTING)

include(CTest)
add_subdirectory(test)
