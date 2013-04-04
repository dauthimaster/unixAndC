/*
 * James Current
 * 4/4/2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_SIZE 10

void uppercase(char *sPtr){ 
    while(*sPtr != '\0'){
        *sPtr++ = toupper(*sPtr);
    }
}

int main(){
    int fd[2];
    char buff[BUFF_SIZE + 1];
    if(pipe(fd) == 0){
        if(fork() != 0){
            //parent
            close(fd[1]);
            read(fd[0], buff, BUFF_SIZE);
            uppercase(buff);
            printf("Input from keyboard: %s.\n", buff);
            close(fd[0]);
        } else {
            //child
            close(fd[0]);
            fputs("Enter some keystrokes: ", stdout);
            fgets(buff, BUFF_SIZE, stdin);
            write(fd[1], buff, strlen(buff));
            close(fd[1]);
        }
    }
    return 0;
}
