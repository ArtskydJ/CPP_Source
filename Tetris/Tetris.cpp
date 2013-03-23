//Tetris
//Joseph Dykstra
//Finished 01-04-2013

//              PREPROCESSOR
#include <iostream>
#include <iostream>
#include <ctime>

//#include <string>
#include <allegro.h>
//#include "allegro5/allegro.h"
#define ALLEGRO_STATICLINK

//#include "+Button+-.c"

//Dimensions / Graphics
#define blksz   4
#define width   10
#define height  25
#define TX      35
#define SX      94
#define SY      61
#define msgX    0
#define msgY    56
#define defaultmode     0
#define previewPieces   6
//Timing (all *10)
#define waitGravity     5
#define waitDisp        18
#define waitSlowMove    3
#define waitFastMove    0
#define waitRotateAgain 3
#define waitHardDrop    3
#define waitLock        2
#define fastRepeat      5
//Buttons

#define BTNLEFT    ALLEGRO_KEY_LEFT
#define BTNRIGHT   ALLEGRO_KEY_RIGHT
#define BTNCENTER  ALLEGRO_KEY_UP
#define BTNEXIT    ALLEGRO_KEY_DOWN

#define BtnMoveL  BTNCENTER
#define BtnMoveR  BTNEXIT
#define BtnRotate BTNRIGHT
#define BtnDrop   BTNLEFT

#define LCD_LINE1 0
#define LCD_LINE2 0
#define LCD_LINE3 0
#define LCD_LINE4 0
#define LCD_LINE5 0
#define LCD_LINE6 0
#define LCD_LINE7 0
#define LCD_LINE8 0

//Move()
#define dwn 0
#define lft 1
#define rht 2
//#define sty 3
//Drop
#define dropHard  1 //Normal
#define dropSoft  2 //Normal
#define dropWHard 3 //Wait
//Tetriminos
#define Itet 0
#define Jtet 1
#define Ltet 2
#define Otet 3
#define Stet 4
#define Ttet 5
#define Ztet 6
#define prob 7


//                 GLOBAL CONSTANTS
const bool allowDbg[5]={0,0,0,0,0};
const char tet[28][8]=
  {
// I
  {0,1,2,3,
   2,2,2,2},
  {1,1,1,1,
   0,1,2,3},
  {0,1,2,3,
   1,1,1,1},
  {2,2,2,2,
   0,1,2,3},
// J
  {0,1,2,2,
   1,1,1,2},
  {1,1,1,0,
   0,1,2,2},
  {0,1,2,0,
   1,1,1,0},
  {1,1,1,2,
   0,1,2,0},
// L
  {0,0,1,2,
   2,1,1,1},
  {0,1,1,1,
   0,0,1,2},
  {0,1,2,2,
   1,1,1,0},
  {1,1,1,2,
   0,1,2,2},
// O
  {1,1,2,2,
   0,1,0,1},
  {1,1,2,2,
   0,1,0,1},
  {1,1,2,2,
   0,1,0,1},
  {1,1,2,2,
   0,1,0,1},
// S
  {2,1,1,0,
   1,1,2,2},
  {0,0,1,1,
   0,1,1,2},
  {2,1,1,0,
   0,0,1,1},
  {1,1,2,2,
   0,1,1,2},
//T
  {0,1,1,2,
   1,1,2,1},
  {1,1,0,1,
   0,1,1,2},
  {0,1,1,2,
   1,1,0,1},
  {1,1,2,1,
   0,1,1,2},
// Z
  {0,1,1,2,
   1,1,2,2},
  {0,0,1,1,
   2,1,1,0},
  {0,1,1,2,
   0,0,1,1},
  {1,1,2,2,
   2,1,1,0}
};


//                 GLOBAL VARIABLES
bool alive         =0;
bool prevQuadClear =0;
bool highMade      =0;
bool floorKickUsed =0;

//START  ARRAYS
bool area[width][height+2]; //Two hidden rows
char chnc[8];
int nextPiece[previewPieces];
// END   ARRAYS

