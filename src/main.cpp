#include <iostream>
#include <cerrno>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>


#include "../include/server/simple_server.h"

using namespace WEB_SERVER;


int main(){

    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cout << "WSAStartup failed: " << result << std::endl;
        return EXIT_FAILURE;
    }

    WebServer _server(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 1);
    _server.launch();
    return EXIT_SUCCESS;
}
