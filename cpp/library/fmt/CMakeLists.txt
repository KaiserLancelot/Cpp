find_package(fmt REQUIRED)

add_executable(core core.cpp)
target_link_libraries(core fmt::fmt)

add_executable(format format.cpp)
target_link_libraries(format fmt::fmt)

add_executable(ostream ostream.cpp)
target_link_libraries(ostream fmt::fmt)

add_executable(syntax syntax.cpp)
target_link_libraries(syntax fmt::fmt)

add_executable(color color.cpp)
target_link_libraries(color fmt::fmt)

add_executable(ranges ranges.cpp)
target_link_libraries(ranges fmt::fmt)

add_executable(os os.cpp)
target_link_libraries(os fmt::fmt)