int showDisp      =0;
int viewDbg       =0;
int gametype      =0;
int gamespeed     =0;
int delaytime     =0;
int lockDelay     =0;
int prevRht       =0;
int prevLft       =0;
int prevDrp       =0;
int prevRot       =0;
int currentPiece  =0;
int currentRotate =0;
int tetLR         =0;
int tetUD         =0;
int drop          =0;
int prevWaited    =0;
float speedup     =0;
long score        =0;
//these were strings
int msg        =0;
int disp       =0;
int accesshigh =0;


//                 SUBROUTINES

int readHigh(int INaccess)
{
return 0;
}

int writeHigh(int INaccess, int INscore)
{
return 0;
}


int writeHighName(int INaccess, int INscore)
  {
  return 0;
  }

bool ButtonPressed(int INbutton)
  {
  return false;
  }

void ClearScreen()
  {
  //std::cout<<"cls\n";
  }

void TextOutput(int x, int y, int n, int options)
  {
  //std::cout<<"text "<<n<<"\n";
  }

void Wait(int waittime)
  {
  //std::cout<<"wait/n";
  }

void LineOut(int INx, int INy, int INlen, int INwid, int INoptions)
  {
  //0, width*blksz+1, 99, width*blksz+1, 0
  }

void RectOut(int INx, int INy, int INwidth, int INheight, int INoptions)
  {
  //std::cout<<"RectOut/n";
  }

void CircleOut(int INx, int INy, int INwidth, int INoptions)
  {
  //std::cout<<"CircleOut\n";
  }

int senseButton(int val, bool lr_ud, int add, int high, bool cut)
	{
	int lu,rd;
	if (lr_ud)
		{
		lu=BTNLEFT;
		rd=BTNRIGHT;
		}
	else
		{
		lu=BTNCENTER;
		rd=BTNEXIT;
		}
	if (ButtonPressed(lu)) //change to on press
		{
		val-=add;
		}
	if (ButtonPressed(rd)) //change to on press
		{
		val+=add;
		}
	if (cut)
		{
		if (val<0)    {val=0;}
		if (val>high) {val=high;}
		}
	else
		{
		if (val<0)  {val=high;}
		if (val>high)  {val=0;}
		}
	return val;
	}



