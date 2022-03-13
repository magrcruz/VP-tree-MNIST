# CMakeList.txt : CMake project for EDA_trabajo_final, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("EDA_trabajo_final")

# Add source to this project's executable.
add_executable (EDA_trabajo_final  "EDA_trabajo_final.cpp" "EDA_trabajo_final.h")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/dataset
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
