cmake_minimum_required (VERSION 2.6)
project (pcx)

include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

set(SOURCES PCXImage.cpp PcxIO.cpp PCXImage.h PcxIO.h)

add_library(pcx SHARED ${SOURCES})
