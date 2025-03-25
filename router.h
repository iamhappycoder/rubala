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

#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <string_view>
#include <unordered_map>
#include <functional>

class Router {
private:
    std::unordered_map<std::string_view, std::function<void(std::ostream&, std::ostream&)>> routes;

public:
    void addRoute(std::string_view path, std::function<void(std::ostream&, std::ostream&)> handler);
    void handleRequest(std::string_view requestPath, std::ostream& out, std::ostream& err) const;
};

#endif
