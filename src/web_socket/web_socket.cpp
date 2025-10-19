
#include "../../include/web_socket/web_socket.h"

// Default constructor
WEB_SOCKET::SimpleSocket::SimpleSocket( int domain, int service, int protocol, int port, u_long interface_ ){
    sock = socket(domain, service, protocol);

    //Define address strcuture
    address.sin_family = domain;
    address.sin_port = htonl(port);
    address.sin_addr.s_addr = htonl(interface_);

    // Bind address to socket

}

// test_connection() virtual function - args -> {sock, connection}
void WEB_SOCKET::SimpleSocket::test_connection(int item_to_test){
    // confirm that the socket or connection is properly established
    if (item_to_test < 0){
        perror("Failed to connect");
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in WEB_SOCKET::SimpleSocket::get_address(){
    return this->address;
};

int WEB_SOCKET::SimpleSocket::get_connection(){
    return this->connection;
}

int WEB_SOCKET::SimpleSocket::get_sock(){
    return this->sock;
}

// setter functions
void WEB_SOCKET::SimpleSocket::set_connection(int con){
    this->connection = con;
}

