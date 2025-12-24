cmake_minimum_required(VERSION 3.2...3.27.5)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(SOURCES
    qt_mario.cpp
    qt_box.cpp
    qt_enemy.cpp
    qt_full_box.cpp
    qt_money.cpp
    qt_ship.cpp
    qt_flying_enemy.cpp
    qt_jumping_enemy.cpp
)

add_library(qt_ui_objects ${SOURCES})

target_include_directories(qt_ui_objects PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/ui/qt
    ${CMAKE_SOURCE_DIR}/model
    ${CMAKE_SOURCE_DIR}/controller
    ${CMAKE_SOURCE_DIR}/objects
    ${CMAKE_SOURCE_DIR}/levels
    ${CMAKE_SOURCE_DIR}/os_controls
    ${CMAKE_SOURCE_DIR}/os_controls/windows
    ${CMAKE_SOURCE_DIR}/os_controls/os_api
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(qt_ui_objects
    Qt6::Widgets
)