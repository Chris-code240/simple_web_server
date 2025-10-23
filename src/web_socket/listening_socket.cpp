#include "../../include/web_socket/listening_socket.h"

WEB_SOCKET::ListeningSocket::ListeningSocket( int domain, int service, int protocol, int port, u_long interface_, int backlog_) : BindingSocket( domain, service, protocol, port, interface_){
    backlog = backlog_;
    start_listening();
    test_connection(listening);
}

void WEB_SOCKET::ListeningSocket::start_listening(){
    listening = listen(get_sock(), backlog);

}
