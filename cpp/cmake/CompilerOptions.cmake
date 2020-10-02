set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
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

if(CPP_USE_LIBCXX)
  add_required_compiler_flag("-stdlib=libc++")
endif()
