//getch_test
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
int x,y;

int main()
{
while (1)
  {
  Sleep(1000);
  if (kbhit()!=0)
    {cout<<getch()<<endl;}
  }
}

/*
119  w
97   a
115  s
100  d
*/
