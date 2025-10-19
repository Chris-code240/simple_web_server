#include <include/web_socket/connecting_socket.h>

WEB_SOCKET::ConnectingSocket::ConnectingSocket(  int domain, int service,  int protocol, int port, u_long interface_): SimpleSocket( domain, service, protocol, port, interface_){

    set_connection(connect_to_network(get_sock(), get_address()));

    test_connection(get_connection());
}

int WEB_SOCKET::ConnectingSocket::connect_to_network(int sock, struct sockaddr_in address){
    return connect(sock, ( struct sockaddr *)&address, sizeof(address));
}