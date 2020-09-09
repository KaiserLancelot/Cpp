if(SANITIZER)
  if(SANITIZER STREQUAL "Address")
    if(WIN32)
      message(FATAL_ERROR "Windows does not support AddressSanitizer")
    endif()

    message(STATUS "Building with AddressSanitizer")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=address -fno-omit-frame-pointer")
  elseif(SANITIZER STREQUAL "Thread")
    if(WIN32)
      message(FATAL_ERROR "Windows does not support ThreadSanitizer")
    endif()

    message(STATUS "Building with ThreadSanitizer")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=thread")
  elseif(SANITIZER STREQUAL "Undefined")
    if(MSVC)
      message(FATAL_ERROR "MSVC does not support UndefinedSanitizer")
    endif()

    message(STATUS "Building with UndefinedSanitizer")
    string(APPEND CMAKE_CXX_FLAGS
           " -fsanitize=undefined -fno-sanitize-recover=all")

    if(CMAKE_CXX_COMPILER_ID MATCHES "(Apple)?Clang")
      string(
        APPEND
        CMAKE_CXX_FLAGS
        " -fsanitize=float-divide-by-zero -fsanitize=local-bounds -fsanitize=implicit-conversion -fsanitize=integer -fsanitize=nullability -fsanitize-recover=unsigned-integer-overflow"
      )
    endif()
  else()
    message(FATAL_ERROR "The Sanitizer is not supported: ${SANITIZER}")
  endif()
endif()
