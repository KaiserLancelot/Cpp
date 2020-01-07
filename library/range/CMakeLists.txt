find_package(range-v3 REQUIRED)

add_executable(algorithms algorithms.cpp)
target_link_libraries(algorithms range-v3::range-v3)

add_executable(views views.cpp)
target_link_libraries(views range-v3::range-v3)

add_executable(actions actions.cpp)
target_link_libraries(actions range-v3::range-v3)
