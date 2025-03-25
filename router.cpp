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

#include "router.h"

void Router::addRoute(std::string_view path, std::function<void(std::ostream&, std::ostream&)> handler) {
    routes[path] = std::move(handler);
}

void Router::handleRequest(std::string_view requestPath, std::ostream& out, std::ostream& err) const {
    if (auto it = routes.find(requestPath); it != routes.end()) {
        it->second(out, err);
    } else {
        out << "Content-Type: text/html\r\n\r\n"
            << "<html><body><h1>404 Not Found: " << requestPath << "</h1></body></html>\n";
    }
}
