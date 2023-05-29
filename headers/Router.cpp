#include "Router.h"

std::shared_ptr<vovanex::Response> vovanex::Router::get_response(const vovanex::Request &request) {
    auto url = supplement_url(request.get_url());

    if (not routes.count(url))
        return NOT_FOUND_RESPONSE;

    auto view = routes[url];

    switch (request.get_method()) {
        case method_t::GET:
            return view->get();
        case method_t::POST:
            return view->post();
        case method_t::PUT:
            return view->put();
        case method_t::PATCH:
            return view->patch();
        case method_t::DEL:
            return view->del();
        case method_t::HEAD:
            return view->head();
        case method_t::OPTIONS:
            return view->options();
        default:
            return METHOD_NOT_IMPLEMENTED_RESPONSE;
    }
}

std::string vovanex::Router::supplement_url(const std::string& url) {
    if (url.back() == '/')
        return url;

    return url + '/';
}

vovanex::Router::Router(std::initializer_list<route_t> routes) {
    for (auto &route: routes)
        this->routes[supplement_url(route.first)] = route.second;
}
