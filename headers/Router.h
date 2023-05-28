#ifndef CN8_ROUTER_H
#define CN8_ROUTER_H

#include "View.h"
#include "Request.h"
#include "Response.h"
#include <memory>
#include <map>

namespace vovanex {

    typedef std::pair<std::string, std::shared_ptr<View>> route_t;

    class Router {
    public:
        Router(std::initializer_list<route_t> routes);

        std::shared_ptr<Response> get_response(const Request& request);
    private:
        std::map<std::string, std::shared_ptr<View>> routes;

        static std::string supplement_url(const std::string& url);
    };
}



#endif //CN8_ROUTER_H
