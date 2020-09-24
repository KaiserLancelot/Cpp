if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "Linux and GCC")
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Linux and Clang")
  endif()
elseif(APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
  message(STATUS "macOS and AppleClang")
else()
  message(FATAL_ERROR "The system and compiler combination does not support")
endif()

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed")
endif()

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to Release as none was specified")
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE STRING "Choose Release or Debug" FORCE)
endif()
