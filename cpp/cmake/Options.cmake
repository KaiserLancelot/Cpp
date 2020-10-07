option(CPP_FORMAT "Format code using clang-format and cmake-format" OFF)

set(CPP_SANITIZER
    ""
    CACHE
      STRING
      "Build with a sanitizer. Options are: Address, Thread, Memory, Undefined and Address;Undefined"
)
