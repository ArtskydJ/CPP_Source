//NAMEOFFILE
#include <iostream>
using namespace std;
int x,y;
bool b;

int main()
  {
  while(1)
    {
    b=false;
    cin>>y;
    x+=y;
    if (x > 32767) {x = 32767; b=true;}
    if (x <-32767) {x =-32767; b=true;}
    if (y > 32767) {y = 32767; b=true;}
    if (y <-32767) {y =-32767; b=true;}
    if (b)  cout<<"\t"<<x<<"Error\n";
    else    cout<<"\t"<<x<<"\n";
    }
  }
