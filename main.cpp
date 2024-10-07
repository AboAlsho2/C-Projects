#include "server.hpp"
#include "command.hpp"
#include <iostream>

int main() {
    Server server;
    Command cmd;
    std::string buffer;

    if (!server.server_init()) {
        std::cerr << "Server initialization failed" << std::endl;
        return -1;
    }
    if (!server.server_listen()) {
        std::cerr << "Server listening failed" << std::endl;
        return -2;
    }

    while (true) {
        std::cout << "Waiting for client connection..." << std::endl;
        if (server.server_accept()) {
            std::cout << "Client connected." << std::endl;
            server.server_send("/--------Welcome------------/\n");
            server.server_send("Enter a command or type 'exit' to quit\n");

            while (true) {
                buffer = server.server_recive();
                server.trim_end(buffer);
                std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);

                if (buffer == "exit") {
                    server.server_send("Exiting the server...\n");
                    server.close_server();
                    std::cout << "Program finished." << std::endl;
                    return 0;
                }

                else if (buffer == "google") {
                    cmd.open_google();
                }
                else if (buffer == "youtube") {
                    cmd.open_youtube();
                }
                else if (buffer == "github") {
                    cmd.open_github();
                }
                else if (buffer == "linkedin") {
                    cmd.open_linkedin();
                }
                else if (buffer == "facebook") {
                    cmd.open_facebook();
                }
                else if (buffer == "amazon") {
                    cmd.open_amazon();
                }
                else if (buffer == "chatgpt") {
                    cmd.open_chatgpt();
                }
                else if (buffer == "vscode") {
                    cmd.open_vscode();
                }
               
                else if (buffer == "visual studio") {
                    cmd.open_visual_studio_2022();
                }
                else if (buffer == "whatsapp") {
                    cmd.open_whatsapp();
                }
                else if (buffer == "telegram") {
                    cmd.open_telegram();
                }
                else if (buffer == "discord") {
                    cmd.open_discord();
                }
                else if (buffer == "alarm") {
                    cmd.open_alarm();
                }
                else if (buffer == "chrome") {
                    cmd.open_chrome();
                }
                else if (buffer == "edge") {
                    cmd.open_edge();
                }
                else if (buffer == "pes19") {
                    cmd.open_pes19();
                }
                else if (buffer == "power off") {
                    cmd.shutdown_pc();
                }
                else {
                    std::cout << "Unknown command: " << buffer << std::endl;
                }
                
                
            }
        }
    }
}