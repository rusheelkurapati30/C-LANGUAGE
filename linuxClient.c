// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <netdb.h> 

// void error(const char *msg)
// {
//     perror(msg);
//     exit(0);
// }

// int main(int argc, char *argv[])
// {
//     int sockfd, portno, n;
//     struct sockaddr_in serv_addr;
//     struct hostent *server;

//     char buffer[256];
//     if (argc < 3) {
//        fprintf(stderr,"usage %s hostname port\n", argv[0]);
//        exit(0);
//     }
//     portno = atoi(argv[2]);
//     sockfd = socket(AF_INET, SOCK_STREAM, 0);
//     if (sockfd < 0) 
//         error("ERROR opening socket");
//     server = gethostbyname(argv[1]);
//     if (server == NULL) {
//         fprintf(stderr,"ERROR, no such host\n");
//         exit(0);
//     }
//     bzero((char *) &serv_addr, sizeof(serv_addr));
//     serv_addr.sin_family = AF_INET;
//     bcopy((char *)server->h_addr, 
//          (char *)&serv_addr.sin_addr.s_addr,
//          server->h_length);
//     serv_addr.sin_port = htons(portno);
//     if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
//         error("ERROR connecting");
//     printf("Client: ");
//     while(1)
//     {
//         bzero(buffer,256);
//         fgets(buffer,255,stdin);
//         n = write(sockfd,buffer,strlen(buffer));
//         if (n < 0) 
//              error("ERROR writing to socket");
//         bzero(buffer,256);
//         n = read(sockfd,buffer,255);
//         if (n < 0) 
//              error("ERROR reading from socket");
//         printf("Server : %s\n",buffer);
//         int i = strncmp("Bye" , buffer , 3);
//         if(i == 0)
//                break;
//     }
//     close(sockfd);
//     return 0;
// }




































#include<netdb.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#define MAX 80 
#define PORT 8081
#define SA struct sockaddr 

void func(int sockfd) 
{ 
    char buff[MAX];
    int n; 

for (;;) 
{
 
    bzero(buff, sizeof(buff)); 
    printf("Enter the string : "); 
    
    n = 0; 
    while ((buff[n++] = getchar()) != '\n');
    
    write(sockfd, buff, sizeof(buff)); 
    
    bzero(buff, sizeof(buff)); 
    
    read(sockfd, buff, sizeof(buff)); 
    
    printf("From Server : %s", buff); 
        
    if ((strncmp(buff, "exit", 4)) == 0) 
    { 
        printf("Client Exit...\n"); 
        break; 
     
    } 
} 

}


int main() 
{ 
    
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli;   

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    
    if (sockfd == -1) { 
    
    printf("socket creation failed...\n"); 
    exit(0);
     
    } 
    else
    printf("Socket successfully created..\n"); 
    
    bzero(&servaddr, sizeof(servaddr)); 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 

    // Connect(sockid,&address,addrlen)
    
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
    
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
    printf("connected to the server..\n"); 
    
    func(sockfd); 
    close(sockfd); 
    
}