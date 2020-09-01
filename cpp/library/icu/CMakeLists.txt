file(COPY data/data.txt DESTINATION ${CMAKE_BINARY_DIR})

find_package(ICU REQUIRED COMPONENTS uc io i18n)

add_executable(conv conv.cpp)
target_link_libraries(conv ${ICU_LIBRARIES})

add_executable(unicode-string unicode_string.cpp)
target_link_libraries(unicode-string ${ICU_LIBRARIES})

add_executable(transforms transforms.cpp)
target_link_libraries(transforms ${ICU_LIBRARIES})
