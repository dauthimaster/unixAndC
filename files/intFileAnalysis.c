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
    int words = 0;
    while(fscanf(target, "%*d") != EOF){
        ++words;
    }
    rewind(target);
    return words;
}

int main(int argc, char * argv[]){
    FILE * target = NULL;
    if(argc > 1){
        target = fopen(argv[1], "r");

        if(target != NULL){
            int size = wordCount(target);
            if(size > 0){
                elem_type * a;
                a = (elem_type*) malloc(size);
                int i = 0;
                int high = INT_MIN;
                int low = INT_MAX;
                while(!feof(target)){
                    fscanf(target, "%d", a + i);
                    if((int)a[i] > high){
                        high = (int)a[i];
                    }
                    if((int)a[i] < low){
                        low = (int)a[i];
                    }
                    ++i;
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
