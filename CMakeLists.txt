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

set(CMAKE_CXX_STANDARD 23)

# List of subdirectories (modules) to add
set(SUBDIRECTORIES
        src/Application
        src/Domain
        src/Infrastructure
        src/Interfaces
)

# Loop over the subdirectories and call add_subdirectory
foreach(subdir ${SUBDIRECTORIES})
    add_subdirectory(${subdir})
endforeach()
