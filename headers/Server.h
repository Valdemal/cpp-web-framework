#ifndef CN8_SERVER_H
#define CN8_SERVER_H

#include "View.h"
#include "Router.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <string>
#include <map>
#include <memory>


namespace vovanex {
    const size_t STANDARD_CLIENT_BUFFER_SIZE = 1024;

    class Server {
    public:
        Server(const std::string &host, const std::string &port, const Router &router,
               size_t client_buffer_size = STANDARD_CLIENT_BUFFER_SIZE);

        int run();
        ~Server();

    private:
        Router router;
        SOCKET listen_socket;
        addrinfo *addr = nullptr;
        size_t client_buffer_size;

        void check_WSA();
        void print_message(const char * client_buffer);
        void receive(char *client_buf, SOCKET client_socket);
    };
}


#endif //CN8_SERVER_H
