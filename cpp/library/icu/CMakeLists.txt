find_package(ICU REQUIRED COMPONENTS uc io)

add_executable(conv conv.cpp)
target_link_libraries(conv ${ICU_LIBRARIES})

add_executable(unicode-string unicode_string.cpp)
target_link_libraries(unicode-string ${ICU_LIBRARIES})
