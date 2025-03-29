/*
* Rubala
 *
 * Copyright (c) 2025, Jasper V. Ferrer
 *
 * This file is part of the Rubala source code.
 *
 * For licensing information, please see the LICENSE file distributed with this code.
 * For inquiries or support, please visit the project's repository at https://github.com/iamhappycoder/rubala.
 */

#include <gtest/gtest.h>
#include <sstream>

#include "Infrastructure/Routing/Router.h"

// Test case for adding a route and handling a request
TEST(RouterTest, AddRouteAndHandleRequest) {
    Router router;

    // Create a handler function for the "/home" path
    auto homeHandler = [](std::ostream& out, std::ostream& err) {
        out << "Welcome to the home page!";
    };

    // Add the "/home" route
    router.addRoute("/home", homeHandler);

    // Create output streams to capture the response
    std::ostringstream outStream;
    std::ostringstream errStream;

    // Handle a request to the "/home" route
    router.handleRequest("/home", outStream, errStream);

    // Check if the response is correct
    EXPECT_EQ(outStream.str(), "Welcome to the home page!");
    EXPECT_TRUE(errStream.str().empty()); // No errors expected
}

// Test case for handling a request with a route that doesn't exist (404)
TEST(RouterTest, Handle404NotFound) {
    Router router;

    // Create output streams to capture the response
    std::ostringstream outStream;
    std::ostringstream errStream;

    // Handle a request to a non-existent route
    router.handleRequest("/nonexistent", outStream, errStream);

    // Check if the response contains the 404 error message
    EXPECT_NE(outStream.str().find("404 Not Found: /nonexistent"), std::string::npos);
    EXPECT_TRUE(errStream.str().empty()); // No errors expected
}

// Test case for handling multiple routes
TEST(RouterTest, AddMultipleRoutesAndHandleRequests) {
    Router router;

    // Create handler functions for multiple routes
    auto homeHandler = [](std::ostream& out, std::ostream& err) {
        out << "Welcome to the home page!";
    };
    auto aboutHandler = [](std::ostream& out, std::ostream& err) {
        out << "This is the about page.";
    };

    // Add the routes
    router.addRoute("/home", homeHandler);
    router.addRoute("/about", aboutHandler);

    // Create output streams to capture the response for "/home"
    std::ostringstream outStream;
    std::ostringstream errStream;

    // Handle a request to the "/home" route
    router.handleRequest("/home", outStream, errStream);
    EXPECT_EQ(outStream.str(), "Welcome to the home page!");
    EXPECT_TRUE(errStream.str().empty());

    // Handle a request to the "/about" route
    outStream.str("");  // Clear the output stream
    router.handleRequest("/about", outStream, errStream);
    EXPECT_EQ(outStream.str(), "This is the about page.");
    EXPECT_TRUE(errStream.str().empty());
}

