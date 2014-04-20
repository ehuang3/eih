# Find Log4cxx
#
# This sets the following variables:
# Log4cxx_FOUND
# Log4cxx_INCLUDE_DIRS
# Log4cxx_LIBRARIES
# Log4cxx_DEFINITIONS

find_package(PkgConfig REQUIRED)
pkg_check_modules(LOG4CXX REQUIRED liblog4cxx)
set(Log4cxx_LIBRARIES log4cxx)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Log4cxx DEFAULT_MSG
                                  Log4cxx_LIBRARIES)
