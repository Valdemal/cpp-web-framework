#include "Request.h"
#include "utils.h"

vovanex::method_t vovanex::Request::get_method() const {
    return this->method;
}

const std::string &vovanex::Request::get_url() const {
    return this->url;
}

vovanex::Request::Request(const char *const request_text) {
    char * str_ptr = const_cast<char *>(request_text);

    std::string method_name;
    str_ptr = vovanex::get_word(str_ptr, method_name);
    this->method = get_method_by_name(method_name);

    str_ptr = vovanex::get_word(str_ptr, this->url);
}
