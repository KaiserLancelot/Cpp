set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(AddCompilerFlag)

add_required_compiler_flag("-Wall")
add_required_compiler_flag("-Wextra")
add_required_compiler_flag("-Wpedantic")
add_required_compiler_flag("-Werror")

if((CMAKE_CXX_COMPILER_ID MATCHES "(Apple)?Clang")
   AND ((CMAKE_BUILD_TYPE STREQUAL "Debug") OR (CMAKE_BUILD_TYPE STREQUAL
                                                "RelWithDebInfo")))
  add_required_compiler_flag("-fstandalone-debug")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  include(CheckIPOSupported)
  check_ipo_supported(RESULT lto_supported OUTPUT error)

  if(lto_supported)
    message(STATUS "IPO / LTO enabled")
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
  else()
    message(FATAL_ERROR "IPO / LTO not supported: ${error}")
  endif()
endif()
