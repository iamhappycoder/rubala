# Rubala
#
# Copyright (c) 2025, Jasper V. Ferrer
#
# This file is part of the Rubala source code.
#
# For licensing information, please see the LICENSE file distributed with this code.
# For inquiries or support, please visit the project's repository at https://github.com/iamhappycoder/rubala.

set(UNIT_TEST_SOURCES
        Infrastructure/Routing/RouterUnitTest.cpp
)

add_executable(unit_tests
        ${UNIT_TEST_SOURCES}
)

target_link_libraries(unit_tests
        interfaces
        infrastructure
        gtest
        gtest_main
        pthread
)

add_test(NAME unit_tests COMMAND unit_tests)
