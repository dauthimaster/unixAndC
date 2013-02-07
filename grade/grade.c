#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int grade[10];

    int i;
    //fill grade[] with 10 ints from user
    for(i=0; i<10; ++i){
        scanf("%d", grade + i);
        printf("%d\n", grade[i]);
    }

    double avg = 0;
    int high = 0;
    int low = 10; //init low to 10, that way 0-9 will work

    //add up each grade, check each grade against the current high and low
    //replace high or low if needed
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
