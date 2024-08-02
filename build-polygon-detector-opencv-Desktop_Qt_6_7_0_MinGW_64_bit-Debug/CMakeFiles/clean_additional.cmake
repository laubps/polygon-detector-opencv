# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PolygonsDetector_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PolygonsDetector_autogen.dir\\ParseCache.txt"
  "PolygonsDetector_autogen"
  )
endif()
