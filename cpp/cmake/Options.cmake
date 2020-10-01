option(CPP_FORMAT "Format code using clang-format and cmake-format" OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "(Apple)?Clang")
  option(CPP_USE_LIBCXX "Use libc++" OFF)
endif()

set(CPP_SANITIZER
    ""
    CACHE
      STRING
      "Build with a sanitizer. Options are: Address, Thread, Memory, Undefined and Address;Undefined"
)
