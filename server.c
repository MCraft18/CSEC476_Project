#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib, "ws2_32.lib")


int main(){
    WSADATA wsa;
    SOCKET s, new_socket;
    struct sockaddr_in server, client;
    int c;
    char *message;

    if (WSAStartup(MAKEWORD(2,2),&wsa) == 0)
    {
        printf("Initialised.\n");
    }

    s = socket(AF_INET, SOCK_STREAM, 0);
    printf("Server socket created\n");

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(12345);

    bind(s ,(struct sockaddr *)&server , sizeof(server));
    puts("Bind done");

    listen(s, 100);
    printf("Waiting for connections...\n");

    c = sizeof(struct sockaddr_in);
    accept(s, (struct sockaddr *)&client, &c);
    printf("Connection accepted");

    message = "Hello Client\n";
    send(new_socket , message , strlen(message) , 0);
    //getchar();
    closesocket(s);
    return 0;
}