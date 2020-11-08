// #ifdef WIN32
#include<winsock2.h>
#include<windows.h>
#include<winsock.h>
#include<ws2tcpip.h>// for socklen_t
// #else
// #define closesocket close
#include <unistd.h>
// #include <sys/types.h> 
// #include <sys/socket.h>
#include<winsock.h>
// #include <netinet/in.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argCount, char *argList[])
{
    if(argCount < 2)
    {
        fprintf(stderr, "Port Number not provided.");
        exit(1);
    }

    int sockfd, newsockfd, portno, n;
    char buffer[255];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("ERROR opening socket");
    }

    memset((char *) &serv_addr,0,  sizeof(serv_addr));
    portno = atoi(argList[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
     
    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("Binding Failed.");

    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
          error("ERROR on accept");
    while(1)
    {
        memset(buffer,0 , 255);
        n = read(newsockfd, buffer, 255);
        if (n < 0) 
            error("ERROR reading from socket");
        printf("Client: %s\n", buffer);
        memset(buffer,0 , 255);
        fgets(buffer, 255, stdin);

        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) 
            error("ERROR writing to socket");
        
        int i = strncmp("Bye" , buffer, 3);
        if(i == 0)
        break;
    }
    close(newsockfd);
    close(sockfd);
    return 0; 
 }