
# define ecto module
ectomodule(daft DESTINATION ecto_daft INSTALL
  module.cpp
  DAFT.cpp
  )
  
# link against the required libs
link_ecto(daft
    ${OpenCV_LIBRARIES}
    ${daft_LIBRARIES})
