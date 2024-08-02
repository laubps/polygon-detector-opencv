cmake_minimum_required(VERSION 3.5)

project(PolygonsDetector VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(OpenCV REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        res/resources.qrc
        src/ui/mainwindow.cpp src/ui/mainwindow.ui
        src/ui/dashfunctionwidget.cpp src/ui/dashfunctionwidget.ui
        src/ui/imagecardwidget.cpp src/ui/imagecardwidget.ui
        src/ui/imagedetailswidget.cpp src/ui/imagedetailswidget.ui
        src/ui/imageresultswidget.cpp src/ui/imageresultswidget.ui
        src/ui/menubutton.cpp src/ui/menubutton.ui
        src/ui/menuwidget.cpp src/ui/menuwidget.ui

        src/core/image/image.cpp src/core/image/image.h
        src/core/polygon/polygon.cpp src/core/polygon/polygon.h
        src/core/polygon/rectangle.cpp src/core/polygon/rectangle.h
        src/core/polygon/triangle.cpp src/core/polygon/triangle.h
        src/core/polygon_detector/polygonsdetector.cpp src/core/polygon_detector/polygonsdetector.h
        src/core/polygon_factory/polygonfactory.cpp src/core/polygon_factory/polygonfactory.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(PolygonsDetector
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        include/colors.h
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET PolygonsDetector APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(PolygonsDetector SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(PolygonsDetector
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(PolygonsDetector PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${OpenCV_LIBS})

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.PolygonsDetector)
endif()
set_target_properties(PolygonsDetector PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS PolygonsDetector
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(PolygonsDetector)
endif()
