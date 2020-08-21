# headers only: find_package(Boost REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(pool pool.cpp)

add_executable(string_algo string_algo.cpp)

add_executable(program_options program_options.cpp)
target_link_libraries(program_options ${Boost_LIBRARIES})
