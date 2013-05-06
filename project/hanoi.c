//James Current
//display inspired by hanoi.c from JustForFun section @ 
//http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/index.html
#include <curses.h>
#include <stdlib.h>
#include <string.h>

#define POSX 10
#define POSY 5
#define DISK_CHAR '#'
#define PEG_CHAR '|'

//a peg is an array of disk sizes
typedef struct{
    int numOfDisks;         //size of the disk array
    int bottomX, bottomY;   //bottom x and y coordinates
    int *disks;             //array of disk sizes, representing a stack of disks
}peg;

void initPegs(peg *pegs, int numOfDisks);
void displayPegs(peg *pegs, int numOfDisks, int error);
void freeMem(peg *pegs, int numOfDisks);
int moveDisk(peg *pegs, int numOfDisks, int start, int end);
void printInMiddle(int x, int y, int width, char *message);
void playGame(peg *pegs, int numOfDisks);

int main(){
    int totalNumOfDisks = 6;
    peg pegs[3];

    initscr();          //start curses mode
    cbreak();           //no buffering
    keypad(stdscr, TRUE);   //enable F keys
    curs_set(FALSE);    //don't show cursor
    start_color();      //...start color...

    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_RED, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_RED);

    //printInMiddle(0, LINES / 2, COLS, "Enter the number of disks between 1 and 9 you would like to solve.", NULL);
    //scanw("%d", &numOfDisks);
    
    noecho();

    initPegs(pegs, totalNumOfDisks);
    displayPegs(pegs, totalNumOfDisks, 0);

    playGame(pegs, totalNumOfDisks);

    freeMem(pegs, totalNumOfDisks);
    endwin();       //end curses mode
    return 0;
}

//initialize the pegs and place all of the disks on the first peg
void initPegs(peg *pegs, int numOfDisks){
    int i, temp, size, bottomY;
    
    pegs[0].numOfDisks = numOfDisks;
    pegs[1].numOfDisks = 0;
    pegs[2].numOfDisks = 0;
    //allocate memory for the disks arrays in each peg
    for(i = 0; i < 3; ++i){
        pegs[i].disks = (int*)calloc(numOfDisks, sizeof(int));
    }

    size = 3 + 2 * (numOfDisks - 1);

    //bottom of the pile of disks is at the top of the array,
    //since we are treating the array like a stack.
    for(i = 0; i < numOfDisks; ++i, size -= 2){
        pegs[0].disks[i] = size;
    }
    //spacing for the first peg from the left edge
    temp = (pegs[0].disks[0] / 2);

    //all of the bottomY's will be the same
    bottomY = POSY + 2 + numOfDisks;

    pegs[0].bottomX = POSX + 1 + temp;
    pegs[0].bottomY = bottomY;

    //spacing for the other two pegs
    temp *= 2;

    //set the coordinates for the other two pegs
    for(i = 1; i < 3; ++i){
        pegs[i].bottomX = pegs[i-1].bottomX + 2 + temp;
        pegs[i].bottomY = bottomY;
    }
}

