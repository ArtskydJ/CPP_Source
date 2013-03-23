/* Exercise 7.27
 * 0.031S exec time, or 0.016S exec time; when not printing every board.
 * 2.605S exec time when printing every board.
 * Programmed by Joseph Dykstra, finished 05/11/2012.
 */
#include <iostream>
using namespace std;
void clearcolumn(int),clearboard(),printboard();
int valid(int,int), temp=0, board[8][8], mb(int);
int main()
  {
  clearboard();
  int cl=0; //column
  int rw=0; //row
  while (cl<8) //'for' loops seem to cause trouble here...
    {
    rw=0;
    while (rw<8) //...and here
      {
      if (valid(rw,cl)==0) //if valid
        {
        if (board[rw][cl]==0) //if board is clear here
          {
          board[rw][cl]=1; //set queen here
          rw=10; //exit row loop
          cl++; //go to next column
          temp=0; //dont execute temp
          cout<<endl<<"Column "<<cl<<" completed:"<<endl; //disable this for faster exection
          }
        else
          {
          board[rw][cl]=-1; //set as a position a queen can not be placed
          temp=1; //execute temp
          cout << endl << "Skipping square" << endl; //disable this for faster exection
          }
        }
      else         //if not valid
        {temp=1;}  //execute temp
      if (temp==1) //temp
        {
        rw++; //go to next row
        if (rw==8) //if at the end
          {
          cout<<endl<<"Can't go into column "<<cl+1<<". Backing up:"<<endl<<"|"; //disable this for faster exection
          clearcolumn(cl); //clear current column
          cl-=1; //go to previous column
          rw=10; //exit row loop
          }
        }
      }//end of row loop
    printboard(); //disable this for faster exection
    }//end of column loop, end of calculation, finished
  printboard(); //print the board, do not disable this
  }

int valid(int ro,int co) //checks if the square is valid
  {
  //the reason the returnme variable adds a makeboolean (mb)...
  //...number is in case board[?][?] is a negative integer.
  int returnme=0;
  for (int chk=0; chk<co; chk++) //left
    {
    returnme+=mb(board[ro][chk]);
    }
  for (int chk=1; (chk<=ro) && (chk<=co); chk++) //up&left diagonal
    {
    returnme+=mb(board[ro-chk][co-chk]);
    }
  for (int chk=1; ((ro+chk)<=7) && ((co-chk)>=0); chk++) //down&left diagonal
    {
    returnme+=mb(board[ro+chk][co-chk]);
    }

  //cout << returnme; //debugging code
  return  returnme;
  }

int mb(int jkl) //takes the int input, and outputs a boolean integer. (Not as a bool type, but an int type)
  {
  if (jkl<0) {jkl=0;}
  if (jkl>1) {jkl=1;}
  return jkl;
  }

void clearboard()
  {
  for (int q=0; q<8; q++)
    {
    for (int w=0; w<8; w++)
      {
      board[w][q]=0;
      }
    }
  }

void clearcolumn(int clrcol)
  {
  for (int row=0; row<8; row++)
    {
    board[row][clrcol]=0;
    }
  }

void printboard()
  {
  int blk=0;
  cout << "RC1_2_3_4_5_6_7_8C" << endl << "1|";
  for (int col=0; col<8; col++)
    {
    for (int row=0; row<8; row++)
      {
      if (board[col][row]==1) //IF QUEEN
        {cout<<"*|";}   //'*' either color if queen
      else                 //IF NO QUEEN
        {
        if (blk%2==1)
          {cout<<" |";} //' ' if white and no queen
        else
          {cout<<"=|";} //'=' if black and no queen
        }
      blk++;
      }
    blk++;
    if (col<7) {cout << endl << col+2 << "|";}
    else {cout << endl << "R" << endl;}
    }
  }

/* Debugging Code
//Folowing put at beginning
#include <stdlib.h> //srand, rand
#include <time.h>   //randomization
int main() //replaces current main() function
{
srand(time(0));
while (1)
  {
  int cl=0;
  int rw=0;
  for (int a=0; a<8; a++) //randomly generated queens
    {
    for (int s=0; s<8; s++)
      {
      board[a][s]=!mb(rand()%20); //about one in 20 are generated
      }
    }
  pb();
  cout<<"row:"; //user enters potential position for a queen to be...
  cin>>rw;
  rw--;
  cout<<"column:"; //...placed in, and then it checks if it can be placed there.
  cin>>cl;
  cl--;
  cout<<"valid("<<rw<<","<<cl<<")== "<<valid(rw,cl)<<" , zero is clear.\n\n\n";
  }
}
*/
