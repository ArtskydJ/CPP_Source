#include <iostream>
#include <iomanip>
using namespace std;
int miles=0;
int gallons;
int count=0;
double currentmpg;
double totalmpg=0;

int main()
  {
  count=0;
  totalmpg=0;
  miles=0;
  while (miles != -1)
    {
    cout << "Enter miles driven (-1 to quit): ";
    cin >> miles;
    if (miles != -1)
      {
      cout << "Enter gallons used: "; //endl <<
      cin >> gallons;
      currentmpg = static_cast<double> (miles)/(gallons);
      cout << "MPG this tankful: " << setprecision(8) << currentmpg; //endl <<
      totalmpg = static_cast<double> (((totalmpg*count)+currentmpg)/(count+1));
      cout << endl << "Total MPG: " << setprecision(8) << totalmpg << endl << endl;
      count++;
      }
    }
  return count;
  }
