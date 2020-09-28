if(FORMAT)
  message(STATUS "Format code using clang-foramt and cmake-foramt")

  find_program(CLANG_FORMAT_PATH clang-format)
  find_program(CMAKE_FORMAT_PATH cmake-format)

  if(NOT CLANG_FORMAT_PATH)
    message(FATAL_ERROR "Can not find clang-format")
  endif()

  if(NOT CMAKE_FORMAT_PATH)
    message(FATAL_ERROR "Can not find cmake-format")
  endif()

  file(
    GLOB_RECURSE
    CLANG_FORMAT_SOURCES
    CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/cpp_primer/*.h
    ${CMAKE_SOURCE_DIR}/cpp_primer/*.cpp
    ${CMAKE_SOURCE_DIR}/library/*.h
    ${CMAKE_SOURCE_DIR}/library/*.cpp
    ${CMAKE_SOURCE_DIR}/new_features/*.h
    ${CMAKE_SOURCE_DIR}/new_features/*.cpp
    ${CMAKE_SOURCE_DIR}/notes/*.h
    ${CMAKE_SOURCE_DIR}/notes/*.cpp)
  file(
    GLOB_RECURSE
    CMAKE_FORMAT_SOURCES
    CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/cmake/*.cmake
    ${CMAKE_SOURCE_DIR}/CMakeLists.txt
    ${CMAKE_SOURCE_DIR}/cpp_primer/*.cmake
    ${CMAKE_SOURCE_DIR}/library/*.cmake
    ${CMAKE_SOURCE_DIR}/new_features/*.cmake
    ${CMAKE_SOURCE_DIR}/notes/*.cmake)

  add_custom_target(
    code_format
    COMMAND ${CLANG_FORMAT_PATH} -i ${CLANG_FORMAT_SOURCES}
    COMMAND ${CMAKE_FORMAT_PATH} -i ${CMAKE_FORMAT_SOURCES}
    COMMENT "Format C++ and CMake files")
endif()
