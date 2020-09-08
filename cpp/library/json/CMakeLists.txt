file(COPY data/in.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

find_package(nlohmann_json REQUIRED)

add_executable(basic basic.cpp)
target_link_libraries(basic nlohmann_json::nlohmann_json)

add_executable(stl stl.cpp)
target_link_libraries(stl nlohmann_json::nlohmann_json)
