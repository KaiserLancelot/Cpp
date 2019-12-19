if(NOT (CMAKE_SYSTEM_NAME MATCHES "Linux" OR CMAKE_SYSTEM_NAME MATCHES "Darwin"
       ))
  message(FATAL_ERROR "Only support linux system and macOS")
endif()

if(NOT (CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES
                                               "Clang"))
  message(FATAL_ERROR "Only supports gcc and clang")
endif()
