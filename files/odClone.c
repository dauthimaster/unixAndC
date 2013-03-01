/*
 * James Current
 * 2/28/2013
 */
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;

long processLine(BYTE * contents, long size, long offset){
    printf("%06d          ", offset);
    char str[11];
    str[10] = 0;
    long i = offset;
    for(; i<offset+10; ++i){
        if(i < size){
            printf("%02X ", contents[i]);
            if(isprint(contents[i]) && contents[i] != '\n'){
                str[i - offset] = contents[i];
            } else {
                str[i - offset] = '.';
            }
        }
    }
    printf("         %s",str);
    return offset + 10;
}

void output(BYTE * contents, long size){
    long i = 0;
    while(i < size){
        i = processLine(contents, size, i);
        printf("\n");
    }
}

int main(int argc, char * argv[]){
    FILE * target = NULL;
    if(argc > 1){
        target = fopen(argv[1], "r");

        if(target != NULL){
            BYTE * buffer;
            long fSize;

            fseek(target, 0, SEEK_END);
            fSize = ftell(target);
            rewind(target);

            buffer = (BYTE*) malloc (sizeof(BYTE)*fSize);

            fread(buffer, 1, fSize, target);
            
            output(buffer, fSize);
            free(buffer);
        }
    }
    fclose(target);
    return 0;
}