void selectGame(bool INfastmode)
  {
  prevQuadClear=false;
  prevRht=0;
  prevLft=0;
  score=0;
  //disp="";
  //accesshigh="Tet";
  if (INfastmode) //debugging
    {
    gamespeed=0;
    gametype=2;
    }
  else
    {
    while (ButtonPressed(BTNRIGHT)==false)
      {
      gamespeed=senseButton(gamespeed,false,1,2,false);
      ClearScreen();
      TextOutput(TX,LCD_LINE1,0,0);
      RectOut(0,40-(gamespeed*8),49,8,0);
      Wait(50);
      }
    //TextOutput(TX,LCD_LINE1,"TETRIS",  0);
    while (ButtonPressed(BTNRIGHT)) {}
    while (ButtonPressed(BTNRIGHT)==false)
      {
      gametype=senseButton(gametype,false,1,4,false);
      ClearScreen();
      TextOutput(TX,LCD_LINE1,0,0);
      RectOut(0,40-(gametype*8),49,8,0);
      Wait(50);
      }
    }
  //TextOutput(TX,LCD_LINE1,"TETRIS",  0);
  while (ButtonPressed(BTNRIGHT)) {}
  //
  if      (gamespeed==0)
    {
    //accesshigh=StrCat(accesshigh,"Slow");
    speedup=0.975;
    delaytime=800;
    }
  else if (gamespeed==1)
    {
    //accesshigh=StrCat(accesshigh,"Med");
    speedup=0.9375;
    delaytime=600;
    }
  else if (gamespeed==2)
    {
    //accesshigh=StrCat(accesshigh,"Fast");
    speedup=0.9;
    delaytime=400;
    }
  if      (gametype==0)
    {
    //accesshigh=StrCat(accesshigh,"Give.dat");
    chnc[Itet]=2;
    chnc[Jtet]=1;
    chnc[Ltet]=1;
    chnc[Otet]=2;
    chnc[Stet]=0;
    chnc[Ttet]=1;
    chnc[Ztet]=0;
    chnc[prob]=7;
    }
  else if (gametype==1)
    {
    //accesshigh=StrCat(accesshigh,"Simp.dat");
    chnc[Itet]=3;
    chnc[Jtet]=1;
    chnc[Ltet]=1;
    chnc[Otet]=3;
    chnc[Stet]=1;
    chnc[Ttet]=2;
    chnc[Ztet]=1;
    chnc[prob]=12;
    }
  else if (gametype==2)
    {
    //accesshigh=StrCat(accesshigh,"Norm.dat");
    chnc[Itet]=1;
    chnc[Jtet]=1;
    chnc[Ltet]=1;
    chnc[Otet]=1;
    chnc[Stet]=1;
    chnc[Ttet]=1;
    chnc[Ztet]=1;
    chnc[prob]=7;
    }
  else if (gametype==3)
    {
    //accesshigh=StrCat(accesshigh,"Hard.dat");
    chnc[Itet]=2;
    chnc[Jtet]=3;
    chnc[Ltet]=3;
    chnc[Otet]=2;
    chnc[Stet]=4;
    chnc[Ttet]=3;
    chnc[Ztet]=4;
    chnc[prob]=21;
    }
  else if (gametype==4)
    {
    //accesshigh=StrCat(accesshigh,"Death.dat");
    chnc[Itet]=1;
    chnc[Jtet]=3;
    chnc[Ltet]=3;
    chnc[Otet]=2;
    chnc[Stet]=4;
    chnc[Ttet]=2;
    chnc[Ztet]=4;
    chnc[prob]=19;
    }
  else if (gametype==5) //DEBUG ONLY
    {
    //accesshigh=StrCat(accesshigh,"Debug.dat");
    chnc[Itet]=0;
    chnc[Jtet]=1;
    chnc[Ltet]=0;
    chnc[Otet]=2;
    chnc[Stet]=0;
    chnc[Ttet]=0;
    chnc[Ztet]=1;
    chnc[prob]=4;
    }
  ClearScreen();
  }

//  ______   ______   ______   ______   ______   ______   ______   ______
//  |__  _|  |__  _|  |__  _|  |__  _|  |__  _|  |__  _|  |__  _|  |__  _|
//  _  ||    _  ||    _  ||    _  ||    _  ||    _  ||    _  ||    _  ||
//  \\_//    \\_//    \\_//    \\_//    \\_//    \\_//    \\_//    \\_//
//   \_/      \_/      \_/      \_/      \_/      \_/      \_/      \_/

bool move(int INdir, int INud)
  {
  int canMove=0;
  int addLR  =0;
  int addUD  =0;
  int tempLR =0;
  int tempUD =0;
  if      (INdir==dwn) addUD=-1;
  else if (INdir==lft) addLR= 1;
  else if (INdir==rht) addLR=-1;
  for (int i=0; i<4; i++)
    {
    tempLR=tet[currentPiece+currentRotate][i  ]+tetLR+addLR;
    tempUD=tet[currentPiece+currentRotate][i+4]+INud +addUD;
    if ((tempLR>=0)&&(tempLR<width)&&(tempUD>=0)) //&&(tempUD<height)
      {canMove+=(area[tempLR][tempUD]);}
    else canMove++;
    }
  //NumOut(0,16,canMove,0);
  //Wait(500);
  return (canMove==0); //canMove in:  0123  0123
  }                    //canMove out: 1000  TFFF


