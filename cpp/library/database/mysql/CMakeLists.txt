add_executable(mysql main.cpp)
target_link_libraries(mysql mysqlcppconn8)
target_link_directories(mysql PRIVATE /usr/local/lib64)
