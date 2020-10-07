cmake_minimum_required(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(cpp LANGUAGES CXX)

option(CPP_FORMAT "Format code using clang-format and cmake-format" OFF)

set(CPP_SANITIZER
    ""
    CACHE
      STRING
      "Build with a sanitizer. Options are: Address, Thread, Memory, Undefined and Address;Undefined"
)

include(Check)
include(CompilerOptions)
include(Format)
include(Sanitizer)

add_subdirectory(cpp_primer)
# add_subdirectory(library)
# add_subdirectory(new_features)
# add_subdirectory(notes)
