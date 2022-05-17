#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#define DELAY 30000

    

    
int main(int argc, char *argv[])
{
   

 initscr();
 noecho();
 curs_set(FALSE);
 bool GameOver =false;
 keypad(stdscr, TRUE); // enables arrows reading for controlls
 double X = 0;
 double *movX = &X; // new x position of the ship
 double Y = 0;
 double *movY = &Y;// new y position of the ship
 int MaxX=0; // maXx position to detect the end x position of the screen
 int MaxY=0; // maxYposition to detect the end y position of the screen
 double gr;
 gr = 0.01;
 
 int score = 0;
 int boost = 8;
 char *ship = "A";

 char land[] = "_____/---/________|XX|___|~~~~~~~~|_________/";

while(GameOver != TRUE)
{
double acceleration;


*movX +=gr; 
gr+=0.01;;
getmaxyx(stdscr, MaxY,MaxX);     //function for getting the widnow size for stopping the ship to go through the window
clear();
mvprintw(*movX,*movY,"%s", ship);       // prints the ship in an this form;//*
mvprintw(20,1,land);
usleep(ESCDELAY);

refresh();
cbreak();
int input;
input = getch();




if (input == KEY_UP)
{
     // if the up arrow is pressed, the ship accelerates up
     gr-=0.01;
     X-=gr;
     acceleration+=0.02;
     X-=acceleration;
}

if(input == KEY_RIGHT)
{
    Y  += 0.5;  // if the right arrow is pressed, the ship moves right
}
if (input == KEY_LEFT)
{
    Y -= 0.5;  // if the left arrow is pressed, the ship moves left
}
if(input == 'p')
{
    GameOver = TRUE; // if p is pressed or A is out of range,GAMEOVER;
}
if(input == KEY_UP && input == KEY_RIGHT)
{
  

}
timeout(100);
refresh();
}
endwin();
}