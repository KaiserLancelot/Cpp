find_package(GTest REQUIRED)

add_library(tools STATIC sales_item.cpp)
target_link_libraries(tools PRIVATE GTest::gtest)

target_include_directories(tools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(
  tools
  PROPERTIES OUTPUT_NAME tools
             POSITION_INDEPENDENT_CODE ON
             DEBUG_POSTFIX d)
