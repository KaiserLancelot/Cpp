find_package(fmt REQUIRED)

add_executable(core core.cpp)
target_link_libraries(core PRIVATE fmt::fmt-header-only)

add_executable(format format.cpp)
target_link_libraries(format PRIVATE fmt::fmt-header-only)

add_executable(ostream ostream.cpp)
target_link_libraries(ostream PRIVATE fmt::fmt-header-only)

add_executable(syntax syntax.cpp)
target_link_libraries(syntax PRIVATE fmt::fmt-header-only)

add_executable(color color.cpp)
target_link_libraries(color PRIVATE fmt::fmt-header-only)

add_executable(ranges ranges.cpp)
target_link_libraries(ranges PRIVATE fmt::fmt-header-only)

add_executable(os os.cpp)
target_link_libraries(os PRIVATE fmt::fmt-header-only)
