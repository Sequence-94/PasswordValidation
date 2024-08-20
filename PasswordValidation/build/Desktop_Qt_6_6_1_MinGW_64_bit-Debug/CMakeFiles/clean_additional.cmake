# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\PasswordValidation_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PasswordValidation_autogen.dir\\ParseCache.txt"
  "PasswordValidation_autogen"
  )
endif()