bool rotate()
  {
  int canRotate=1, addRot=0, tempLR, tempUD, addUD, addLR;
  if (currentRotate>=3) addRot=-3;
  else                  addRot=1;
  for (int i=0; (i<3 && canRotate>0); i++)
    {
    if (i==0) addUD= 0;  //1st  Level
    if (i==1) addUD=-1;  //2nd  D
    if (i==2) addUD= 1;  //3rd  U
    if (i==3) addUD=-2*(currentPiece*4==Itet);  //4th D if I tetromino
    if (i==4) addUD= 2*(currentPiece*4==Itet);  //5th U if I tetromino
    for (int j=0; (j<5 && canRotate>0); j++)
      {
      if (j==0) addLR= 0;  //1st  Center
      if (j==1) addLR=-1;  //2nd  L
      if (j==2) addLR= 1;  //3rd  R
      if (j==3) addLR=-2*(currentPiece*4==Itet);  //4th L if I tetromino
      if (j==4) addLR= 2*(currentPiece*4==Itet);  //5th R if I tetromino
      canRotate=0;
      for (int k=0; k<4; k++)
        {
        tempLR=tet[currentPiece+currentRotate+addRot][k  ]+tetLR+addLR;
        tempUD=tet[currentPiece+currentRotate+addRot][k+4]+tetUD+addUD;
        if ((tempLR>=0)&&(tempUD>=0)&&(tempLR<width)&&(tempUD<height+2)&&(tetUD>0))
          {canRotate+=(area[tempLR][tempUD]);}
        else {canRotate++;}
        }
      }
    }
  if (canRotate==0)
    {
    //if (!(addUD>0 && floorKickUsed==true))
      //{
      tetLR+=addLR;
      tetUD+=addUD;
      //if (addUD>0) floorKickUsed=true;
      //}
    }
  return (canRotate==0);
  }


void displayTetromino(int INtet,int INrot, int INlr, int INud, int INdrawMode)
  {
  int tempLR,tempUD;
  for (int i=0; i<4; i++)
    {
    tempLR=INlr+(tet[INtet+INrot][i  ])*blksz;
    tempUD=INud+(tet[INtet+INrot][i+4])*blksz;
    if      (INdrawMode==0) RectOut(tempUD,tempLR,blksz,blksz,32);
    else if (INdrawMode==1) RectOut(tempUD,tempLR,blksz,blksz,0);
    else if (INdrawMode==2) CircleOut(tempUD+blksz/2,tempLR+blksz/2,blksz/2-1,32);
    }
  }

/* BEGIN  _ _        __
 *         |     /  /  \
 *         |    /   |  |
 *        _|_  /    \__/
 *       ================
 */

