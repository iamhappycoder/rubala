# Rubala
#
# Copyright (c) 2025, Jasper V. Ferrer
#
# This file is part of the Rubala source code.
#
# For licensing information, please see the LICENSE file distributed with this code.
# For inquiries or support, please visit the project's repository at https://github.com/iamhappycoder/rubala.

enable_testing()

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/vendor)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
)

# Make sure Google Test is downloaded and placed in the vendor directory
FetchContent_MakeAvailable(googletest)
