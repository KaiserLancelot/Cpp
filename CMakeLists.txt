cmake_minimum_required(VERSION 3.16)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Release' as none was specified")
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE STRING "Choose the type of build" FORCE)
endif()

project(Cpp-Study LANGUAGES CXX)

if((CMAKE_BUILD_TYPE MATCHES "Debug") OR (CMAKE_BUILD_TYPE MATCHES
                                          "RelWithDebInfo"))
  # Address Thread Undefined None
  set(sanitizer "Undefined")
else()
  set(sanitizer "None")
endif()

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(check)
include(sanitizers)
include(compiler-options)

# aadd_subdirectory(cpp-primer/chapter01)
# aadd_subdirectory(cpp-primer/chapter02)
add_subdirectory(cpp-primer/chapter03)
# add_subdirectory(cpp-primer/chapter04)
# add_subdirectory(cpp-primer/chapter05)
# add_subdirectory(cpp-primer/chapter06)
# add_subdirectory(cpp-primer/chapter07)
# add_subdirectory(cpp-primer/chapter08)
# add_subdirectory(cpp-primer/chapter09)
# add_subdirectory(cpp-primer/chapter10)
# add_subdirectory(cpp-primer/chapter11)
# add_subdirectory(cpp-primer/chapter12)
# add_subdirectory(cpp-primer/chapter13)
# add_subdirectory(cpp-primer/chapter14)
# add_subdirectory(cpp-primer/chapter15)
# add_subdirectory(cpp-primer/chapter16)
# add_subdirectory(cpp-primer/chapter17)
# add_subdirectory(cpp-primer/chapter18)
# add_subdirectory(cpp-primer/chapter19)

# add_subdirectory(library/fmt)

# add_subdirectory(library/Qt/Core)
# add_subdirectory(library/Qt/GUI)
# add_subdirectory(library/Qt/SQL)
# add_subdirectory(library/Qt/Test)

# add_subdirectory(new-features/cpp11)
# add_subdirectory(new-features/cpp14)
# add_subdirectory(new-features/cpp17)
# add_subdirectory(new-features/cpp17/filesystem)
add_subdirectory(new-features/cpp20)

# add_subdirectory(notes)

# add_subdirectory(concurrency/chapter01)
# add_subdirectory(concurrency/chapter02)
