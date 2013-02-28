/*
 * James Current
 * 2/14/2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
    int i, len, n;

    if(argc > 1){
        len = strlen(argv[1]);

        n = floor(len/2.0);

        char is = 1;

        for(i=0; i<n && is; ++i){
            is = is && argv[1][i]==argv[1][--len];
        }

        printf("%s %s a palindrome.\n", argv[1], is ? "is" : "is not");
    } else {
        printf("No arg passed, not cool dude...\n");
    }

    return 0;
}