bool inputOutput(bool INallowInput, bool INallowOutput, bool INallowDraw, int INwaited)
  {
  bool temppiecemoving=true; //return this
  int refresh=0; //refresh the screen: 0=no, 1=piece, 2=score+piece, 3=everything

//INPUT
//INPUT
  if (INallowInput)
    {
    if (ButtonPressed(BtnDrop))
      {
      lockDelay=0;
      if (prevDrp<waitHardDrop)
        {drop=dropWHard;}  //Fast = Hard Drop
      else
        {drop=dropSoft;} //Hold = Soft Drop
      prevDrp++;
      }
    else
      {
      prevDrp=0;
      if (drop==dropWHard) {drop=dropHard; lockDelay=waitLock;}
      else                 {drop=0;}
      }
    if (ButtonPressed(BtnRotate))
      {
      if (prevRot==0)
        {
        if (rotate())
          {
          lockDelay=0;
          refresh=2;
          currentRotate++;
          if (currentRotate>=4) currentRotate=0;
          }
        }
      prevRot++;
      if (prevRot>waitRotateAgain) prevRot=0;
      }
    else
      {
      prevRot=0;
      }
    if (ButtonPressed(BtnMoveL))
      {
      prevLft++;
      if ((prevLft>=waitSlowMove || prevLft<0) && move(lft,tetUD))
        {
        lockDelay=0;
        if (prevLft<0) prevLft=0;
        else prevLft=waitSlowMove-waitFastMove;
        tetLR++;
        refresh=2;
        }
      }
    else
      {
      prevLft=-5;
      }
    if (ButtonPressed(BtnMoveR))
      {
      prevRht++;
      if ((prevRht>=waitSlowMove || prevRht<0) && move(rht,tetUD))
        {
        lockDelay=0;
        if (prevRht<0) prevRht=0;
        else prevRht=waitSlowMove-waitFastMove;
        tetLR--;
        refresh=2;
        }
      }
    else
      {
      prevRht=-5;
      }
    }

//OUTPUT
//OUTPUT
  if (INallowOutput) //Gravity and Drop
    {
    if (drop==dropHard)                                                   //HARD DROP
      {
      bool tempLoop=true;
      while (tempLoop)
        {
        if (move(dwn,tetUD))
          {
          tetUD--;
          score+=2;
          }
        else
          {
          tempLoop=false;
          lockDelay++;
          if (lockDelay>=waitLock) temppiecemoving=false;
          }
        }
      refresh=3;
      drop=0;
      }
    if ((INwaited%waitGravity<=prevWaited%waitGravity) || drop==dropSoft) //SOFT DROP or GRAVITY
      {
      if (drop==dropSoft)
        {
        score++;
        }
      if (refresh==0) refresh=1;
      if (move(dwn,tetUD)) {tetUD--;}
      else {lockDelay++;}
      if (lockDelay>=waitLock) {temppiecemoving=false; lockDelay=0;}
      drop=0;
      }
    prevWaited=INwaited;
    if (score>readHigh(accesshigh))
      {
      writeHigh(accesshigh,score);
      highMade=true;
      }
    }

//DRAW
//DRAW
  if (INallowDraw)                      //refresh the screen:
    {                                   //0=nothing   //1=piece   //2=area   //3=everything
    if      (refresh==1) RectOut(tetUD*blksz,tetLR*blksz,blksz*5,blksz*4,36); //Fill+Invert
    else if (refresh==2) RectOut(0,0,height*blksz,width*blksz,36); //Fill+Invert
    else if (refresh==3) ClearScreen();
    int tempUD=tetUD;
    bool tempLoop=1;
    //Ghost Piece
    while (tempLoop)
      {
      if (move(dwn,tempUD)) {tempUD--;}
      else
        {
        //tetUD++;
        tempLoop=false;
        displayTetromino(currentPiece,currentRotate,tetLR*blksz,tempUD*blksz,2);
        }
      }
    //AREA
    LineOut(0, width*blksz+1,99,width*blksz+1,0);
    int i;
    int j;
    for (i=0; i<height; i++)
      {
      for (j=0; j<width; j++)
        {
        if (area[j][i]) RectOut(i*blksz,j*blksz,blksz,blksz,32); //replace 32 W/ area[j][i]*28+4
        }
      }
    //NEXT PIECES / MESSAGE

    for (i=0; i<previewPieces; i++)
      {              //    tet      rot       lr           ud                                  draw
      displayTetromino(nextPiece[i], 0, 63-4*blksz, 78-(4*blksz*i)+(nextPiece[i]==Otet*4)*blksz, 1);
      }
    if (showDisp>0&&disp==0)
      {
      TextOutput(msgX,msgY,0,0);
      showDisp=0;
      }
    if (disp!=0)
      {
      TextOutput(msgX,msgY,disp,0);
      showDisp++;
      if (showDisp==0) refresh=2;
      if (showDisp>waitDisp) disp=0;
      }
    //CURRENT TETROMINO / SCORE
    LineOut(92,width*blksz+1,92,63,0);
    displayTetromino(currentPiece,currentRotate,tetLR*blksz,tetUD*blksz,1);
    //RotatedNumbersOut(SX,SY,score);
    }

  return temppiecemoving;
  }


//  END   _ _        __
//         |     /  /  \
//         |    /   |  |
//        _|_  /    \__/
//       ================


