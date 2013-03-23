//Snake.cpp
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define LF 97
#define UP 119
#define RT 100
#define DN 115

using namespace std;
const int b=16,f=255,height=15,width=15;
void intro();
int x,y,z,fx,fy,lx,ly,selection,dir=100,score=0,length,grow,startlength,delaytime,board[width+1][height+1];
float speedup;
bool foodate=false,dead=false;

int main()
{
intro();
srand(time(0));
cin>>selection;
if (selection<1) {selection=1;}
if (selection>5) {selection=5;}
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
  delaytime=150;
  }
else if (selection==5)
  {
  cout<<"Start Length   = ";
  cin>>startlength;
  cout<<"Grow Length    = ";
  cin>>grow;
  cout<<"Speed up       = ";
  cin>>speedup;
  cout<<"Original Delay = ";
  cin>>delaytime;
  }
length=startlength;
fx=startlength-1;
fy=lx=ly=0;
for (x=0;x<=width;x++)
  {
  for (y=0;y<=height;y++)
    {
    board[x][y]=0;
    }
  }
for  (x=0;x<startlength;x++)
  {
  board[x][0]=x+1;
  }

while (dead==false)
  {
  z=0;
  while (z==0)
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
    int n;
    if (kbhit()!=0) {n=getch();}
    if ((n==LF) or (n==UP) or (n==RT) or (n==DN))
      {
      if((n==LF and dir!=RT)
      or (n==RT and dir!=LF)
      or (n==DN and dir!=UP)
      or (n==UP and dir!=DN))
        {dir=n;}
      }
    int tempx=fx;
    int tempy=fy;
    if (dir==LF) tempx-=1;
    if (dir==UP) tempy-=1;
    if (dir==RT) tempx+=1;
    if (dir==DN) tempy+=1;
    n=board[tempx][tempy];
    if  (tempx<0 || tempx>=width
      || tempy<0 || tempy>=height
      || n>1)
        dead=true;
    if  (n<=1)  {fx=tempx; fy=tempy; board[fx][fy]=length+1;}
    if  (n==-1) {foodate=1;length=length+grow;}
    if (dead==false) //GROW
      {
      for  (x=0;x<width;x++)
        {
        for  (y=0;y<height;y++)
          {
          if (board[x][y]==1) {lx=x;ly=y;}
          if (board[x][y]>=1) {board[x][y]--;}
          //cout<<".";
          }
        }
      }
    //cout<<" fx="<<fx<<", fy="<<fy<<", lx="<<lx<<", ly="<<ly; //DEBUG
    cout<<endl<<string((width+2),char(176))<<endl<<char(176);
    for (y=0;y<height;y++)
      {
      for (x=0;x<width;x++)
        {
        if (board[x][y]>0)
          {
          cout<<char(219);
          }
        else if (board[x][y]<0)
          {
          cout<<char(3);
          }
        else
          {
          cout<<" ";
          }
        //cout<<board[x][y]<<" "; //DEBUG
        }
      cout<<char(176)<<endl<<char(176);
      }
    cout<<string((width+1),char(176))<<endl;
    cout<<"  Score: "<<score;
    }
  if  (dead==false) //snakegrow
    {
    for (y=0;y<height;y++)
      {
      for (x=0;x<width;x++)
        {
        if  (board[x][y]>=1)  {board[x][y]+=grow;}
        }
      }
    score+=1;
    }
  delaytime*=speedup;
  }
cout<<endl<<"Game Over";
Sleep(2000);cout<<"4"<<setw(8)<<"Death" <<endl;
return 0;
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
cout<<"Controls: WASD"<<endl;
cout<<"Choose:" <<endl;
cout<<"1"<<setw(8)<<"Easy"  <<endl;
cout<<"2"<<setw(8)<<"Medium"<<endl;
cout<<"3"<<setw(8)<<"Hard"  <<endl;
cout<<"4"<<setw(8)<<"Death" <<endl;
cout<<"5"<<setw(8)<<"Custom"<<endl;
}
