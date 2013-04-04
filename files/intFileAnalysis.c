/*
 * James Current
 * 2/28/2013
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Algorithm from N. Wirth's book, implementation by N. Devillard.
 * This code in public domain.
 */


typedef int elem_type ;

#define ELEM_SWAP(a,b) { register elem_type t=(a);(a)=(b);(b)=t; }


/*---------------------------------------------------------------------------
 *    Function :   kth_smallest()
 *    In       :   array of elements, # of elements in the array, rank k
 *    Out      :   one element
 *    Job      :   find the kth smallest element in the array
 *    Notice   :   use the median() macro defined below to get the median. 
 *
 *                 Reference:
 *
 *                   Author: Wirth, Niklaus 
 *                    Title: Algorithms + data structures = programs 
 *                Publisher: Englewood Cliffs: Prentice-Hall, 1976 
 *     Physical description: 366 p. 
 *                   Series: Prentice-Hall Series in Automatic Computation 
 *
 *---------------------------------------------------------------------------*/


elem_type kth_smallest(elem_type a[], int n, int k)
{
    register i,j,l,m ;
    register elem_type x ;

    l=0 ; m=n-1 ;
    while (l<m) {
        x=a[k] ;
        i=l ;
        j=m ;
        do {
            while (a[i]<x) i++ ;
            while (x<a[j]) j-- ;
            if (i<=j) {
                ELEM_SWAP(a[i],a[j]) ;
                i++ ; j-- ;
            }
        } while (i<=j) ;
        if (j<k) l=i ;
        if (k<i) m=j ;
    }
    return a[k] ;
}


#define median(a,n) kth_smallest(a,n,(((n)&1)?((n)/2):(((n)/2)-1)))

int wordCount(FILE * target){
    int c;
    int words = 0;
    while(!feof(target)){
        while((c = getc(target)) != EOF){
            if(isdigit(c)){
                ++words;
                break;
            }
        }

        for(; c != EOF; c = getc(target)){
            if(!isdigit(c)){
                break;
            }
        }
    }
    return words;
}

long getLong(FILE * target){
    int c;
    char str[12] = {0};
    int i = 0;
    while((c = getc(target)) != EOF){
        if(isdigit(c)){
            str[i++] = c;
            break;
        }
    }

    c = getc(target);

    for(; c != EOF; c = getc(target)){
        if(i < 11){
            if(isdigit(c)){
                str[i++] = c;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    if(!i){
        return -1;
    }
    return strtol(str, NULL, 10);
}

int main(int argc, char * argv[]){
    FILE * target = NULL;
    if(argc > 1){
        target = fopen(argv[1], "r");

        if(target != NULL){
            int size = wordCount(target);
            rewind(target);
            if(size > 0){
                elem_type * a;
                a = (elem_type*) malloc(size);
                int i = 0;
                int high = INT_MIN;
                int low = INT_MAX;
                while(!feof(target)){
                    int check = getLong(target);
                    if(check > 0){
                        a[i] = check;
                        if((int)a[i] > high){
                            high = (int)a[i];
                        }
                        if((int)a[i] < low){
                            low = (int)a[i];
                        }
                        ++i;
                    }
                }
                int median = (int)median(a, size);
                printf("Largest: %d\n", high);
                printf("Lowest: %d\n", low);
                printf("Median: %d\n", median);
            } else {
                printf("No ints found in file.\n");
            }
        } else {
            printf("File not found.\n");
        }
    }
    return 0;
}
