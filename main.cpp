#include "headers/Server.h"
#include <windows.h>

using vovanex::Server;
using vovanex::Router;
using vovanex::Response;
using vovanex::HtmlResponse;
using vovanex::TextResponse;

const std::string TEMPLATE_DIR = "../templates/";

class IndexView : public vovanex::View {
public:
    virtual std::shared_ptr<Response> get() const final {
        return std::make_shared<HtmlResponse>(TEMPLATE_DIR + "index.html");
    }
};


class Page2View : public vovanex::View {
public:
    virtual std::shared_ptr<Response> get() const final {
        return std::make_shared<HtmlResponse>(TEMPLATE_DIR + "page2.html");
    }

};



int main() {
    SetConsoleOutputCP(CP_UTF8); // Подключение русского языка

    Router router {
            {"/", std::make_shared<IndexView>()},
            {"/page2/", std::make_shared<Page2View>()}
    };

    Server server ("localhost", "8000", router);
    server.run();
}

