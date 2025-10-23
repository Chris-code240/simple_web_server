#include "../../include/server/simple_server.h"
#include <string>

using namespace WEB_SOCKET;


WEB_SERVER::SimpleServer::SimpleServer(int domain, int service, int protocol, int port, u_long interface_, int backlog_){

    server_socket = new ListeningSocket( domain, service, protocol, port, interface_, backlog_);

}

ListeningSocket * WEB_SERVER::SimpleServer::get_server_socket(){
    return this->server_socket;
}



WEB_SERVER::WebServer::WebServer(int domain, int service, int protocol, int port, u_long interface_, int backlog_):SimpleServer(domain, service, protocol, port, interface_, backlog_){
                std::cout<<">>>>>>>>>Server instantiated<<<<<<<<<<<<<<<<<"<<std::endl;
}

void WEB_SERVER::WebServer::acceptor() {
    struct sockaddr_in address_;
    socklen_t addrlen = sizeof(address_);
    std::cout<<"About to accept... [sock: "<<std::endl<<get_server_socket()->get_sock()<<", address: "<< (std::string *)&address_<<std::endl;
    
    int client_socket = accept(get_server_socket()->get_sock(),(struct sockaddr*)&address_, &addrlen );
    std::cout<<"Processing socket..."<<std::endl;

    

    if (client_socket < 0) {
        perror("Accept failed");
        return;
    }

    std::cout << "Connection accepted!" <<std::endl;
}


void WEB_SERVER::WebServer::handler() {
    std::cout<<"Processing connection..."<<std::endl;
    const int BUFFER_SIZE = 30000;
    char buffer[BUFFER_SIZE] = {0};
    long valread = recv(client_socket, buffer, BUFFER_SIZE, 0);

    if (valread > 0)
        std::cout << "Received: " << buffer << std::endl;
    std::cout<<"Connection processed..."<<std::endl;
    
}

void WEB_SERVER::WebServer::responder() {
    const char msg[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nhello from server";
    std::cout<<"Responding..."<<std::endl;

    send(client_socket, msg, strlen(msg), 0);
    closesocket(client_socket);
}


void WEB_SERVER::WebServer::launch(){
    std::cout<<"-------------Server is Runing--------------"<<std::endl;
    while(true){
            std::cout<<"=======WAITING========="<<std::endl;
            acceptor();
            handler();
            responder();
            std::cout<<"===DONE==="<<std::endl;
    }
}
