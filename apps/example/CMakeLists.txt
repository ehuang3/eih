# Example executables

add_executable(mastermind mastermind.cpp)
target_link_libraries(mastermind eih)
set_target_properties(mastermind PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_executable(gnuplot_example gnuplot_example.cpp)
target_link_libraries(gnuplot_example eih)
set_target_properties(gnuplot_example PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")


