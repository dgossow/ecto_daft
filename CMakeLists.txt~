cmake_minimum_required(VERSION 2.8)
project(ecto_daft)

find_package(catkin REQUIRED)
catkin_stack()

set(${PROJECT_NAME}_GITHUB_URL https://github.com/dgossow/ecto_daft)

add_definitions(-Wno-strict-aliasing -Wall -Werror)

find_package(OpenCV REQUIRED core imgproc highgui calib3d)
find_package(daft REQUIRED)
find_package(ecto REQUIRED)

message(STATUS "OpenCV version: ${OpenCV_VERSION}")

include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS})

if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

set_ecto_install_package_name(ecto_daft)

add_subdirectory(cells)
