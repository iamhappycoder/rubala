# Rubala
#
# Copyright (c) 2025, Jasper V. Ferrer
#
# This file is part of the Rubala source code.
#
# For licensing information, please see the LICENSE file distributed with this code.
# For inquiries or support, please visit the project's repository at https://github.com/iamhappycoder/rubala.

cmake_minimum_required(VERSION 3.28.3)

project(Rubala)

include_directories(${CMAKE_SOURCE_DIR}/src/)

include(cmake/CMakeRequire.cmake)

# TODO make this conditional
include(cmake/CMakeRequireDev.cmake)
add_subdirectory(tests)

if(NOT CMAKE_BUILD_TYPE)
    message(FATAL_ERROR "Please specify CMAKE_BUILD_TYPE (e.g., Debug, Release, RelWithDebInfo).")
endif()

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)
