if(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "x86_64")
  message(STATUS "x86_64 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR STREQUAL "AMD64")
  message(STATUS "AMD64 architecture detected")
else()
  message(FATAL_ERROR "The architecture does not support: "
                      ${CMAKE_HOST_SYSTEM_PROCESSOR})
endif()

if((NOT (CMAKE_C_COMPILER_ID STREQUAL CMAKE_CXX_COMPILER_ID))
   OR (NOT (CMAKE_C_COMPILER_VERSION STREQUAL CMAKE_CXX_COMPILER_VERSION)))
  message(
    FATAL_ERROR
      "C compiler and C++ compiler are different. C: "
      ${CMAKE_C_COMPILER_ID}
      " "
      ${CMAKE_C_COMPILER_VERSION}
      ", C++: "
      ${CMAKE_CXX_COMPILER_ID}
      " "
      ${CMAKE_CXX_COMPILER_VERSION})
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "Linux and GCC")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10.1.0)
      message(FATAL_ERROR "GCC version must be at least 10.1.0: "
                          ${CMAKE_CXX_COMPILER_VERSION})
    endif()
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Linux and Clang")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 10.0.0)
      message(FATAL_ERROR "Clang version must be at least 10.0.0: "
                          ${CMAKE_CXX_COMPILER_VERSION})
    endif()
  endif()
elseif(APPLE AND CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
  message(STATUS "macOS and AppleClang")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 11.0.3)
    message(FATAL_ERROR "AppleClang version must be at least 11.0.3: "
                        ${CMAKE_CXX_COMPILER_VERSION})
  endif()
else()
  message(FATAL_ERROR "The system and compiler combination does not support: "
                      ${CMAKE_SYSTEM_NAME} " " ${CMAKE_CXX_COMPILER_ID})
endif()

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed")
endif()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE STRING "Choose Release, Debug, MinSizeRel OR RelWithDebInfo" FORCE)
endif()

message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})
