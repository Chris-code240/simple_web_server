#include <iostream>
#include <cerrno>
#include <cstring>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "../include/web_socket/binding_socket.h"

using namespace WEB_SOCKET;


int main(){

    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cout << "WSAStartup failed: " << result << std::endl;
        return EXIT_FAILURE;
    }

    BindingSocket  _socket (AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY);
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        std::cout << "socket() failed: " << strerror(errno) << std::endl;
    }


    return EXIT_SUCCESS;
}