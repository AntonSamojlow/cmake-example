﻿include_guard()

# Enable static analysis with clang-tidy
macro(enable_clang_tidy)

  find_program(CLANGTIDY clang-tidy)
  if(NOT CLANGTIDY)
    message(FATAL_ERROR "clang-tidy requested but executable not found. Consider disabling static analysis.")
  endif()

  # construct the clang-tidy command line
  set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY} -extra-arg=-Wno-unknown-warning-option)
  # set all warnings as errors, if enabled
  if(${WARNINGS_AS_ERRORS})
    message(STATUS "enable_clang_tidy_globally: WARNINGS_AS_ERRORS enabled")
    list(APPEND CMAKE_CXX_CLANG_TIDY -warnings-as-errors=*)
  endif()

  message(STATUS "enable_clang_tidy_globally: CMAKE_CXX_CLANG_TIDY=${CMAKE_CXX_CLANG_TIDY}")


  # C clang-tidy
  set(CMAKE_C_CLANG_TIDY ${CMAKE_CXX_CLANG_TIDY})

  # set C++ standard
  if(NOT
      "${CMAKE_CXX_STANDARD}"
      STREQUAL
      "")
    if("${CMAKE_CXX_CLANG_TIDY_DRIVER_MODE}" STREQUAL "cl")
      set(CMAKE_CXX_CLANG_TIDY ${CMAKE_CXX_CLANG_TIDY} -extra-arg=/std:c++${CMAKE_CXX_STANDARD})
    else()
      set(CMAKE_CXX_CLANG_TIDY ${CMAKE_CXX_CLANG_TIDY} -extra-arg=-std=c++${CMAKE_CXX_STANDARD})
    endif()
  endif()

  # set C standard
  if(NOT
      "${CMAKE_C_STANDARD}"
      STREQUAL
      "")
    if("${CMAKE_C_CLANG_TIDY_DRIVER_MODE}" STREQUAL "cl")
      set(CMAKE_C_CLANG_TIDY ${CMAKE_C_CLANG_TIDY} -extra-arg=/std:c${CMAKE_C_STANDARD})
    else()
      set(CMAKE_C_CLANG_TIDY ${CMAKE_C_CLANG_TIDY} -extra-arg=-std=c${CMAKE_C_STANDARD})
    endif()
  endif()

endmacro()

# Disable clang-tidy for target
function(disable_clang_tidy_for target_name)
  find_program(CLANGTIDY clang-tidy)
  if(NOT CLANGTIDY)
    message(WARNING "clang tidy was not found - skipping disabling clang tidy for '${target_name}'")
  else()
    set_target_properties(${target_name} PROPERTIES C_CLANG_TIDY "")
    set_target_properties(${target_name} PROPERTIES CXX_CLANG_TIDY "")
  endif()
endfunction()