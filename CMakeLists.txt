cmake_minimum_required(VERSION 3.1.0)

project(KR VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(KR
    src/main.cpp
    src/foo.h
    # src/main.moc
    # resources.qrc
    # mainwindow.ui
    # mainwindow.cpp
)

target_link_libraries(KR Qt5::Widgets)