set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(AddCompilerFlag)

add_compiler_flag("-Wall")
add_compiler_flag("-Wextra")
add_compiler_flag("-Wpedantic")
add_compiler_flag("-Werror")

if(CPP_USE_LIBCXX)
  if(CMAKE_COMPILER_IS_GNUCXX)
    message(FATAL_ERROR "GCC does not support libc++")
  endif()

  message(STATUS "Use libc++")
  add_cxx_compiler_flag("-stdlib=libc++")

  # https://blog.jetbrains.com/clion/2019/10/clion-2019-3-eap-debugger-improvements/
  if(((CMAKE_BUILD_TYPE STREQUAL "Debug") OR (CMAKE_BUILD_TYPE STREQUAL
                                              "RelWithDebInfo"))
     AND (CMAKE_SYSTEM_NAME STREQUAL "Linux"))
    add_compiler_flag("-fstandalone-debug")
  endif()
endif()
