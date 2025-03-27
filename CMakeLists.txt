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

set(SOURCES
    src/Interfaces/Http/Fcgi/index.cpp
    src/Infrastructure/Routing/Router.cpp
)

add_executable(index.fcgi
               ${SOURCES}
)

target_include_directories(index.fcgi PRIVATE
        src/
)

target_link_libraries(index.fcgi
                      fcgi
                      fcgi++
)

set_target_properties(index.fcgi PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/public/
)