void initArrays()
  {
  for (int i=0; i<height; i++)
    {
    for (int j=0; j<width; j++)
      {
      area[j][i]=0;
      }
    }
  for (int i=0; i<3; i++)
    {
    int pieceToCreate=prob;
    int rndm=(rand())%(chnc[prob]);
    int add=0;
    for (int j=0; (j<=Ztet)&&(pieceToCreate==prob); j++)
      {
      add+=chnc[j];
      if (add>rndm) pieceToCreate=j*4;
      }
    if (pieceToCreate==prob)
      {
      ClearScreen();
      TextOutput(0,24,add,0);
      TextOutput(0,16,rndm,0);
      TextOutput(0,00,0,0);
      Wait(1000);
      }
    nextPiece[i]=pieceToCreate;
    }
  showDisp      =0;
  viewDbg       =0;
  gametype      =0;
  gamespeed     =0;
  delaytime     =0;
  lockDelay     =0;
  prevRht       =0;
  prevLft       =0;
  prevDrp       =0;
  prevRot       =0;
  currentPiece  =0;
  currentRotate =0;
  tetLR         =0;
  tetUD         =0;
  drop          =0;
  prevWaited    =0;
  speedup       =0;
  score        =0;
  msg        =0;
  disp       =0;
  accesshigh =0;
}


void resetVars()
  {
  lockDelay      = 0;
  prevRht        = 0;
  prevLft        = 0;
  prevDrp        = 0;
  prevRot        = 0;
  currentRotate  = 0;
  prevWaited     = 0;
  currentRotate  = 0;
  drop           = 0;
  lockDelay      = 0;
  floorKickUsed  = 0;
  tetLR=width/2-2;
  tetUD=height;
  }


void pieceCreate()
  {
  int pieceToCreate=prob;
  int rndm=(rand())%(chnc[prob]);
  int add=0;
  for (int j=0; (j<=Ztet)&&(pieceToCreate==prob); j++)
    {
    add+=chnc[j];
    if (add>rndm) pieceToCreate=j*4;
    }
  if (pieceToCreate==prob)
    {
    ClearScreen();
    TextOutput(0,24,add ,0);
    TextOutput(0,16,rndm,0);
    TextOutput(0,00,0,0);
    Wait(1000);
    }
  currentPiece=nextPiece[0];
  for (int i=1; i<previewPieces; i++)
    {
    //PlayTone(1000,500);Wait(500);
    nextPiece[i-1]=nextPiece[i];
    }
  nextPiece[previewPieces-1]=pieceToCreate;
  }


void pieceSetInto()
  {
  int tempLR,tempUD;
  for (int i=0; i<4; i++)
    {
    tempLR=tet[currentPiece+currentRotate][i  ]+tetLR;
    tempUD=tet[currentPiece+currentRotate][i+4]+tetUD;
    area[tempLR][tempUD]=1;
    }
  }


int clearFullRows()
  {
  int blocksInRow=0;
  int numOfFilledLines=0;
  int i,j,k;
  for (i=0; i<height+2; i++)           //Check All Rows
    {
    blocksInRow=0;
    for (j=0; j<width; j++)            //Add up blocks in row
      {
      blocksInRow+=(area[j][i]);
      }
    if (blocksInRow==width&&i<height)  //If the row is full)
      {
      for (k=i; k<height; k++)         //Move higher rows down
        {
        for (j=0; j<width; j++)
          {
          //int temp=area[j][k];
          //SendResponseNumber(9,temp);
          area[j][k]=area[j][k+1];
          }
        }
      i--; //redo row if it gets destroyed
      numOfFilledLines++;
      }
    else if (blocksInRow>0&&i>=height)
      {
      alive=false;
      }
    }

  //add to score
  if      (numOfFilledLines==1)    {score+=100; prevQuadClear=false; disp=1;}
  else if (numOfFilledLines==2)    {score+=300; prevQuadClear=false; disp=2;}
  else if (numOfFilledLines==3)    {score+=500; prevQuadClear=false; disp=3;}
  else if (numOfFilledLines==4)
  {if (prevQuadClear) {score+=400;} score+=800; prevQuadClear=true;  disp=4;}
  return numOfFilledLines;
  }


