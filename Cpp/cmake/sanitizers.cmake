function(append value)
  foreach(variable ${ARGN})
    set(${variable}
        "${${variable}} ${value}"
        PARENT_SCOPE)
  endforeach(variable)
endfunction()

if(sanitizer MATCHES "([Nn]one)")
  message(STATUS "None Sanitizer")
else()
  if(sanitizer MATCHES "([Aa]ddress)")
    message(STATUS "Building with Address and Undefined Sanitizer")
    append("-fsanitize=address -fno-omit-frame-pointer -fsanitize=undefined"
           CMAKE_CXX_FLAGS)
  elseif(sanitizer MATCHES "([Mm]emory)")
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
      message(
        STATUS
          "Building with Undefined sanitizer, GCC does not support Memory Sanitizer"
      )
      append("-fsanitize=undefined" CMAKE_CXX_FLAGS)
    else()
      message(STATUS "Building with Memory and Undefined Sanitizer")
      append(
        "-fsanitize=memory -fsanitize-memory-track-origins -fPIE -fno-omit-frame-pointer -fsanitize=undefined"
        CMAKE_CXX_FLAGS)
    endif()
  elseif(sanitizer MATCHES "([Tt]hread)")
    message(STATUS "Building with Thread and Undefined Sanitizer")
    append("-fsanitize=thread -fsanitize=undefined" CMAKE_CXX_FLAGS)
  else()
    message(FATAL_ERROR "Sanitizer is not supported")
  endif()
endif()
