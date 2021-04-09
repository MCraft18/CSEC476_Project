#include <stdio.h>
#include "server.c"
#include "client.c"
int main() {
    printf("Hello, Worlda!\n");
    serv();
    client();
    return 0;
}