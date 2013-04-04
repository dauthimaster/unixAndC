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
        int fd1 = open("namedpipe", O_RDONLY);
        char buff[BUFF_SIZE + 1];
        read(fd1, buff, BUFF_SIZE + 1);
        printf("%s\n", buff);
        close(fd1);
        if(buff[0] == '0'){
            break;
        }
    }
    return 0;
}
