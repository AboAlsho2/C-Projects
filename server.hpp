#ifndef SERVER_HPP
#define SERVER_HPP
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <array>
#include <string>
#include <array>
#include <basetsd.h>
#include <iostream>
// #include <sys/socket.h> Linux
#include <winsock2.h>
#include <ws2tcpip.h>  // For inet_pton()
#include <algorithm>

#pragma comment(lib, "ws2_32.lib")  // Link against Winsock library
class Server
{
    private:
    int socket_fd;
    int client_socket_fd;
    std::array<char,5000> buffer ;

    public:
    Server();
    ~Server();
    bool server_init ();
    bool server_listen ();
    bool server_accept ();
    bool server_send (const std::string& message);
    std::string server_recive ();
    void close_listening();
    void close_server();
    void close_listening_client();
    void trim_end(std::string& str);


};
#endif // !