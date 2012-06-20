/* Slot Machine Program by Joe Tchamitchian, edited by Joseph Dykstra*/
#include <iostream>  //cout, cin
#include <iomanip>   //setw
#include <stdlib.h>  //srand
#include <time.h>    //time for srand
using namespace std;
int main()
{
int x,a, b, c, token=4;
srand(time(0));
cout<<"\t\t +------------------------------+ \n"
    <<"\t\t | Welcome to the Slot Machine. | \n"
    <<"\t\t |        Enter to Play.        | \n"
    <<"\t\t +------------------------------+ \n";
cin.get();
while(token>=1)
	{
	cout<<"You have "<<token<<" token";
	if (token!=1)	{cout<<"s";}
	cout<<".\n\n"<<"Enter to Pull\n\n";
	cin.get();
  a = 1+rand() %10;
  b = 1+rand() %10;
  c = 1+rand() %10;
	cout<<setw(22)<<a<<setw(12)<<b<<setw(12)<<c<<"\n\n";
  if(a==b==c)
    {
    token+=4;
    cout<<"You win!\n\n";
		}
  if(a==b || b==c || a==c)
		{
    token+=1;
		cout<<"You got two of three.\n\n";
		}
  else
		{
    token-=1;
		cout<<"You lose.\n\n";
		}
  }
  cout<<"No more tokens";
  return token;
}
