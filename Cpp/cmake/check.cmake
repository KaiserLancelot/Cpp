if(NOT (CMAKE_SYSTEM_NAME MATCHES "Linux" OR CMAKE_SYSTEM_NAME MATCHES "Darwin"
       ))
  message(FATAL_ERROR "Only support Linux system and macOS")
endif()

if(NOT (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES
                                               "Clang"))
  message(FATAL_ERROR "Only supports GCC and Clang")
endif()
