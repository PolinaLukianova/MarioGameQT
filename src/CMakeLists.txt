cmake_minimum_required(VERSION 3.2...3.27.5)

project(super_mario)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

SET(CMAKE_CXX_FLAGS "-finput-charset=utf-8 -fexec-charset=utf-8")

set(SOURCES main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/model
    ${CMAKE_SOURCE_DIR}/controller
    ${CMAKE_SOURCE_DIR}/objects
    ${CMAKE_SOURCE_DIR}/levels
    ${CMAKE_SOURCE_DIR}/os_controls/windows
    ${CMAKE_SOURCE_DIR}/os_controls/os_api
    ${CMAKE_SOURCE_DIR}/ui/qt
    ${CMAKE_SOURCE_DIR}/ui/qt/ui_objects
)

add_subdirectory(model)
add_subdirectory(controller)
add_subdirectory(objects)
add_subdirectory(levels)
add_subdirectory(os_controls)
add_subdirectory(ui)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt6::Widgets
        qt_ui
)