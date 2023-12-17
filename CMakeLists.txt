cmake_minimum_required(VERSION 3.5)

project(matModelKA VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)

# ПОДКЛЮЧАЕМ MARBLE ++++++++++++++++++++++++++++++++++++++++++
# указываем в нашем проекте где лежат дополнительные .cmake файлы
LIST(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" "${PROJECT_SOURCE_DIR}/import/cmake")

# ПОДКЛЮЧАЕМ MARBLE ++++++++++++++++++++++++++++++++++++++++++

MESSAGE("==============================")
MESSAGE("AAAAAAAAAAAAAAAA ")


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        inc/stateVectorModel.h src/stateVectorModel.cpp
        inc/mathModelSpacecraft.h src/mathModelSpacecraft.cpp
        inc/MapMarbleTrassa.h src/MapMarbleTrassa.cpp
        inc/coordinateVectors.h src/coordinateVectors.cpp
        inc/definitions.h
        inc/xyz2blh.h src/xyz2blh.cpp
        inc/TMicsellFunction.h src/TMicsellFunction.cpp
        inc/stateVectorShell.h src/stateVectorShell.cpp
        inc/stateVectorDelegate.h src/stateVectorDelegate.cpp
        inc/VectorModel.h src/VectorModel.cpp
        inc/MapSettings.h src/MapSettings.cpp src/MapSettings.ui
        inc/settingsTreeView.h src/settingsTreeView.cpp
        inc/settingsTreeItem.h src/settingsTreeItem.cpp
        inc/MapMarbleDelegate.h src/MapMarbleDelegate.cpp
        inc/connectDataBase.h src/connectDataBase.cpp
        inc/PZ_90_02.h
        res/resourse.qrc
#        MathModelOld.h MathModelOld.cpp
#        StackedWidgetCharts.h StackedWidgetCharts.cpp StackedWidgetCharts.ui
        SWcharts.h SWcharts.cpp SWcharts.ui
        inc/qcustomplot.h src/qcustomplot.cpp
)

message("PROJECT_SOURCES")


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(matModelKA
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET matModelKA APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(matModelKA SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(matModelKA
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Для марбл на всякий случай))))
#target_link_libraries(matModelKA PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
find_package(Qt COMPONENTS Sql REQUIRED)
target_link_libraries(matModelKA PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
  PRIVATE Qt::Sql)

# после того, какпрописану все свойства, прописываем
target_include_directories(matModelKA PRIVATE "/home/mary/3rd_party/marble-product/include/marble")

target_link_libraries(matModelKA PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    "/home/mary/3rd_party/marble-product/lib/libastro.so"
    "/home/mary/3rd_party/marble-product/lib/libastro.so.1"
    "/home/mary/3rd_party/marble-product/lib/libastro.so.23.3.70"
    "/home/mary/3rd_party/marble-product/lib/libmarbledeclarative.so"
    "/home/mary/3rd_party/marble-product/lib/libmarblewidget-qt5.so"
    "/home/mary/3rd_party/marble-product/lib/libmarblewidget-qt5.so.23.3.70"
    "/home/mary/3rd_party/marble-product/lib/libmarblewidget-qt5.so.28")


set_target_properties(matModelKA PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(matModelKA)
endif()


set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT Alttaira@yandex.ru)

include(CPack)
