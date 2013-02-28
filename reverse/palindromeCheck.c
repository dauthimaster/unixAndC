/*
 * James Current
 * 2/14/2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char isPalindrome(char * victim);

int main(int argc, char * argv[]){
    if(argc > 1){
        int i;
        for(i=1; i<argc; ++i){
            printf("%s - %s a palindrome\n", argv[i], isPalindrome(argv[i]) ? "is" : "is not");
        }
    } else {
        printf("Need args!!!!\n");
    }
}

char isPalindrome(char * victim){
    int i, n, len;

    len = strlen(victim);

    n = floor(len/2.0);

    char is = 1;

    for(i=0; i<n && is; ++i){
        is = is && victim[i]==victim[--len];
    }

    return is;
}
