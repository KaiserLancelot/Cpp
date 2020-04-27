add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)

add_executable(sql main.cpp)
target_link_libraries(sql mysqlcppconn8)
