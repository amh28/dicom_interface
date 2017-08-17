cmake_minimum_required(VERSION 2.8.11)

project(qt_vtk_dcm)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

find_package(Qt5 REQUIRED Widgets)
#INCLUDE_DIRECTORIES(${QT_INCLUDE_DIR})
#include(${QT_USE_FILE})

SET(VTK_DIR "/usr/local/lib/cmake/vtk-6.3/" CACHE PATH "VTK directory override" FORCE)
find_package (VTK REQUIRED)
include(${VTK_USE_FILE})

set  (project_SOURCES main.cpp mainwindow.cpp)
set  (project_HEADERS mainwindow.h)
set  (project_FORMS   mainwindow.ui)

add_executable(qt_vtk_dcm ${project_SOURCES}
                     ${project_FORMS}
                     ${project_HEADERS})


if(VTK_LIBRARIES)
  target_link_libraries(qt_vtk_dcm Qt5::Widgets vtkWidgets ${VTK_LIBRARIES})
else()
  target_link_libraries(qt_vtk_dcm vtkHybrid vtkWidgets)
endif()
