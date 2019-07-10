set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Widgets REQUIRED CONFIG)
find_package(Qt5LinguistTools REQUIRED CONFIG)

add_executable(json json.cpp)
target_link_libraries(json Qt5::Core)

add_executable(enum enum.cpp enum.h)
target_link_libraries(enum Qt5::Core)

add_executable(command_line command_line.cpp translator.cpp)
target_link_libraries(command_line Qt5::Core)

add_executable(file file.cpp)
target_link_libraries(file Qt5::Core)

file(COPY data/in.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(text_stream text_stream.cpp)
target_link_libraries(text_stream Qt5::Core)

add_executable(containers containers.cpp)
target_link_libraries(containers Qt5::Core)

add_executable(string string.cpp)
target_link_libraries(string Qt5::Core)

add_executable(variant variant.cpp)
target_link_libraries(variant Qt5::Core)

set(TS_FILES ${CMAKE_SOURCE_DIR}/library/Qt/Core/i18n/zh-CN.ts)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR}/library/Qt/Core/translator.cpp
    ${TS_FILES})
set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION
    ${CMAKE_SOURCE_DIR}/library/Qt/Core/i18n)
qt5_add_translation(QM_FILES ${TS_FILES})

add_executable(translator translator.cpp resource.qrc ${QM_FILES})
target_link_libraries(translator Qt5::Core Qt5::Widgets)
