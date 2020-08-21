find_package(ICU REQUIRED COMPONENTS uc)

add_executable(icu main.cpp)
target_link_libraries(icu ${ICU_LIBRARIES})
