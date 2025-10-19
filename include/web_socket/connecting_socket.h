#ifndef CONNECTING_SOCKET_H_INCLUDED
#define CONNECTING_SOCKET_H_INCLUDED

#include <stdio.h>
#include <include/web_socket/binding_socket.h>

namespace WEB_SOCKET {

    class ConnectingSocket: public SimpleSocket{

        public:
            ConnectingSocket( int domain, int service, int protocol, int port, u_long interface_);

            int connect_to_network(int sock, struct sockaddr_in address);
    };
}

#endif