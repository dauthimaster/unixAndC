#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int grade[10];

    int i;
    for(i=0; i<10; ++i){
        scanf("%d", grade + i);
        printf("%d\n", grade[i]);
    }

    double avg = 0;
    int high = 0;
    int low = 10;

    for(i=0; i<10; ++i){
        avg += grade[i];
        
        if(grade[i] > high){
            high = grade[i];
        }
        
        if(grade[i] < low){
            low = grade[i];
        }
    }

    avg /= 10.0;

    printf("Average: %f\n", avg);
    printf("Highest: %d\n", high);
    printf("Lowest: %d\n", low);

    return 0;
}
