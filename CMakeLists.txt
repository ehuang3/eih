cmake_minimum_required(VERSION 2.8.3)
project(eih)
set(BUILD_FLAGS "-std=c++0x -Wreturn-type -Wno-enum-compare")

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp sensor_msgs std_msgs tf cv_bridge)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

## Include Eigen
find_package(Eigen REQUIRED)
include_directories(${EIGEN_INCLUDE_DIRS})
add_definitions(${EIGEN_DEFINITIONS})

## Include Qt
find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

# Include the OpenCV library
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIR})
link_libraries(${OpenCV_LIBS})

## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend and a run_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependencies might have been
##     pulled in transitively but can be declared for certainty nonetheless:
##     * add a build_depend tag for "message_generation"
##     * add a run_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs  # Or other packages containing msgs
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES eih
  CATKIN_DEPENDS sensor_msgs std_msgs tf cv_bridge
  DEPENDS system_lib QtCore QtGui
)

######################
## Qt configuration ##
######################
# Run files through "moc", Qt's meta-object compiler
# qt4_wrap_cpp(MOC_FILES
#   include/eih/eih_panel.h)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(include ${catkin_INCLUDE_DIRS})
link_libraries(${catkin_LIBRARIES})

## Collect the source files
# file(GLOB lib_source "src/libraries/*.cpp")
# set(lib_source ${lib_source} ${MOC_FILES}) # Add Qt auto-generated files to library
# list(SORT lib_source)

# file(GLOB nodes_source "src/nodes/*.cpp")
# list(SORT nodes_source)

file(GLOB utils_source "src/utils/*.cpp")
list(SORT utils_source)

# file(GLOB plugins_source "src/plugins/*.cpp")
# set(plugins_source ${plugins_source} ${MOC_FILES}) # Add Qt auto-generated files to plugins
# list(SORT plugins_source)

file(GLOB include_source "include/iarrc_tutorials/*.h")
list(SORT include_source)

## Declare a cpp library
# add_library(${PROJECT_NAME} SHARED ${lib_source})
# add_dependencies(${PROJECT_NAME} eih_msgs_gencpp)
# set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS ${BUILD_FLAGS})
# add_library(${PROJECT_NAME}_rviz SHARED ${plugins_source} ${include_source})
# add_dependencies(${PROJECT_NAME}_rviz eih_msgs_gencpp)
# set_target_properties(${PROJECT_NAME}_rviz PROPERTIES COMPILE_FLAGS ${BUILD_FLAGS})

# Build executables
# message(STATUS "\n-- ROS NODES: ")
# foreach(node_src_file ${nodes_source})
# 	get_filename_component(node_base ${node_src_file} NAME_WE)
# 	message(STATUS "Adding ROS Node ${node_base}" )
# 		add_executable(${node_base} ${node_src_file} ${include_source})
# 	target_link_libraries(${node_base} ${PROJECT_NAME})
# 	add_dependencies(${node_base} eih_msgs_gencpp)
# 	set_target_properties(${node_base} PROPERTIES COMPILE_FLAGS ${BUILD_FLAGS})
# endforeach(node_src_file)

# Build utilities
message(STATUS "\n-- UTILITY SCRIPTS: ")
foreach(util_src_file ${utils_source})
	get_filename_component(util_base ${util_src_file} NAME_WE)
	message(STATUS "Adding ROS util ${util_base}" )
	add_executable(${util_base} ${util_src_file} ${include_source})
	# target_link_libraries(${util_base} ${PROJECT_NAME})
	add_dependencies(${util_base} eih_msgs_gencpp)
	set_target_properties(${util_base} PROPERTIES COMPILE_FLAGS ${BUILD_FLAGS})
endforeach(util_src_file)

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS eih eih_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_eih.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
