#ifndef SIMPLE_SERVER_H_INCLUDED
#define SIMPLE_SERVER_H_INCLUDED

#include "../web_socket/socket_main.h"

using namespace WEB_SOCKET;

namespace WEB_SERVER {
    class SimpleServer{

        private:
            ListeningSocket * server_socket;
            virtual void acceptor() = 0;
            virtual void handler() = 0;
            virtual void responder() = 0;
        public:
            SimpleServer( int domain, int service, int protocol, int port, u_long interface_, int backlog_);

            virtual void launch() = 0;

            ListeningSocket * get_server_socket();

    };

    class WebServer : public SimpleServer {

        private:
            void acceptor();
            void responder();
            void handler();
            int client_socket;
        public:
            WebServer( int domain, int service, int protocol, int port, u_long interface_, int backlog_);
            void launch();
    };
}

#endif