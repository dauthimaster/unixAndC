#include <ncurses.h>

int main(){
    int ch;

    initscr();              //start curses mode
    raw();                  //line buffering disabled
    keypad(stdscr, TRUE);   //We get F1, F2, arrows, etc...
    noecho();               //Don't echo() while doing getch

    printw("Type any character to see it in bold\n");
    ch = getch();           /* If raw hadn't been called
                             * we have to press enter before it
                             * gets to the program
                             */
    if(ch == KEY_F(1)){         //Without keypad this wouldn't get to us either
        printw("F1 Key pressed");
    } else {
        printw("The pressed key is ");
        attron(A_BOLD);
        printw("%c", ch);
        attroff(A_BOLD);
    }
    refresh();              //print to real screen
    getch();                //wait for user input
    endwin();               //end curses mode

    return 0;
}
