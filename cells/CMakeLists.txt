# find libs
find_package(OpenCV REQUIRED)
find_package(daft REQUIRED)
include_directories(${daft_INCLUDE_DIRS})

# define ecto module
ectomodule(daft
  module.cpp
  DAFT.cpp
  )
  
# link against the required libs
link_ecto(daft
    ${OpenCV_LIBRARIES}
    ${daft_LIBRARIES})

#create 'install' rules
install_ecto_module(daft)
