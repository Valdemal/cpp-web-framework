cmake_minimum_required(VERSION 3.24)
project(CN8)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
        headers/Server.cpp headers/Server.h headers/View.h headers/Response.h headers/View.cpp headers/Response.cpp headers/Request.h headers/method.h headers/method.cpp headers/Request.cpp headers/utils.h headers/utils.cpp headers/Router.h headers/Router.cpp headers/http_status.h headers/http_status.cpp)

add_executable(CN8 main.cpp ${SOURCES})
target_link_libraries(CN8 ws2_32)
