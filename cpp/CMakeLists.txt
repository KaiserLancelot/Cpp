cmake_minimum_required(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(cpp LANGUAGES CXX)

option(CPP_FORMAT "Format code using clang-format and cmake-format" OFF)
option(CPP_SANITIZER "Build with AddressSanitizer and UndefinedSanitizer" OFF)

include(Check)
include(CompilerOptions)
include(Format)

add_subdirectory(cpp_primer)
# add_subdirectory(library) add_subdirectory(new_features)
# add_subdirectory(notes)
