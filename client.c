
#include <winsock2.h>
#include<stdio.h>
#pragma comment(lib, "ws2_32.lib")

int main(){
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char *data, server_response[2000];
    int recv_len;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) == 0)
    {
        printf("Initialised.\n");
    }

    s = socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket Created\n");

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);

    if(connect(s,(struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Connect error\n");
    }

   // data = "Hello server";
    //if(send(s, data, strlen(data), 0) < 0)
    //{
      // puts("Send failed");
    //}
    //else{
      //  printf("Send successful\n");
    //}

    if((recv_len = recv(s , server_response , 2000 , 0)) == SOCKET_ERROR)
    {
        puts("recv failed");
    }
    printf("Response text\n");
    puts("Reply received\n");

    //Add a NULL terminating character to make it a proper string before printing
    server_response[recv_len] = '\0';
    printf(server_response);


    printf("Test text\n");
    closesocket(s);
    return 0;
}