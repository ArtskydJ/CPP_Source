//Snake.cpp
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <math.h>
#include <conio.h>
using namespace std;
const int b=16,f=255,height=20,width=22;
void intro();
int x,y,z,fx,fy,lx,ly,selection,dir=0,score=0,length,grow,startlength,speedup,delaytime,board[width+1][height+1];
bool foodate=false,dead=false;


int main()
{
intro();
cin>>selection;
if (selection<1) {selection=1;}
if (selection>4) {selection=4;}

if (selection==1)
  {
  grow=2;
  startlength=3;
  speedup=0.975;
  delaytime=300;
  }
else if (selection==2)
  {
  grow=3;
  startlength=3;
  speedup=0.9375;
  delaytime=250;
  }
else if (selection==3)
  {
  grow=4;
  startlength=3;
  speedup=0.9;
  delaytime=200;
  }
else if (selection==4)
  {
  grow=10;
  startlength=10;
  speedup=1;
  delaytime=120;
  }

length=startlength;
x=1;
y=1;
z=1;
fx=startlength;
fy=1;
lx=1;
ly=1;
for (x=0;x<width+1;x++)    //was  for  x=1  to  width
  {
  for (y=0;y<height+1;y++) //was  for  y=1  to  height
    {
    board[x][y]=0;
    }
  }
for  (x=0;x<startlength;x++)
  {
  board[x][0]=x+1;
  }




while (dead==false) //play the game
  {
  z=0;
  while (z=0)
    {
    x=round(rand()%(width-1)+1);
    y=round(rand()%(height-1)+1);
    if (board[x][y]==0) {z=1; board[x][y]=-1;}
    }
  foodate=false;
  dead=false;
  while (foodate==false and dead==false)
    {

    Sleep(delaytime);


    //  <move>
    int n;
    if (kbhit()!=0) {x=getch();}
    if ((n==119) or (n==97) or (n==115) or (n==100)) {dir=n;}
    //119  w  up
    //97   a  left
    //115  s  down
    //100  d  right
    if (dir==97)  { //if  moving  LEFT
      n=board[fx-1][fy];
      if  (fx<2)  {dead=1;}
      if  (n>1)   {dead=1;}
      if  (n<2)   {fx=fx-1;board[fx][fy]=length+1;}
      if  (n==-1) {foodate=1;length=length+grow;}}

    if (dir==119)  { //if  moving  UP
      n=board[fx][fy-1];
      if  (fy<2)  {dead=1;}
      if  (n>1)   {dead=1;}
      if  (n<2)   {fy=fy-1;board[fx][fy]=length+1;}
      if  (n==-1) {foodate=1;length=length+grow;}}

    if (dir==100)  { //if  moving  RIGHT
      n=board[fx+1][fy];
      if (fx+1>width) {dead=1;}
      if (n>1)        {dead=1;}
      if (n<2)        {fx=fx+1;board[fx][fy]=length+1;}
      if (n==-1)      {foodate=1;length=length+grow;}}

    if (dir==115)  { //if  moving  DOWN
      n=board[fx][fy+1];
      if (fy+1>height) {dead=1;}
      if (n>1)         {dead=1;}
      if (n<2)         {fy=fy+1;board[fx][fy]=length+1;}
      if (n==-1)       {foodate=1;length=length+grow;}}

    if (dead==0)
      {
      for  (x=1;x<width;x++)
        {
        for  (y=1;y<height;y++)
          {
          if (board[x][y]=1) {lx=x;ly=y;}
          if (board[x][y]>0) {board[x][y]-=1;}
          }
        }
      }
    //  </move>


    //  <display>
    cout<<endl<<string(((width*2)+4),'+')<<endl<<string(((width*2)+4),'+')<<endl<<"++";
    for (y=0;y<height;y++)
      {
      for (x=0;x<width;x++)
        {
        if (board[x][y]>0)       //SNAKE
          {//rect  x*b-(b-1),  y*b-(b-1),  STEP  b-1,  b-1,  color  rgb(0,255,0)  filled
          cout<<"[]";
          }
        else if (board[x][y]<0)  //FOOD
          {//rect  x*b-(b-1),  y*b-(b-1),  STEP  b-1,  b-1,  color  rgb(255,0,0)  filled
          cout<<"<>";
          }
        else if (board[x][y]==0) //NOTHING
          {
          cout<<"  ";
          }
        else {cout<<"uh-oh";}
        //cout<<board[x][y]<<" ";  //DEBUG
        }
      cout<<"++"<<endl<<"++";
      }
    cout<<string(((width*2)+2),'+')<<endl<<string(((width*2)+4),'+')<<endl<<"  Score: "<<score;
    //  </display>


    }
  if  (dead==false)
    {//snakegrow
    for  (x=0;x<width;x++)
      {
      for  (y=0;y<height;y++)
        {
        if  (board[x][y]>0)  {board[x][y]+=grow;}
        }
      }
    score+=1;
    }
  delaytime*=speedup;
  }
cout<<endl<<"Game Over"<<endl<<"Press any key to Continue";
cin.get();
return dead;
}




void intro()
{
cout<<" /-----\\  " <<"|\\      |        /\\        |   /  |-----" <<endl;
cout<<"(         "  <<"| \\     |       /  \\       |  /   |     " <<endl;
cout<<" \\        " <<"|  \\    |      /    \\      | /    |     " <<endl;
cout<<"  \\--\\    "<<"|   \\   |     /------\\     |(     |-----" <<endl;
cout<<"      \\   " <<"|    \\  |    /        \\    | \\    |     "<<endl;
cout<<"       )  "  <<"|     \\ |   /          \\   |  \\   |     "<<endl;
cout<<"\\-----/   " <<"|      \\|  /            \\  |   \\  |-----"<<endl;
cout<<endl;
cout<<"|\\    /|   /\\   |--\\ |--"<<"    |--\\ \\  / "<<"   --|--  /--\\  /--\\ |-- |-\\ |  |    |--\\"<<endl;
cout<<"| \\  / |  /--\\  |   ||--" <<"    |--<  \\/  " <<"     |   (    ) \\--\\ |-- |-/ |--|    |  |"  <<endl;
cout<<"|  \\/  | /    \\ |--/ |--" <<"    |--/  |    " <<"  \\-|    \\--/  \\--/ |-- |   |  |    |--/."  <<endl;
cout<<endl;
cout<<" \\    /\\    / -|- --|-- |  |    --|--  /--\\  /--\\ -|-   /\\   |  |    | /\n";
cout<<"  \\  /  \\  /   |    |   |--|      |   (    ) \\--\\  |   /--\\  |--|    |< \n";
cout<<"   \\/    \\/   -|-   |   |  |    \\-|    \\--/  \\--/ -|- /    \\ |  |    | \\.\n\n";
cout<<"Choose:" <<endl;
cout<<"1"<<setw(8)<<"Easy"  <<endl;
cout<<"2"<<setw(8)<<"Medium"<<endl;
cout<<"3"<<setw(8)<<"Hard"  <<endl;
cout<<"4"<<setw(8)<<"Death" <<endl;
}