bool gameEnd()
  {
  disp=888;
  inputOutput(0,0,1,0);
  bool plyagn=false;
  Wait(2500);
  ClearScreen();
  if (highMade) writeHighName(accesshigh,score);
  ClearScreen();
  /*TextOutput(TX,LCD_LINE1,"TETRIS",  0);
  TextOutput(0,LCD_LINE4,StrCat("S:",NumToStr(score)),0);
  TextOutput(0,LCD_LINE5,StrCat("HS:",NumToStr( readHigh(accesshigh) )),0);
  msg=readHighName(accesshigh);
  TextOutput(0,LCD_LINE6,StrCat("N:",msg),0);
  TextOutput(5,LCD_LINE8,"Yes  Again?  No",0);
  until (ButtonPressed(BTNLEFT)==false
     && ButtonPressed(BTNRIGHT)==false) {}
  until (ButtonPressed(BTNLEFT)==true
     || ButtonPressed(BTNRIGHT)==true)  {}
  plyagn=ButtonPressed(BTNLEFT)==true;
  until (ButtonPressed(BTNLEFT)==false
     && ButtonPressed(BTNRIGHT)==false) {}*/
  return plyagn;
  }

// BEGIN  _    __   __          __
//       | \  |    |  )  |  |  /  \
//       | |  |--  |-<   |  |  |  __
//       |_/  |__  |__)  \__/  \__/
//      ============================
/*
void debugStream(int INint)
  {
  bool insideLoop=0;
  for (int i=0;i<5&&!insideLoop;i++) //check if any debugs are allowed
    {
    insideLoop+=allowDbg[i];
    }
  if (insideLoop)                   //if any are...
    {
    insideLoop=true;
    while (insideLoop)              //go to the next allowed one.
      {
      if (allowDbg[viewDbg]) insideLoop=false;
      if (insideLoop==true)  viewDbg++;
      if (viewDbg>=5)        viewDbg=0;
      }
    string str1="";
    string str2="";
    string str3="";
    string str4="";
    string str5="";
    string msg1="";
    string msg2="";
    string msg3="";
    string msg4="";
    string msg5="";
    string result;
    if      (viewDbg==0)
      {
      str1=disp;
      str2=accesshigh;
      str3=NumToStr(speedup);
      str4=NumToStr(INint); //  i/wait
      msg1="  dsp ";
      msg2="  ahi ";
      msg3="  sdp ";
      msg4="    i ";
      }
    else if (viewDbg==1)
      {
      str1=NumToStr(score);
      str2=NumToStr(gametype);
      str3=NumToStr(gamespeed);
      str4=NumToStr(delaytime);
      str5=NumToStr(lockDelay);
      msg1="  sc ";
      msg2="  gt ";
      msg3="  gs ";
      msg4="  dt ";
      msg4="  lD ";
      }
    else if (viewDbg==2)
      {
      str1=NumToStr(prevWaited);
      str2=NumToStr(prevLft);
      str3=NumToStr(prevRht);
      str4=NumToStr(prevDrp);
      str5=NumToStr(prevRot);
      msg1="  pW ";
      msg2="  pL ";
      msg3="  pR ";
      msg4="  pD ";
      msg5="  pR ";
      }
    else if (viewDbg==3)
      {
      str1=NumToStr(currentPiece);
      str2=NumToStr(currentRotate);
      str3=NumToStr(tetLR);
      str4=NumToStr(tetUD);
      msg1="  cP ";
      msg2="  cR ";
      msg3="  tL ";
      msg4="  tU ";
      }
    else if (viewDbg==4)
      {
      str1=NumToStr(drop);
      str2=NumToStr(alive);
      str3=NumToStr(prevQuadClear);
      str4=NumToStr(highMade);
      msg1="  dp ";
      msg2="  lv ";
      msg3="  pQ ";
      msg4="  hM ";
      }
    result=StrCat(msg1,str1,msg2,str2,msg3,str3,msg4,str4,msg5,str5);
    SendResponseString(9,result);
    Wait(60);
    }
  }


void debug(int INmode)
  {
  prevQuadClear=false;
  prevLft=0;
  prevRht=0;
  selectGame(1);
  initArrays();
  score=Random(LONG_MAX-10000)+10000;
  ClearScreen();

  if (INmode==2) //ClearFullRows()
    {
    for (int i=0; i<height; i++)
      {
      for (int j=0; j<width; j++)
        {
        area[j][i]=(Random(8)!=0);
        }
      }
    //PlayTone(1000,800);Wait(1000);
    inputOutput(false,false,true,0);
    Wait(3000);
    int i=clearFullRows();
    ClearScreen();
    Wait(250);
    inputOutput(false,false,true,0);
    NumOut(0,48,i,0);
    while(1){}
    }

  else if (INmode==3) //displayTetromino()
    {
    int tets,angl,k;
    for (tets=0; tets<7; tets++)
      {
      for (angl=0; angl<4; angl++)
        {
        ClearScreen();
        displayTetromino(tets*4,angl,0,0,0);
        Wait(500);
        until (!ButtonPressed(3)){}
        }
      }
    }

  else if (INmode==4) //peiceSetinto()
    {
    pieceCreate();
    tetUD=10;
    pieceSetInto();
    inputOutput(false,false,true,0);
    Wait(3000);
    debugStream(0);
    ClearScreen();
    displayTetromino(currentPiece,currentRotate,tetLR*blksz,tetUD*blksz,1);
    Wait(500);
    inputOutput(false,false,true,0);
    Wait(3000);
    }
  else if (INmode==5) //peiceCreate()
    {
    while (1)
      {
      pieceCreate();
      ClearScreen();
      NumOut(0,48,currentPiece,4096);
      NumOut(0,40,nextPiece[0],4096);
      NumOut(0,32,nextPiece[1],4096);
      NumOut(0,24,nextPiece[2],4096);
      Wait(400);
      }
    }
  else if (INmode==6) //gravity
    {
    pieceCreate();
    while(1)
      {
      ClearScreen();
      inputOutput(false,false,true,0);
      Wait(1000);
      tetUD--;
      }
    }
  }
*/
//  END   _    __   __          __
//       | \  |    |  )  |  |  /  \
//       | |  |--  |-<   |  |  |  __
//       |_/  |__  |__)  \__/  \__/
//      ============================

