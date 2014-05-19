//NAMEOFFILE
#include <iostream>
using namespace std;
int x,y;

int main()
{
  x=0;
  y=4;
  cout<<"x="<<x<<", y="<<y<<endl;
  x=y;
  cout<<"x="<<x<<", y="<<y<<endl;
  x=y=18;
  cout<<"x="<<x<<", y="<<y<<endl;
}
