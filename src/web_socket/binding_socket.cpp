#include "../../include/web_socket/binding_socket.h"


WEB_SOCKET::BindingSocket::BindingSocket( int domain, int service,  int protocol, int port, u_long interface_): SimpleSocket( domain, service, protocol, port, interface_){

    set_connection(connect_to_network( get_sock(), get_address()));
    std::cout<<"connection-> "<<get_connection()<<std::endl;
    // test_connection(get_connection());
}

int WEB_SOCKET::BindingSocket::connect_to_network(int sock, struct sockaddr_in address){

    return bind(sock, (struct sockaddr *)&address, sizeof(address));
}