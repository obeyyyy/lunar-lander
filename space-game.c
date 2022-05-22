#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdbool.h>
#include <strings.h>
#include <time.h>
#define DELAY 30000


void fuel(int *fuel, bool GameOver)
{

  if (fuel>0)
    { 
      printw("FUEL: %d\n",*fuel);
    }

      if(*fuel == 0)
         {
             GameOver = TRUE;
         }
}


void score(int *score,int *fuel)
{
 
 printw("SCORE: %d\n", *score);
     if(*fuel<150)
        {
           *score+=5;
        }
     if(*fuel<100)
        {
          *score+=10;
        }
     if(*fuel<50)
        {
         *score+=40;
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


  



int main(int argc, char *argv[])
{

 
 initscr();
 noecho();
 curs_set(FALSE);
 bool GameOver =false; // boolean if whether you won or not
 
 keypad(stdscr, TRUE);  // enables arrows reading for controlls
 double X =0;  // new x position of the ship
 double Y =40;  // new y position of the ship
 int MaxX=0; // maXx position to detect the end x position of the screen
 int MaxY=0; // maxYposition to detect the end y position of the screen
 char *ship="A";
 int Fuel=200;
int Score;
double PadPos; // landpad position
int PadPos_2;

srand(time(0));
double acceleration=0;
double gr=0;
char lanpad[]={"|=|\n"}; // landpad 
char landpad_2[]={"|~|\n"};
char landscape[]={"###########################################################################################################################################################################################################################################################################################################\n"};

PadPos = rand() % 39; // landap position random position generator
PadPos_2 = 75;
double Land=40.000000; // landscape position

while(GameOver != TRUE)
{
    

getmaxyx(stdscr, MaxY,MaxX); //function for getting the widnow size for stopping the ship to go through the window
clear();
fuel(&Fuel,GameOver); // function to display the fuel
positionX_display((int)X, GameOver); // ship's postions fucntion display
positionY_display((int)Y, GameOver);  //
score(&Score,&Fuel); // score display function
mvprintw(X,Y,"%s", ship);      // prints the ship in an this form
mvprintw(39,PadPos,lanpad);     //  prints the 1st landap
mvprintw(39,PadPos_2,landpad_2);     //  prints the 2nd pad
mvprintw(Land,1,landscape);       // prints the landscape





gr= gr + 0.003; // increasing the gravity by the time goes
X+=gr;         // apply the gravity to the ship
acceleration-=0.0001; // decreases the acceleration after boosting





if ((int)Y == PadPos+1 && (int)X ==39 && gr<0.1) // collision logic ( landing )
{

printw("NICE LANDING\nYOUR SCORE IS: %d\n", Score*500);
    
    GameOver = TRUE;
    refresh();
}

if ((int)Y == PadPos_2+1 && (int)X ==39 && gr<0.1) // collision logic ( landing )
{

printw("NICE LANDING\nYOUR SCORE IS: %d\n", Score*30);
    
    GameOver = TRUE;
    refresh();
}



if(X  > Land || Fuel == 0)  // collision logic (crash)
{
    printw("YOU CRASHED, GAME OVER\nYOUR SCORE IS: %d\n", Score);
    
    GameOver = TRUE;
    refresh();
    
}




usleep(ESCDELAY);
cbreak();
int input;
input = getch(); // getting input from the user


if (input == KEY_UP)
{
  
     Fuel--; // decreasing the fuel
     acceleration+=0.0005; // increasign the acc
     X-=acceleration;
     gr-=acceleration/2; // friction with the gravity
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
    GameOver = TRUE; // if p is pressed ,GAMEOVER;(closes the window)
}


timeout(100);
refresh();
}


}
