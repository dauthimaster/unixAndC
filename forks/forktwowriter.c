/*
 * James Current
 * 4/4/2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define BUFF_SIZE 100

int main(){
    while(1){
        char buff[BUFF_SIZE + 1];
        int fd1 = open("namedpipe", O_WRONLY);
        fputs("Enter some keystrokes: ", stdout);
        fgets(buff, BUFF_SIZE, stdin);
        write(fd1, buff, strlen(buff)+1);
        close(fd1);
        if(buff[0] == '0'){
            break;
        }
    }
    return 0;
}
