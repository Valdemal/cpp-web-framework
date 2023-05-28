#ifndef CN8_REQUEST_H
#define CN8_REQUEST_H

#include "method.h"
#include <string>

namespace vovanex {
    class Request {
    public:
        Request(const char *const request_text);

        method_t get_method() const;

        const std::string& get_url() const;
    private:
        std::string url;
        method_t method;
    };
}



#endif //CN8_REQUEST_H
