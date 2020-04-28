find_package(fmt REQUIRED)
find_package(Sqlpp11 REQUIRED)

add_definitions(-DFMT_STRING_ALIAS)

add_executable(sql main.cpp)
target_link_libraries(sql fmt::fmt sqlpp-mysql mysqlclient)
