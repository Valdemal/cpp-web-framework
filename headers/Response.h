#ifndef CN8_RESPONSE_H
#define CN8_RESPONSE_H

#include <sstream>
#include "http_status.h"

namespace vovanex {
    class Response {
    public:
        virtual std::stringstream render () = 0;

        virtual size_t get_status() const;

    protected:
        size_t status;
    };

    class TextResponse : public Response {
    public:
        explicit TextResponse(
                size_t status = http_status::OK_200,
                const std::string& charset = "utf-8",
                const std::string& content_type = "text/html"
        );

        explicit TextResponse(
                const std::string& body,
                size_t status = http_status::OK_200,
                const std::string& charset = "utf-8",
                const std::string& content_type = "text/html"
                );

        virtual std::stringstream render () override;

    protected:
        virtual std::string create_header();

        std::string charset;
        std::stringstream body;
        std::string content_type;
    };

    class HtmlResponse : public TextResponse {
    public:
        explicit HtmlResponse(const std::string& template_filename,
                              size_t status = http_status::OK_200,
                              const std::string& charset = "utf-8",
                              const std::string& content_type = "text/html"
        );
    private:
        std::string template_filename;
    };
}


#endif //CN8_RESPONSE_H
