# Enable multi-threaded compilation.
# We do this here and not in the root folder since the example apps
# do not have enough source files to benefit from this.
if(MSVC)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")
endif()

set(CORE_SUBDIRS camera eih gnuplot)
set(NONCORE_SUBDIRS utils)
# optimizer is also a NONCORE_SUBDIR, but it will be handled separately

# Search all header and source files
foreach(SUBDIR ${CORE_SUBDIRS})
  file(GLOB_RECURSE subdir_srcs ${SUBDIR}/*.cpp ${SUBDIR}/*.h)
  set(core_srcs ${core_srcs} ${subdir_srcs})
endforeach()

foreach(SUBDIR ${NONCORE_SUBDIRS})
  file(GLOB_RECURSE subdir_srcs ${SUBDIR}/*.cpp ${SUBDIR}/*.h)
  set(noncore_srcs ${noncore_srcs} ${subdir_srcs})
endforeach()

# Setup directory structure for Visual Studio
foreach(SUBDIR ${CORE_SUBDIRS} ${NONCORE_SUBDIRS})
        file(GLOB_RECURSE dir_files ${SUBDIR}/*.cpp ${SUBDIR}/*.h)
        source_group(${SUBDIR} FILES ${dir_files})
endforeach()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Library
add_library(eih-core ${core_srcs})
target_link_libraries(eih-core ${EIH_CORE_DEPENDENCIES})
set_target_properties(eih-core PROPERTIES OUTPUT_NAME "eih-core${EIH_MAJOR_VERSION}"
                                           SOVERSION ${EIH_MINOR_VERSION}
                                           VERSION "${EIH_MINOR_VERSION}.${EIH_PATCH_VERSION}.0")

if(NOT BUILD_CORE_ONLY)
  add_library(eih ${noncore_srcs})
  target_link_libraries(eih eih-core ${EIH_DEPENDENCIES})
  set_target_properties(eih PROPERTIES OUTPUT_NAME "eih${EIH_MAJOR_VERSION}"
                                        SOVERSION ${EIH_MINOR_VERSION}
                                        VERSION "${EIH_MINOR_VERSION}.${EIH_PATCH_VERSION}.0")
endif()


if(MSVC)
    set_target_properties(${target} PROPERTIES STATIC_LIBRARY_FLAGS_RELEASE "/LTCG")
endif()

install(DIRECTORY ./ DESTINATION include/eih FILES_MATCHING PATTERN "*.h")
install(TARGETS eih-core EXPORT EIHCoreTargets DESTINATION lib)
if(NOT BUILD_CORE_ONLY)
    install(TARGETS eih-core eih EXPORT EIHTargets DESTINATION lib)
endif()
