ectomodule(ecto_daft
  module.cpp
  DAFT.cpp
  )

# find libs
find_package(OpenCV REQUIRED)
find_package(daft REQUIRED)
include_directories(${daft_INCLUDE_DIRS})


link_ecto(ecto_daft
    ${OpenCV_LIBS}
    ${daft_LIBS})

install_ecto_module(ecto_daft)
