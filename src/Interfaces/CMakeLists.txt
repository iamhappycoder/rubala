# Rubala
#
# Copyright (c) 2025, Jasper V. Ferrer
#
# This file is part of the Rubala source code.
#
# For licensing information, please see the LICENSE file distributed with this code.
# For inquiries or support, please visit the project's repository at https://github.com/iamhappycoder/rubala.

add_executable(index.fcgi
        Http/Fcgi/index.cpp
)

target_link_libraries(index.fcgi
        infrastructure
        fcgi
        fcgi++
)

set_target_properties(index.fcgi PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/public/
)