//
// Created by michal on 24/01/2020.
//

#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *c) {
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        exit(1);
    }
    //bind socket to IP address
    // we first need to create the sockaddr obj.
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);
    //we need to convert our number
    // to a number that the network understands.

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        exit(1);
    }

    //making socket listen to the port
    if (listen(socketfd, 10) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        exit(1);
    } else {
        std::cout << "Parallel Server is now listening ..." << std::endl;
    }
    thread serverThread([=]{loop(socketfd, address, c);});
    serverThread.join();
}

void MyParallelServer::stop(int socketfd) {
    this->stopLoop = true;
}

void MyParallelServer::loop(int socketfd, sockaddr_in address, ClientHandler *c) {
    struct timeval tv{};
    tv.tv_sec = 120;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
    while(!stopLoop) {
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        if (client_socket == -1) {
            if (errno == EWOULDBLOCK) {
                cout << "timeout" << endl;
                this->stop(socketfd);
                break;
            } else {
                cout<<"error"<<endl;
                exit(1);
            }
        }
        ClientHandler* newC = c->clone();
        thread cThread([=]{clientTheard(client_socket,newC);});
        cThread.detach();
    }
}

void MyParallelServer::clientTheard(int client_socket, ClientHandler *c) {
    c->handleClient(client_socket);
}
