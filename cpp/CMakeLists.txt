cmake_minimum_required(VERSION 3.10)

project(cpp LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(Check)
include(CompilerOptions)

set(SANITIZER
    ""
    CACHE
      STRING
      "Build with a sanitizer. Options are: Address, Thread, Memory, Undefined and Address;Undefined"
)
include(Sanitizer)

add_subdirectory(cpp_primer/chapter01)
add_subdirectory(cpp_primer/chapter02)
add_subdirectory(cpp_primer/chapter03)
add_subdirectory(cpp_primer/chapter04)
add_subdirectory(cpp_primer/chapter05)
add_subdirectory(cpp_primer/chapter06)
add_subdirectory(cpp_primer/chapter07)
add_subdirectory(cpp_primer/chapter08)
add_subdirectory(cpp_primer/chapter09)
add_subdirectory(cpp_primer/chapter10)
add_subdirectory(cpp_primer/chapter11)
add_subdirectory(cpp_primer/chapter12)
# add_subdirectory(cpp_primer/chapter13) add_subdirectory(cpp_primer/chapter14)
# add_subdirectory(cpp_primer/chapter15) add_subdirectory(cpp_primer/chapter16)
# add_subdirectory(cpp_primer/chapter17) add_subdirectory(cpp_primer/chapter18)
# add_subdirectory(cpp_primer/chapter19)

add_subdirectory(library/benchmark)
add_subdirectory(library/boost)
add_subdirectory(library/boost/asio)
add_subdirectory(library/database/mysql)
add_subdirectory(library/database/rocksdb)
add_subdirectory(library/fmt)
add_subdirectory(library/gtest)
add_subdirectory(library/icu)
add_subdirectory(library/json)
add_subdirectory(library/libarchive)
add_subdirectory(library/libcurl)
add_subdirectory(library/magic_enum)
add_subdirectory(library/protobuf)
add_subdirectory(library/spdlog)
add_subdirectory(library/zstd)

add_subdirectory(new_features/cpp11)
add_subdirectory(new_features/cpp14)
add_subdirectory(new_features/cpp17)
add_subdirectory(new_features/cpp17/filesystem)
add_subdirectory(new_features/cpp20)

add_subdirectory(notes)
