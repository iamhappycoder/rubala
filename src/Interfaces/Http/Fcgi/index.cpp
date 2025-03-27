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

#include <string_view>
#include <sstream>
#include <fcgio.h>

#include "Infrastructure/Routing/Router.h"

struct ParsedUrl {
    std::string_view path;
    std::string_view query;
};

// Parses a URL into path and query components
constexpr ParsedUrl parse_url(std::string_view url) {
    auto query_pos = url.find('?');
    return query_pos != std::string_view::npos
        ? ParsedUrl{url.substr(0, query_pos), url.substr(query_pos + 1)}
        : ParsedUrl{url, ""};
}

void home(std::ostream& out, std::ostream& /*err*/) {
    out << "Content-Type: text/html\r\n\r\n"
        << "<html><body><h1>Welcome to the Home Page!</h1></body></html>\n";
}

void about(std::ostream& out, std::ostream& /*err*/) {
    out << "Content-Type: text/html\r\n\r\n"
        << "<html><body><h1>About Us</h1></body></html>\n";
}

void contact(std::ostream& out, std::ostream& /*err*/) {
    out << "Content-Type: text/html\r\n\r\n"
        << "<html><body><h1>Contact Us</h1></body></html>\n";
}

void api_transactions(std::ostream& out, std::ostream& /*err*/) {
    out << "Content-Type: text/html\r\n\r\n"
        << "<html><body><h1>Transactions API</h1></body></html>\n";
}

int main() {
    Router router;
    router.addRoute("/", home);
    router.addRoute("/index.fcgi", home);
    router.addRoute("/api/transactions.fcgi", api_transactions);
    router.addRoute("/about.fcgi", about);
    router.addRoute("/contact.fcgi", contact);

    FCGX_Request request;
    FCGX_Init();
    FCGX_InitRequest(&request, 0, 0);

    while (FCGX_Accept_r(&request) == 0) {
        fcgi_streambuf cin_fcgi(request.in), cout_fcgi(request.out), cerr_fcgi(request.err);
        std::ostream out(&cout_fcgi), err(&cerr_fcgi);

        if (const char* request_uri = FCGX_GetParam("REQUEST_URI", request.envp)) {
            auto parsed_url = parse_url(request_uri);
            router.handleRequest(parsed_url.path, out, err);
        }

        FCGX_Finish_r(&request);
    }

    return 0;
}
