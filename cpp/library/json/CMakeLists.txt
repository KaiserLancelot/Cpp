file(COPY data/in.json DESTINATION ${CMAKE_BINARY_DIR})

find_package(nlohmann_json REQUIRED)

add_executable(basic basic.cpp)
target_link_libraries(basic PRIVATE nlohmann_json::nlohmann_json)

add_executable(stl stl.cpp)
target_link_libraries(stl PRIVATE nlohmann_json::nlohmann_json)
