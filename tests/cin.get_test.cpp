//cin.get_test.cpp
#include <iostream>
#include <windows.h>
using namespace std;
int x,y;

int main()
{
while (1)
  {
  for (x=3;x>=0;x--)
    {
    cout<<x;
    Sleep(1000);
    }
  cout<<endl<<'"';
  cin.get();
  cout<<'"'<<endl;
  }
}
