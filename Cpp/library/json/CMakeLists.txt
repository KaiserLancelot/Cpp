find_package(nlohmann_json REQUIRED)

add_executable(json main.cpp)
target_link_libraries(json PRIVATE nlohmann_json::nlohmann_json)
