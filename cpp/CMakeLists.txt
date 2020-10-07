cmake_minimum_required(VERSION 3.12)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

project(cpp LANGUAGES CXX)

include(Options)
include(Check)
include(CompilerOptions)
include(Format)
include(LTO)

add_subdirectory(cpp_primer)
# add_subdirectory(library) add_subdirectory(new_features)
# add_subdirectory(notes)
