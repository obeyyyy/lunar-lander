#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#include <time.h>
#define DELAY 30000


void fuel(int *fuel, bool fuel_isempty)
{

  if (fuel>0)
    {
      printw("FUEL: %d\n",*fuel);
    }

  if(fuel == 0)
   {
      bool fuel_isempty = TRUE;
   }

}




void positionX_display(int X, bool GameOver)
    {
      if(GameOver != TRUE)
           {
                printw("X-position: %d\n",X);
           }
    }



void positionY_display(int Y, bool GameOver)
    {
      if(GameOver != TRUE)
           {
                printw("Y-position: %d\n",Y);
           }        
    }



void gravity_display(int gravity, bool GameOver)
    {
      if(GameOver != TRUE)
           {
                printw("gravity: %d\n",gravity);
           }     
    }



void speed_display(int speed, bool GameOver)
    {
      if(GameOver != TRUE)
           {
                printw("speed: %d\n",speed);
           }      
    }




int main(int argc, char *argv[])
{
   
 initscr();
 noecho();
 curs_set(FALSE);
 bool GameOver =false;
 keypad(stdscr, TRUE);  // enables arrows reading for controlls
 double X =0;  // new x position of the ship
 double Y =40;  // new y position of the ship
 int MaxX=0; // maXx position to detect the end x position of the screen
 int MaxY=0; // maxYposition to detect the end y position of the screen
 char *ship="A";
 int Fuel=200;

int PadPos; //landpad position
srand(time(0));

double acceleration=0;
double gr=0; // gravity
char lanpad[]={"|==|\n"};
char landscape[]={"#######################################################################################################################################################################################################\n####################################################################################################"};

PadPos= rand() % 39;
while(GameOver != TRUE)
{
    


getmaxyx(stdscr, MaxY,MaxX); //function for getting the widnow size for stopping the ship to go through the window
clear();
fuel(&Fuel,GameOver);
positionX_display((int)X, GameOver);
positionY_display((int)Y, GameOver);
gravity_display((int)gr, GameOver);
speed_display((int)acceleration, GameOver);


mvprintw(X,Y,"%s", ship);      // prints the ship in an this form
mvprintw(39,PadPos,lanpad);     // prints the ship in an this form
mvprintw(40,1,landscape);       // prints the ship in an this form



gr= gr + 0.003; // increasing the gravity by the time goes
X+=gr;         // apply the gravity to the ship
acceleration-=0.0001;


usleep(ESCDELAY);
refresh();
cbreak();

if((int)Y >= PadPos && (int)X  >= 39)
{
    GameOver = TRUE;
}


int input;
input = getch();
if (input == KEY_UP)
{
     // if the up arrow is pressed, the ship accelerates up
     Fuel--;
     acceleration+=0.0005;
     X-=acceleration;
     gr-=acceleration/2;
}


if(input == KEY_RIGHT)
{
    Y  +=0.5;  // if the right arrow is pressed, the ship moves right
}


if (input == KEY_LEFT)
{
    Y -= 0.5;  // if the left arrow is pressed, the ship moves left
}


if(input == 'p' || Fuel == 0)
{
    GameOver = TRUE; // if p is pressed or A is out of range,GAMEOVER;
}

timeout(100);
refresh();
}
endwin();
}
