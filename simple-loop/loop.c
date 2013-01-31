#include <stdio.h>
#include <stdlib.h>

void binary(unsigned int in);

int main(){
    int i;
    for(i=0; i <= 100; ++i){
        printf("%d, %o, %x, ", i, i, i);
        binary(i);
        printf("\n");
    }

    return(0);
}

void binary(unsigned int in){
    if(in){
        binary(in >> 1);
    }else{
        return;
    }
    if(in & 1){
        printf("1");
    }else{
        printf("0");
    }
    return;
}
