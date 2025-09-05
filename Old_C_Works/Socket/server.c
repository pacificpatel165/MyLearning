// Server side C/C++ program to demonstrate Socket
// programming
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const* argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in server_address, client_address;
    int opt = 1;
    int addrlen_client = sizeof(client_address);
    char ip_addr_str[INET_ADDRSTRLEN];
    char buffer[1024] = { 0 };
    char* hello = "Hi Message from Prashant";

    // Creating socket file descriptor
    printf("==> Creat socket descriptor on Server <==\n");
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
    	perror("socket failed");
    	exit(EXIT_FAILURE);
    }
    printf("server_fd = %d\n", server_fd);

    // Forcefully attaching socket to the port 8080
    printf("==> Forcing socket to reuser IP Address and Port(8080) through setsockopt <==\n");
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
    	perror("setsockopt");
    	exit(EXIT_FAILURE);
    }
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the IP Family(AF_INET), Address(INADDR_ANY) and Port(8080) of Server
    printf("==> Bind the IP Family(AF_INET), Address(INADDR_ANY) and Port(8080) of Server <==\n");
    inet_ntop(AF_INET, &server_address.sin_addr, ip_addr_str, INET_ADDRSTRLEN);
    printf("Server IP Family ==> %d\n", server_address.sin_family);
    printf("Server IP Address ==> %s\n", ip_addr_str);
    printf("Server Port Number ==> %d\n", htons(server_address.sin_port));
    if(bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
    {
    	perror("bind failed");
    	exit(EXIT_FAILURE);
    }

    printf("==> Listen maximum 3 client simultaneously <==\n");
    if(listen(server_fd, 3) < 0)
    {
    	perror("listen");
    	exit(EXIT_FAILURE);
    }

    printf("==> Accept the connection from Clients <==\n");
    while(1)
    {
        if((new_socket = accept(server_fd, (struct sockaddr*)&client_address, (socklen_t*)&addrlen_client)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        inet_ntop(AF_INET, &client_address.sin_addr, ip_addr_str, INET_ADDRSTRLEN);
        printf("Client IP Family ==> %d\n", client_address.sin_family);
        printf("Client IP Address ==> %s\n", ip_addr_str);
        printf("Client Port Number ==> %d\n", ntohs(client_address.sin_port));

        //printf("==> Going to read the message from Client through new file descriptor <==\n");
        memset(buffer, 0, 1024);
        valread = read(new_socket, buffer, 1024);
        printf("valread = %d\n", valread);
        printf("Message Received from Client as ==> %s\n", buffer);

        printf("==> Going to Send new message 'Hi Message from Prashant' to client <==\n");
        send(new_socket, hello, strlen(hello), 0);
    };

    // closing the connected socket
    printf("==> Closing the connected socket <==\n");
    close(new_socket);

    // closing the listening socket
    printf("==> Closing the listening socket <==\n");
    shutdown(server_fd, SHUT_RDWR);

    return 0;
}
