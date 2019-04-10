set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Sql REQUIRED CONFIG)
find_package(Qt5Widgets REQUIRED CONFIG)
find_package(fmt)

add_definitions(-DFMT_STRING_ALIAS=1)

add_executable(sql sql.cpp)
target_link_libraries(sql Qt5::Core Qt5::Sql fmt::fmt)

add_executable(sql_model sql_model.cpp)
target_link_libraries(sql_model Qt5::Core Qt5::Sql fmt::fmt)

add_executable(show show.cpp)
target_link_libraries(show Qt5::Core Qt5::Sql Qt5::Widgets)
