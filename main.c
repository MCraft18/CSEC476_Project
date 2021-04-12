#include <stdio.h>
#include "server.c"
#include "client.c"
int main() {
    printf("Hello, World!\n");
    client();
    serv();
    return 0;
}