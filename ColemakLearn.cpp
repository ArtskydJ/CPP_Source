//Colemak Learn
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#define maxnum  54
#define homenum 20
using namespace std;

const string read[maxnum]=
  {
  "qqqqq",//0
  "wwwww",
  "fffff",
  "ppppp",
  "ggggg",
  "jjjjj",
  "lllll",
  "uuuuu",
  "yyyyy",
  ";;;;;",

  "zzzzz", //10
  "xxxxx",
  "ccccc",
  "vvvvv",
  "bbbbb",
  "kkkkk",
  "mmmmm",
  ",,,,,",
  ".....",

  "Joseph",//19
  "Lee",
  "Dykstra",
  "empty",
  "an",
  "awesome",
  "goodies",
  "colemak",
  "dvorak",
  "qwertyuiop",
  "qwerty",
  "super",
  "linoleum",
  "poly_vinyl_chloride",
  "pnuemonoultramicroscopicsilicavolcanoconiosis",

  "aaaaa", //34   home row
  "rrrrr",
  "sssss",
  "ttttt",
  "ddddd",
  "hhhhh",
  "nnnnn",
  "eeeee",
  "iiiii",
  "ooooo",
  "'''''",

  "the", //45 home row
  "hot",
  "dots",
  "it's",
  "ratter",
  "and",
  "strider",
  "snares",
  "read"//52
  };

int main ()
  {
  int line;
  string type;
  bool loop;
  bool home;
  bool keepon;
  srand(time(0));
  cout<<"---Learn Colemak---"<<endl<<"Type 'exit' to exit."<<endl<<"Type 'skip' to skip."
  <<endl<<"Choose:"<<endl<<"1-All Chars"<<endl<<"2-Home Row"<<endl;
  type="0";
  while(type!="1" && type!="2" && type!="exit" && type!="skip")
    {
    cin>>type;
    }
  line=atoi(type.c_str());
  home=line-1;
  loop=(type!="exit" && type!="skip");
  while (loop)
    {
    if (home) line=((rand()%homenum)+maxnum-homenum);
    else      line=(rand()%maxnum);
    type="a";
    for (int i=0; (type!=(string)read[line] && type!="exit" && type!="skip"); i++)
      {
      if (i>0) cout<<"Try Again...";
      cout<<endl<<read[line]<<endl;
      cin>>type;
      }
    loop=(type!="exit");
    }
  return 0;
  }