//Modes:
//0  normal
//1  fast
//2  debug clearFullRows()
//3  dubug rotation
//4  debug peiceSetinto()
//5  debug peiceCreate()
//6  debug gravity in inputOutput()

int main()
  {
  int mode=defaultmode;
  srand(time(0));
  /*while (!ButtonPressed(3))
    {
    mode=senseButton(mode,true,1,6,false);
    NumOut(48,0,mode,0);
    }
  until (!ButtonPressed(3)) {}*/
  if (mode==0||mode==1)
    {
    //SetLongAbort(true);
    bool playagain=true;
    bool piecemoving;
    while (playagain)
      {
      ClearScreen();
      selectGame(1);
      initArrays();
      selectGame(mode);
      alive=true;
      while (alive)
        {
        resetVars();
        pieceCreate();
        piecemoving=move(dwn,tetUD); //If a piece was made where it...
        alive=piecemoving;           //can't move down, end the game.
        if (alive) ClearScreen();
        for (int i=0; piecemoving; i++) //waiting
          {
          piecemoving=inputOutput(true,true,true,i);
          Wait(10);
          //debugStream(i);
          }
        delaytime*=speedup;
        pieceSetInto();
        clearFullRows();
        }
      playagain=gameEnd();
      }
    }
  else
    {
    //debug(mode);
    }
  }

/*
BUGS
crashes a few min into the game (NOT DUE TO MEMORY)
cant see piece well while soft dropping


Process Order:
-Rotation
-Move
-Drop
-Gravity


Soft Drop               DONE
Hard Drop               DONE
Clockwise Rotation      DONE
Right Side Bias         DONE
Delayed Auto Shift      DONE
Wall kicks              DONE

Allow only 1 floor kick                                DELETED (Don't Like)
Allow I wall kicking always.                           DONE
Allow I floor kicking even when not touching ground    DONE

Adhere to SRS guidelines, some ARS guidelines
  http://tetris.wikia.com/wiki/SRS
  http://tetris.wikia.com/wiki/ARS

*/
