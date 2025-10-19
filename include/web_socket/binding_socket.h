#ifndef BINDING_SOCKET_H_INCLUDED
#define BINDING_SOCKET_H_INCLUDED

#include "./web_socket.h"


namespace WEB_SOCKET {
    class BindingSocket: public SimpleSocket  {
        public:
            BindingSocket(int domain, int service, int protocol, int port, u_long interface_);
            
            int connect_to_network(int sock, struct sockaddr_in address);
    };
    
}

#endif