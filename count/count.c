#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int count[10] = {[0 ... 9] = 0};
    char c;
    
    do{
        c=getchar();
        int i = c - '0';
        if(i >= 0 && i < 10){
            ++count[i];
        }
    }while(c != EOF);

    printf("0 1 2 3 4 5 6 7 8 9\n");
    
    int i;
    for(i=0; i < 10; ++i){
        printf("%d ", count[i]);
    }
    printf("\n");

    return(0);
}
