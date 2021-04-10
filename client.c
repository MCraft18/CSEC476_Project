#include<stdio.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

int client(){
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char *data;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) == 0)
    {
        printf("Initialised.\n");
    }

    s = socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket Created\n");

    server.sin_addr.s_addr = inet_addr("74.125.235.20");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    if(connect(s,(struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Connect error\n");
    }

    data = "GET / HTTP/1.1\r\n\r\n";
    if(send(s, data, strlen(data), 0) < 0)
    {
       puts("Send failed");
    }


    return 0;
}