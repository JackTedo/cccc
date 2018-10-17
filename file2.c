#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
add experimental


int main(int argc , char *argv[])
{
    int sock;
    struct sockaddr_in server;
    
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(5555);
    
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return 1;
    }
    puts("Connected\n");

    printf(argc);
    for(int i=1; i<agrc; i++){
        if( send(sock , argv[i] , strlen(argv[i]) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
    }
    return 0;
}
