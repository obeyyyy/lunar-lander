#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#define DELAY 30000

    
void fuel(int *fuel)
{
*fuel=500;
}
    

int main(int argc, char *argv[])
{
   
 initscr();
 noecho();
 curs_set(FALSE);
 bool GameOver =false;
 keypad(stdscr, TRUE); // enables arrows reading for controlls
 double X = 0;
 // new x position of the ship
 double Y = 0;
 // new y position of the ship
 int MaxX=0; // maXx position to detect the end x position of the screen
 int MaxY=0; // maxYposition to detect the end y position of the screen
 getmaxyx(stdscr, MaxY,MaxX);  //function for getting the widnow size for stopping the ship to go through the window
 int boost = 8;
 char *ship = "A";
 char land[] = "_____/---/_5xscore________________|XX|_20xscore__________________|~~~WATER~~~~|______________________";

while(GameOver != TRUE)
{
double acceleration;
double gr; //gravity

clear();
gr= gr + 0.002; // increasing the gravity by the time goes
X+=gr; // apply the gravity to the ship
mvprintw(X,Y,"%s", ship); // prints the ship in an this form;//*
mvprintw(40,1,land);
//mvprintw(1,30,fuel())
usleep(ESCDELAY);

refresh();
cbreak();
int input;
input = getch();




if (input == KEY_UP)
{
     // if the up arrow is pressed, the ship accelerates up
     acceleration+=0.00005; 
     X-=acceleration;
     gr-=acceleration; 
     
}

if(input == KEY_RIGHT)
{
    Y  +=0.5;  // if the right arrow is pressed, the ship moves right
}
if (input == KEY_LEFT)
{
    Y -= 0.5;  // if the left arrow is pressed, the ship moves left
}
if(input == 'p')
{
    GameOver = TRUE; // if p is pressed or A is out of range,GAMEOVER;
}


timeout(50);
refresh();
}
endwin();
}
