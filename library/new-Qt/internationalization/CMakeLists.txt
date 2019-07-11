set(TS_FILES ${CMAKE_CURRENT_SOURCE_DIR}/i18n/zh-CN.ts)
qt5_create_translation(QM_FILES ${CMAKE_CURRENT_SOURCE_DIR} ${TS_FILES})
set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION
    ${CMAKE_CURRENT_SOURCE_DIR}/i18n)
qt5_add_translation(QM_FILES ${TS_FILES})

file(GLOB cppsrc *.h *.cpp)
add_executable(internationalization ${cppsrc}
    resource.qrc ${QM_FILES} main.cpp setting_dialog.cpp setting_dialog.h main_Widget.cpp main_Widget.h)

target_link_libraries(internationalization
    Qt5::Core
    Qt5::Widgets)
