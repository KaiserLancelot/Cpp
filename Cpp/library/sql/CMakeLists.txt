include_directories(/usr/include/mysql)

add_executable(sql main.cpp)
target_link_libraries(sql mysqlpp mysqlclient)
