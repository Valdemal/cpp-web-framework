#include "View.h"

std::shared_ptr<vovanex::Response> vovanex::View::get() const {
    return this->method_not_allowed();
}


std::shared_ptr<vovanex::Response> vovanex::View::post() const {
    return this->method_not_allowed();
}

std::shared_ptr<vovanex::Response> vovanex::View::patch() const {
    return this->method_not_allowed();
}

std::shared_ptr<vovanex::Response> vovanex::View::put() const {
    return this->method_not_allowed();
}

std::shared_ptr<vovanex::Response> vovanex::View::del() const {
    return this->method_not_allowed();
}


std::shared_ptr<vovanex::Response> vovanex::View::options() const {
    return this->method_not_allowed();
}

std::shared_ptr<vovanex::Response> vovanex::View::method_not_allowed() const {
    return METHOD_NOT_ALLOWED_RESPONSE;
}

std::shared_ptr<vovanex::Response> vovanex::View::head() const {
    return std::make_shared<TextResponse>();
}
