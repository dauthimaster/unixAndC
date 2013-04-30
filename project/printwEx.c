#include <ncurses.h>
#include <string.h>

int main(){
    char mesg[] = "Just a string";          //message to appear on screen
    int row, col;                           //row and column storage

    initscr();
    getmaxyx(stdscr, row, col);             //get the number of rows and columns
    mvprintw(row/2, (col-strlen(mesg))/2, "%s", mesg); //print message at center of screen
    mvprintw(row-2, 0, "this screen has %d rows and %d columns\n", row, col);
    printw("Try resizing your window(if possible) and then run this program again");
    refresh();
    getch();
    endwin();

    return 0;
}
