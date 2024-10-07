#include "server.hpp"



Server::Server(){};
Server::~Server()
{
    if( socket_fd != -1 ){
        closesocket(socket_fd);
    }
    if( client_socket_fd != -1 ){
        closesocket(client_socket_fd);
    }
};

bool Server::server_init() {
    WSADATA wsaData; // Store information about the current state of the sockets system.
    
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
        return false;
    }

    sockaddr_in sock_add;
    // Initialize socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == INVALID_SOCKET) {
        std::cerr << "Cannot create socket, error: " << WSAGetLastError() << std::endl;
        WSACleanup();  // Cleanup here if socket creation fails
        return false;
    }

    sock_add.sin_family = AF_INET;  // Use IPv4
    sock_add.sin_port = htons(8000);  // Port number, converted to network byte order
    sock_add.sin_addr.s_addr = inet_addr("192.168.1.5");  // Localhost IP //write ipconfig on the cmd to get it 

    // Binding the socket
    if (bind(socket_fd, (sockaddr*)&sock_add, sizeof(sock_add)) == SOCKET_ERROR) {
        std::cerr << "Cannot bind, error: " << WSAGetLastError() << std::endl;
        closesocket(socket_fd);  // Close the socket if binding fails
        WSACleanup();  // Cleanup after failure
        return false;
    }

    return true;
}



bool Server::server_listen ()
{
    if(listen(socket_fd,2)== SOCKET_ERROR){
        //SOCKET_ERROR =-1 so we can use listen()< 0 
        //backlog refer to queue size (the server can hold up to two pending connections in the queue at once)
        std::cout<<"cannot listen "<<std::endl;
    }
    std::cout << "Server is listening.... " << std::endl;
    return true ;
};

bool Server::server_accept ()
{
    sockaddr_in client;
    //sockaddr_in is a structure (sockaddr_in) that stores information about the address family IPv4(AF_INET)
    //sock_add will hold information about the connected server , including its IP address and port number.
    socklen_t client_size=sizeof(client);
    //socklen_t  is an integer type used to represent the size of a socket address structure(in bytes).

    client_socket_fd=accept(socket_fd, (sockaddr*) &client, &client_size);
    //accept() needs to know where to store the information about the client that is connecting.
    //sockaddr_in speify for ipv4 while acccept recive more general structure 
    // accept(server's socket descriptor,pointer ro sockaddr structue where we store info about the client,pointer size of memory that could be written in for the client )
    // On success, accept() returns a new socket descriptor (client_socket_fd) specifically for the connection with the client.
    //On failure, it returns INVALID_SOCKET on Windows -1 in Linux.
    if(client_socket_fd==SOCKET_ERROR)
    {
        std::cout<<"Problem with client connection" << std::endl;
        return false; // Return false if there's a problem
    }
    return true; // Return true if the client is successfully accepted
    
};

bool Server::server_send (const std::string& message)
{
    send(client_socket_fd,message.c_str(),message.size(),0);
    //client_socket_fd This is the socket descriptor for the connected client.
    //massaage.c_str() converts the C++ std::string into a format that the send() function can work with.
    //message.size() tells send() how many bytes to transmit.
    // flag 0 meaning no special options are used.
    return true ;
};
std::string Server::server_recive ()
{
    int read_data = recv(client_socket_fd,(buffer.data()),buffer.size()-1,0); 
    if (read_data==SOCKET_ERROR)
    {
        std::cerr << "Error receiving data" << std::endl;
        return "Error receiving data";
    }else if (read_data == 0) {
 //       std::cout << "Client closed connection" << std::endl;
        return "Client closed connection";
    }
    else {
    std::string buffer_str(buffer.data(),read_data);
    //buffer.data() gives you the raw data
    //read_data tells you how many bytes were received.
    // The string is then constructed with the received data.
    std::cout << "Received message: " << buffer_str << std::endl;
    return buffer_str;
    }
};

void Server::close_listening(){
    closesocket(socket_fd);
    //use close() for Linux 
}
//the socket is invalid, and the server will stop accepting new incoming connections.
void Server::close_listening_client(){
    closesocket(client_socket_fd);
    //use close() for Linux 
}
//This terminate the client connection when the server no longer needs to communicate with the client.

void Server::close_server() {
    if (client_socket_fd != -1) {
        closesocket(client_socket_fd);  // Close the client socket if it's valid
        //use close() for Linux 
        client_socket_fd = -1;          // Set it to -1 after closing
    }
};
void Server::trim_end(std::string& str) {
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}
//function is for cleaning up strings by removing trailing whitespace not important for socket 
