cmake_minimum_required(VERSION 3.22)
project(gal2xyPass)

set(LLVM_DIR /home/gal2xy/Desktop/llvm-project-llvmorg-14.0.6/build/lib/cmake/llvm)//记得替换
find_package(LLVM REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

add_definitions(${LLVM_DEFINITIONS})
include_directories(${LLVM_INCLUDE_DIRS})

add_subdirectory(gal2xyPass)

