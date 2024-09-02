# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\McDonald_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\McDonald_autogen.dir\\ParseCache.txt"
  "McDonald_autogen"
  )
endif()
