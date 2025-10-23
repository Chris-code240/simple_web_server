#ifndef LISTENING_SOCKET_H_INCLUDED
#define LISTENING_SOCKET_H_INCLUDED

#include "./binding_socket.h"

namespace WEB_SOCKET {

    class ListeningSocket: public BindingSocket {
        private:
            int backlog;
            int listening;
        public:
            ListeningSocket( int domain, int service, int protocol, int port, u_long interface_, int backlog_);

            void start_listening();
    };  
}

#endif