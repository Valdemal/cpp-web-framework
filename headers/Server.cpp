#include "Server.h"
#include "Request.h"
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>

vovanex::Server::Server(const std::string &host, const std::string &port, const Router &router,
                        size_t client_buffer_size)
        : router(router), client_buffer_size(client_buffer_size) {

    std::cout << "Initializing WSA" << std::endl;
    this->check_WSA();

    addrinfo hints{AI_PASSIVE, AF_INET, SOCK_STREAM, IPPROTO_TCP};

    auto result = getaddrinfo(host.c_str(), port.c_str(), &hints, &addr);

    if (result != 0) {
        WSACleanup(); // очищение памяти, занимаемой библиотекой
        throw std::runtime_error("ERROR: getaddrinfo failed: " + std::to_string(result));
    }

    this->listen_socket = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);

    if (listen_socket == INVALID_SOCKET) {
        freeaddrinfo(addr);
        WSACleanup();
        throw std::runtime_error("Error at socket:  " + std::to_string(WSAGetLastError()));
    }

    std::cout << "Binding socket" << std::endl;
    result = bind(listen_socket, addr->ai_addr, (int) addr->ai_addrlen);

    if (result == SOCKET_ERROR) {
        freeaddrinfo(addr);
        closesocket(listen_socket);
        WSACleanup();
        throw std::runtime_error("Binding failed with error: " + std::to_string(WSAGetLastError()));
    }

    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
        closesocket(listen_socket);
        WSACleanup();
        throw std::runtime_error("Listening failed with error: " + std::to_string(WSAGetLastError()));
    }
}

int vovanex::Server::run() {
    auto client_buf = new char[client_buffer_size];
    auto client_socket = INVALID_SOCKET;

    std::cout << std::endl << "Listening to new clients..." << std::endl;

    while (true) {
        client_socket = accept(listen_socket, nullptr, nullptr);

        if (client_socket == INVALID_SOCKET) {
            closesocket(listen_socket);
            WSACleanup();
            throw std::runtime_error("ERROR: accept failed: " + std::to_string(WSAGetLastError()));
        }
        receive(client_buf, client_socket);
    }
}

void vovanex::Server::receive(char *client_buf, SOCKET client_socket) {
    auto result = recv(client_socket, client_buf, int(client_buffer_size), 0);
    if (result > 0) {
        client_buf[result] = '\0';
        print_message(client_buf);

        Request request (client_buf);
        auto response = router.get_response(request)->render();
        result = send(client_socket, response.str().c_str(), int(response.str().length()), 0);

        if (result == SOCKET_ERROR)
            std::cerr << "ERROR: send failed: " << WSAGetLastError() << "\n";

        closesocket(client_socket);

    } else if (result == 0) {
        std::cerr << "Connection closed" << std::endl << std::endl;
    } else if (result == SOCKET_ERROR) {
        std::cerr << "ERROR: receiving failed: " << result << std::endl;
        closesocket(client_socket);
    }
}

void vovanex::Server::check_WSA() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (result != 0)
        throw std::runtime_error("ERROR: WSAStartup failed: " + std::to_string(result));
}

vovanex::Server::~Server() {
    closesocket(listen_socket);
    freeaddrinfo(addr);
    WSACleanup();
}

void vovanex::Server::print_message(const char *const client_buffer) {
    std::cout << "[SERVER] ";

    size_t pos = 0;
    while (client_buffer[pos] != '\n')
        std::cout << client_buffer[pos++];

    std::cout << std::endl;
}
