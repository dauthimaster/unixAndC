#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[]){
    int i, j, len;
    char * reverse;
        
    len = strlen(argv[1]);

    reverse = (char*) malloc(len + 1); 

    for(i=len-1,j=0;i>=0;--i,++j){
        reverse[i] = argv[1][j];
    }
                          
    printf("%s\n", reverse);
                                                                    
    return 0;
}
