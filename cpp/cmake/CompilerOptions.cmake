set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(MSVC)
  string(APPEND CMAKE_CXX_FLAGS
         " /nologo /EHsc /GF /errorReport:queue /FC /W4 /WX")
else()
  string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra -Wpedantic -Werror")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "(Apple)?Clang")
  if(NOT APPLE)
    add_link_options(-fuse-ld=lld)
  endif()

  if((CMAKE_BUILD_TYPE STREQUAL "Debug") OR (CMAKE_BUILD_TYPE STREQUAL
                                             "RelWithDebInfo"))
    string(APPEND CMAKE_CXX_FLAGS " -fstandalone-debug")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCXX)
  # FIXME
  if(NOT CLANG_TIDY)
    string(APPEND CMAKE_CXX_FLAGS " -fanalyzer")
  endif()
endif()

if((CMAKE_BUILD_TYPE STREQUAL "Release") OR (CMAKE_BUILD_TYPE STREQUAL
                                             "RelWithDebInfo"))
  include(CheckIPOSupported)
  check_ipo_supported(RESULT lto_supported OUTPUT error)

  if(lto_supported)
    message(STATUS "IPO / LTO enabled")
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
  else()
    message(FATAL_ERROR "IPO / LTO not supported: <${error}>")
  endif()
endif()
