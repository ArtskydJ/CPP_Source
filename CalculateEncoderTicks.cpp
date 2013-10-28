//Calculate Encoder Ticks
//Joseph Dykstra
//2013-05-09
#define WHEELSIZE 4
#include <iostream>
using namespace std;
float x;
float y;

int main()
  {
  while(1)
    {
    cout<<"Enter inches: "; cin>>x; //SENSE
    y = x*360/(WHEELSIZE*3.14);     //PLAN
    cout<<"Ticks:"<<y<<endl<<endl;  //ACT
    }
  }
