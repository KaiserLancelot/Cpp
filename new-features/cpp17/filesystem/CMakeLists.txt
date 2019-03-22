set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(fmt)

add_executable(filesystem base.cpp)
target_link_libraries(filesystem stdc++fs)

add_executable(ls ls.cpp)
target_link_libraries(ls stdc++fs fmt::fmt)

add_executable(grep grep.cpp)
target_link_libraries(grep stdc++fs fmt::fmt)

add_executable(renamer renamer.cpp)
target_link_libraries(renamer stdc++fs)

add_executable(file_size file_size.cpp)
target_link_libraries(file_size stdc++fs fmt::fmt)

add_executable(remove remove.cpp)
target_link_libraries(remove stdc++fs)

add_executable(copy copy.cpp)
target_link_libraries(copy stdc++fs)