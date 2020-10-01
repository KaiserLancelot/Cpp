function(mangle_compiler_flag FLAG OUTPUT)
  string(TOUPPER "HAVE_FLAG_${FLAG}" SANITIZED_FLAG)
  string(REPLACE "+" "X" SANITIZED_FLAG ${SANITIZED_FLAG})
  string(REGEX REPLACE "[^A-Za-z_0-9]" "_" SANITIZED_FLAG ${SANITIZED_FLAG})
  string(REGEX REPLACE "_+" "_" SANITIZED_FLAG ${SANITIZED_FLAG})

  set(${OUTPUT}
      "${SANITIZED_FLAG}"
      PARENT_SCOPE)
endfunction()

include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)

function(add_required_compiler_flag FLAG)
  mangle_compiler_flag("${FLAG}" MANGLED_FLAG)
  set(OLD_CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS}")
  set(CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS} ${FLAG}")
  check_c_compiler_flag("${FLAG}" ${MANGLED_FLAG}_C)
  check_cxx_compiler_flag("${FLAG}" ${MANGLED_FLAG}_CXX)
  set(CMAKE_REQUIRED_FLAGS "${OLD_CMAKE_REQUIRED_FLAGS}")

  set(VARIANT ${ARGV1})
  if(ARGV1)
    string(TOUPPER "_${VARIANT}" VARIANT)
  endif()

  if(${MANGLED_FLAG}_C OR ${MANGLED_FLAG}_CXX)
    set(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} ${FLAG}"
        PARENT_SCOPE)
    set(CMAKE_SHARED_LINKER_FLAGS
        "${CMAKE_SHARED_LINKER_FLAGS} ${FLAG}"
        PARENT_SCOPE)
    set(CMAKE_MODULE_LINKER_FLAGS
        "${CMAKE_MODULE_LINKER_FLAGS} ${FLAG}"
        PARENT_SCOPE)
    set(CMAKE_REQUIRED_FLAGS
        "${CMAKE_REQUIRED_FLAGS} ${FLAG}"
        PARENT_SCOPE)
  else()
    message(
      FATAL_ERROR "Required flag '${FLAG}' is not supported by the compiler")
  endif()

  if(${MANGLED_FLAG}_C)
    set(CMAKE_C_FLAGS${VARIANT}
        "${CMAKE_C_FLAGS${VARIANT}} ${FLAG}"
        PARENT_SCOPE)
  endif()

  if(${MANGLED_FLAG}_CXX)
    set(CMAKE_CXX_FLAGS${VARIANT}
        "${CMAKE_CXX_FLAGS${VARIANT}} ${FLAG}"
        PARENT_SCOPE)
  endif()
endfunction()
