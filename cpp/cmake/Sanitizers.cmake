if(SANITIZER)
  if(SANITIZER STREQUAL "Address")
    message(STATUS "Building with AddressSanitizer")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=address -fno-omit-frame-pointer")
  elseif(SANITIZER STREQUAL "Thread")
    message(STATUS "Building with ThreadSanitizer")
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=thread")
  elseif(SANITIZER STREQUAL "Undefined")
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
