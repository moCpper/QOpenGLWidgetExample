# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QOpenGLWidget_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QOpenGLWidget_autogen.dir\\ParseCache.txt"
  "QOpenGLWidget_autogen"
  )
endif()
