set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(AddCompilerFlag)

# ---------------------------------------------------------------------------------------
# LTO
# ---------------------------------------------------------------------------------------
# https://github.com/ninja-build/ninja/blob/master/CMakeLists.txt
if(CMAKE_BUILD_TYPE STREQUAL "Release")
  include(CheckIPOSupported)
  check_ipo_supported(RESULT LTO_SUPPORTED OUTPUT ERROR)

  if(LTO_SUPPORTED)
    message(STATUS "IPO / LTO enabled")
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
  else()
    message(FATAL_ERROR "IPO / LTO not supported: ${ERROR}")
  endif()
endif()

# ---------------------------------------------------------------------------------------
# Sanitizer
# ---------------------------------------------------------------------------------------
if(CPP_SANITIZER)
  message(STATUS "Build with AddressSanitizer and UndefinedSanitizer")

  add_cxx_compiler_flag("-fsanitize=address")
  add_cxx_compiler_flag("-fsanitize-address-use-after-scope")
  add_cxx_compiler_flag("-fno-omit-frame-pointer")
  add_cxx_compiler_flag("-fno-optimize-sibling-calls")

  add_cxx_compiler_flag("-fsanitize=undefined")
  add_cxx_compiler_flag("-fno-sanitize-recover=all")

  if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_cxx_compiler_flag("-fsanitize=float-divide-by-zero")
    add_cxx_compiler_flag("-fsanitize=unsigned-integer-overflow")
    add_cxx_compiler_flag("-fsanitize=implicit-conversion")
    add_cxx_compiler_flag("-fsanitize=local-bounds")
    add_cxx_compiler_flag("-fsanitize=nullability")
    add_cxx_compiler_flag("-fsanitize-recover=unsigned-integer-overflow")
  endif()
endif()

# ---------------------------------------------------------------------------------------
# Warning
# ---------------------------------------------------------------------------------------
add_cxx_compiler_flag("-Wall")
add_cxx_compiler_flag("-Wextra")
add_cxx_compiler_flag("-Wpedantic")
add_cxx_compiler_flag("-Werror")

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_cxx_compiler_flag("-Weverything")

  add_cxx_compiler_flag("-Wno-c++98-compat")
  add_cxx_compiler_flag("-Wno-missing-prototypes")

  add_cxx_compiler_flag("-Wno-error=padded")
endif()
