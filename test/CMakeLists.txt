# To launch those tests, uncomment the following two lines and add object_recognition_tod as a dependency in your stack.xml
#find_package(object_recognition_tod QUIET)
#find_package(object_recognition_core QUIET)

if (NOT object_recognition_tod_FOUND)
  return()
endif()

object_recognition_core_detection_test(${CMAKE_CURRENT_SOURCE_DIR}/config_detection.tod.DAFT)
object_recognition_core_training_test(${CMAKE_CURRENT_SOURCE_DIR}/config_training.tod.DAFT)
