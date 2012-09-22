cmake_minimum_required(VERSION 2.8)
project(ecto_daft)

find_package(catkin REQUIRED)

# Read stack.xml and do some magic (?)
if (${catkin_VERSION} VERSION_GREATER "0.5.26")
catkin_package()
else()
catkin_stack()
endif()

# Read setup.py and generate __init__.py in gen/py/ecto_daft
catkin_python_setup()

# What does this do? Probably only for the build error messages.
set(${PROJECT_NAME}_GITHUB_URL https://github.com/dgossow/ecto_daft)

find_package(OpenCV REQUIRED core imgproc highgui calib3d)
find_package(daft REQUIRED)
find_package(ecto REQUIRED)

message(STATUS "OpenCV version: ${OpenCV_VERSION}")

include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS} ${daft_INCLUDE_DIRS})

if(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
endif()

add_subdirectory(cells)
add_subdirectory(test)
