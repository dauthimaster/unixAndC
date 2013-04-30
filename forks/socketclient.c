/*
 * James Current
 * 4/4/2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h> 
#define BUFF_SIZE 100

int main(int argc, char *argv[]){
    int sockfd, len, result;
    struct sockaddr_in address;
    char buff[BUFF_SIZE + 1];

    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1){
        perror("Socket create failed.\n") ;
        return -1 ;
    }
         
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(argv[1]);
    address.sin_port = htons(7734);
    len = sizeof(address);
         
    while (1){
        result = connect(sockfd, (struct sockaddr *)&address, len);
        if(result == -1){
            perror("Error has occurred");
            return -1;
        }

        fputs("Enter some keystrokes: ", stdout);
        fgets(buff, BUFF_SIZE, stdin);
        write(sockfd, buff, strlen(buff)+1);
                        
        if(buff[0] == '0'){
            break;
        }
        close(sockfd);
    }
           
    return 0;
}