//clear whatever is on screen and display the current state of the pegs
void displayPegs(peg *pegs, int numOfDisks, int error){
    int i, j, k, x, y, size, width;

    clear();            //clear screen
    attron(A_REVERSE);  //highlighting on
    attron(COLOR_PAIR(6));
    mvprintw(24, 0, "Press F1 to Exit");
    attroff(COLOR_PAIR(6));

    //print peg labels
    for(i = 0; i < 3; ++i){
        mvprintw(pegs[i].bottomY + 2, pegs[i].bottomX, "%c", i + 1 + '0');
    }

    //length from the outer edges of the game screen
    width = pegs[2].bottomX + (3 + 2 * (numOfDisks - 1)) / 2 - (POSX + 1);

    if(error){
        attron(COLOR_PAIR(5));
    }
    switch(error){
        case 1: printInMiddle(POSX + 1, pegs[0].bottomY + 6, width, "Please choose a peg with a disk on it"); break;
        case 2: printInMiddle(POSX + 1, pegs[0].bottomY + 6, width, "You may only move a smaller disk to a larger disk. Try again"); break;
        default: printInMiddle(POSX + 1, pegs[0].bottomY + 6, width, "Which disk would you like to move?");
    }

    if(error){
        attroff(COLOR_PAIR(5));
    }

    attroff(A_REVERSE); //highlighting off

    //print the top of the peg
    for(i = 0; i < 3; ++i){
        attron(COLOR_PAIR(i+1));
        mvprintw(pegs[i].bottomY - numOfDisks - 1, pegs[i].bottomX, "%c", PEG_CHAR);
        attroff(COLOR_PAIR(i+1));
    }
    
    //y position of the first possible disk
    y = pegs[0].bottomY - numOfDisks;

    for(i = 0; i < 3; ++i){     //each peg
        //each disk, back to front, move down one for every disk
        //or peg segment we print
        for(j = numOfDisks - 1; j >= 0; --j, ++y){   
            if(pegs[i].disks[j]){       //do this if a disk is here
                size = pegs[i].disks[j];

                //starting x position is half the length of the disk,
                //the extra 1 caused by dividing an odd int by 2 is 
                //accounted for by the 1 char width of the peg.
                x = pegs[i].bottomX - (size / 2);

                //print the disk
                attron(COLOR_PAIR(4));
                for(k = 0; k < size; ++k){
                    mvprintw(y, x + k, "%c", DISK_CHAR);
                }
                attroff(COLOR_PAIR(4));
            } else {                    //do this if a disk isn't here
                //no disk, so just print a peg segment here
                attron(COLOR_PAIR(i+1));
                mvprintw(y, pegs[i].bottomX, "%c", PEG_CHAR);
                attroff(COLOR_PAIR(i+1));
            }
        }
        //reset the y for the next peg
        y = pegs[0].bottomY - numOfDisks;
    }
    //flush all changes to the screen
    refresh();
}

//clean up allocated memory for arrays
void freeMem(peg *pegs, int numOfDisks){
    int i;
    for(i = 0; i < 3; ++i){
        free(pegs[i].disks);
    }
}

void printInMiddle(int x, int y, int width, char *message){
    int length, temp;

    //width defaults to 80
    width = width ? width : 80;

    length = strlen(message);
    temp = (width - length) / 2;
    x += temp;
    mvprintw(y, x, "%s", message);
    refresh();
}

int moveDisk(peg *pegs, int numOfDisks, int start, int end){
    int temp, i, j;
    //don't do anything if the peg chosen to move from is empty
    if(!pegs[start].numOfDisks){
        return 1;
    }
    //set i to the top disk of the starting peg
    i = pegs[start].numOfDisks - 1;
    //set j to the empty slot at the top of the starting peg
    j = pegs[end].numOfDisks;
    //check to see if move is valid
    if(j && pegs[start].disks[i] > pegs[end].disks[j-1]){
        return 2;
    }
    //put the disk to be moved in temp
    temp = pegs[start].disks[i];
    //remove disk from the starting peg
    pegs[start].disks[i] = 0;
    --pegs[start].numOfDisks;

    //add the disk in temp to the end peg
    pegs[end].disks[j] = temp;
    ++pegs[end].numOfDisks;
    return 0;
}

void playGame(peg *pegs, int numOfDisks){
    int start, end, width, error;
    //loop until all disks are on the last peg
    while(pegs[0].numOfDisks || pegs[1].numOfDisks){
        start = getUserInput();

        if(start == -1){
            return;
        }

        move(pegs[0].bottomY + 6, 0);
        clrtoeol();   //clear first question

        width = pegs[2].bottomX + (3 + 2 * (numOfDisks - 1)) / 2 - (POSX + 1);
        attron(A_REVERSE);  //<highlight>
        printInMiddle(POSX + 1, pegs[0].bottomY + 6, width, "Where would you like to move it?");
        attroff(A_REVERSE); //</highlight>

        refresh();
        
        end = getUserInput();

        if(end == -1){
            return;
        }

        mvprintw(0, 0, "%d", start);
        mvprintw(1, 0, "%d", end);
        refresh();

        error = moveDisk(pegs, numOfDisks, start, end);
        displayPegs(pegs, numOfDisks, error);
    }
}

//returns index of chosen peg or -1 if they choose to exit
int getUserInput(){
    int ch;

    while(1){
        ch = getch();
        switch(ch){
            case KEY_F(1): return -1;
            case '1': return 0;
            case '2': return 1;
            case '3': return 2;
            default: break;
        }
    }
    return -1;
}

