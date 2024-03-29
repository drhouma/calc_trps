cmake_minimum_required(VERSION 3.5)

project(Calculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_PREFIX_PATH "~/Qt/6.3.1/gcc_64")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        controller/controller.cpp
        controller/controller.h
#        interface/graphwindow.cpp
#        interface/graphwindow.h
        interface/main.cpp
        interface/mainwindow.cpp
        interface/mainwindow.h
        model/complex.inl
        model/fraction.inl
        model/model.cpp
        model/model.h
        model/number.h
#        model/number.inl
        model/p_numbers.inl
#        model/qcustomplot.cpp
#        model/qcustomplot.h
        graphwindow.ui
        mainwindow.ui
        )


    if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
        qt_add_executable(untitled
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
        )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET untitled APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
    else()
        if(ANDROID)
            add_library(untitled SHARED
                ${PROJECT_SOURCES}
            )
    # Define properties for Android with Qt 5 after find_package() calls as:
    #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
        else()
            add_executable(untitled
                ${PROJECT_SOURCES}
            )
        endif()
    endif()

    target_link_libraries(untitled PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

    set_target_properties(untitled PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
    )

    install(TARGETS untitled
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

    if(QT_VERSION_MAJOR EQUAL 6)
        qt_finalize_executable(untitled)
    endif()

