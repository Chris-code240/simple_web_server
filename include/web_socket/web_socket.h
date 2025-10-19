#ifndef WEB_SOCKET_H_INCLUDED
#define WEB_SOCKET_H_INCLUDED

#include <stdio.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <iostream>

namespace WEB_SOCKET {
class SimpleSocket {
    private:
        struct sockaddr_in address;
        int connection;
        int sock;
    public:
        // domain - {AF_INET (IP), AF_INET6(IPV6), AF_UNIX (local channel similar to pipes), AF_ISO (ISO protocols), AF_NS(Xerox Network Systems protocols}
        // service - { SOCK_STREAM (virtual circuit service), SOCK_DGRAM (datagram service), SOCK_RAW (direct IP service)}
        // interface - your ip address [it is in bytes same as port]
        SimpleSocket(int domain, int service, int protocol, int port, u_long interface_);

        // virtual function to connect to a network
        virtual int connect_to_network(int sock, struct sockaddr_in address) = 0;

        // functio to test socket and connection
        void test_connection(int item_to_test);

        //getter functions
        struct sockaddr_in get_address();
        int get_sock();
        int get_connection();

        // setter functiions

        void set_connection(int con);

};
}

#endif // SIMPLE_SOCKET_H_INCLUDED
