cmake_minimum_required(VERSION 3.16)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(SOURCES
    qt_game_map.cpp
    qt_ui_obj_rect_adapter.cpp
    qt_ui_factory.cpp
    ui_objects/qt_mario.cpp
    ui_objects/qt_box.cpp
    ui_objects/qt_enemy.cpp
    ui_objects/qt_full_box.cpp
    ui_objects/qt_money.cpp
    ui_objects/qt_ship.cpp
    ui_objects/qt_flying_enemy.cpp
    ui_objects/qt_jumping_enemy.cpp
)

add_library(qt_ui ${SOURCES})

target_include_directories(qt_ui PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/ui_objects
    
    ${CMAKE_SOURCE_DIR}/model
    ${CMAKE_SOURCE_DIR}/controller
    ${CMAKE_SOURCE_DIR}/objects
    ${CMAKE_SOURCE_DIR}/levels
    
    ${CMAKE_SOURCE_DIR}/os_controls
    ${CMAKE_SOURCE_DIR}/os_controls/windows
    ${CMAKE_SOURCE_DIR}/os_controls/os_api
    
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(qt_ui 
    Qt6::Widgets
)