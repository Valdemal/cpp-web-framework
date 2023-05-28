#include <stdexcept>
#include "method.h"
#include "cctype"

vovanex::method_t vovanex::get_method_by_name(std::string method_name) {
    // to upper case
    std::transform(method_name.begin(), method_name.end(), method_name.begin(),
                   [](unsigned char c) {return std::toupper(c);});
    try {
        return method_map.at(method_name);
    } catch (std::out_of_range & error) {
        throw std::domain_error("Invalid method name: " + method_name);
    }
}

