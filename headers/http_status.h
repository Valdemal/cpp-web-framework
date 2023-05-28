#ifndef CN8_HTTP_STATUS_H
#define CN8_HTTP_STATUS_H

namespace vovanex {
    enum http_status {
        OK_200 = 200,
        CREATED_201 = 201,

        BAD_REQUEST_400 = 400,
        UNAUTHORIZED_401 = 401,
        PAYMENT_REQUIRED_402 = 402,
        FORBIDDEN_403 = 403,
        NOT_FOUND_404 = 404,
        METHOD_NOT_ALLOWED = 405,
    };
}

#endif //CN8_HTTP_STATUS_H
