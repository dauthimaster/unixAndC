/*
 * James Current
 * 2/24/2013
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE * target = NULL;
    if(argc > 1){
        target = fopen(argv[1], "r");
    
        if(target != NULL){
            int ch;
            int chars = 0;
            int lines = 0;
            int words = 0;
            while (!feof(target)){
                ch = getc(target);
                ++chars;
//                printf("%d\n", ch);
                if(ch == '\n'){
                    ++lines;
                }
            }
            if(chars){
                rewind(target);
                while(fscanf(target, "%*s") != EOF){
                    ++words;
                }
            }
            printf("chars: %d\n", chars);
            printf("words: %d\n", words);
            printf("lines: %d\n", lines);
            fclose(target);
        } else {
            printf("Not a valid file");
        }
    }
    return 0;
}
