#include "http_status.h"

const std::map<size_t, std::string> vovanex::STATUS_ANNOTATION = {
        {vovanex::http_status::OK_200, "OK"},
        {vovanex::http_status::NOT_FOUND_404, "Not Found"},
        {vovanex::http_status::METHOD_NOT_ALLOWED_405, "Method Not Allowed"},
        {vovanex::http_status::METHOD_NOT_IMPLEMENTED_501, "Method Not Implemented"},
};

