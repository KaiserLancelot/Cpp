# headers only: find_package(Boost REQUIRED)
find_package(Boost REQUIRED COMPONENTS locale program_options)

add_executable(pool pool.cpp)

add_executable(string_algo string_algo.cpp)

# ${Boost_LIBRARIES}
add_executable(local local.cpp)
target_link_libraries(local Boost::locale)

add_executable(program_options program_options.cpp)
target_link_libraries(program_options Boost::program_options)
