#include "Response.h"
#include "fstream"


const std::shared_ptr<vovanex::Response> vovanex::NOT_FOUND_RESPONSE = std::make_shared<vovanex::TextResponse>(
        "<h1>Not Found!</h1>", vovanex::http_status::NOT_FOUND_404);

const std::shared_ptr<vovanex::Response> vovanex::METHOD_NOT_ALLOWED_RESPONSE = std::make_shared<vovanex::TextResponse>(
        "<h1>Method Not Allowed!</h1>", vovanex::http_status::METHOD_NOT_ALLOWED_405);

const std::shared_ptr<vovanex::Response> vovanex::METHOD_NOT_IMPLEMENTED_RESPONSE = std::make_shared<vovanex::TextResponse>(
        "<h1>Method Not Implemented!</h1>", vovanex::http_status::METHOD_NOT_IMPLEMENTED_501);


vovanex::TextResponse::TextResponse(
        const std::string &body, size_t status, const std::string &charset, const std::string &content_type)
        : TextResponse(status, charset, content_type) {
    this->body << body;
}

std::stringstream vovanex::TextResponse::render() {
    return std::stringstream() << create_header() << body.str();
}

std::string vovanex::TextResponse::create_header() {
    std::stringstream header;
    header << "HTTP/1.1 " << status << " " << STATUS_ANNOTATION.at(status) <<"\r\n";
    header << "Version: HTTP/1.1\r\n";
    header << "Content-Type: " << content_type << "; charset=" << charset << "\r\n";
    header << "Content-Length: " << body.str().length();
    header << "\r\n\r\n";

    return header.str();
}

vovanex::TextResponse::TextResponse(size_t status, const std::string &charset, const std::string &content_type)
        : charset(charset), content_type(content_type) {
    this->status = status;
}

vovanex::HtmlResponse::HtmlResponse(const std::string &template_filename, size_t status, const std::string &charset,
                                    const std::string &content_type) : TextResponse(status, charset, content_type) {
    std::ifstream file(template_filename);
    if (not file)
        throw std::runtime_error("Файл " + template_filename + " не найден!");

    body << file.rdbuf();

    file.close();

}
