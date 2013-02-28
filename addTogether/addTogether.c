/*
 * James Current
 * 2/14/2013
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    if(argc > 1){
        int i, tot;

        tot = 0;

        for(i=1; i<argc; ++i){
            tot += strtol(argv[i], NULL, 10);
        }

        printf("sum is %d\n", tot);
    }

    return 0;
}
