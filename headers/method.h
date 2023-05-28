#ifndef CN8_METHOD_H
#define CN8_METHOD_H

#include <string>
#include <map>

namespace vovanex {

    enum class method_t {
        GET, POST, PUT, PATCH, DEL,  HEAD, OPTIONS, TRACE, CONNECT
    };

    method_t get_method_by_name(std::string method_name);

    static const std::map<std::string, vovanex::method_t> method_map {
            {"GET", vovanex::method_t::GET},
            {"POST", vovanex::method_t::POST},
            {"PUT", vovanex::method_t::PUT},
            {"PATCH", vovanex::method_t::PATCH},
            {"DELETE", vovanex::method_t::DEL},
            {"HEAD", vovanex::method_t::HEAD},
            {"OPTIONS", vovanex::method_t::OPTIONS},
            {"CONNECT", vovanex::method_t::CONNECT},
            {"TRACE", vovanex::method_t::TRACE}
    };
}

#endif //CN8_METHOD_H
