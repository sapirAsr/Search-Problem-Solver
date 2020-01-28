//
// Created by michal on 14/01/2020.
//

#include <cstring>
#include "MySerialServer.h"

/**
 * @param port the port we want to connect.
 * @param c client handler.
 */
void MySerialServer::open(int port, ClientHandler *c) {
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
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr << "Error during listening command" << std::endl;
        exit(1);
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }
//timeout waiting for client
    // accepting a client

   // close(socketfd); //closing the listening socket

    //reading from client
    thread serverThread([=]{loop(socketfd, address, c);});
    serverThread.join();
    stop(socketfd);
}

/**
 * this func will connect a client to socket.
 * @param socketfd the socket we want all our clients to connect.
 * @param address the addres we want to connect.
 * @param c the client handler that we will use.
 */
void MySerialServer::loop(int socketfd,sockaddr_in address, ClientHandler* c) {
    struct timeval tv{};
    tv.tv_sec = 120;
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
    int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
    while (client_socket != -1) {
        c->handleClient(client_socket);
        client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
        if (errno == EWOULDBLOCK) {
            cout << "timeout" << endl;
        }
    }
}

/**
 * this func stops the running.
 * @param socketfd the number of the socket we want to connect
 */
void MySerialServer::stop(int socketfd) {
    close(socketfd);
}
