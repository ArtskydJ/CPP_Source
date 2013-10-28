#define cBack   SDL_MapRGB(screen->format,225,225,225)
#define cGhost  SDL_MapRGB(screen->format,000,200,000)
#define SCR_WIDTH  640
#define SCR_HEIGHT 480
#define SCR_BPP    32

//Dimensions / Graphics
#define blksz   40
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

#define BlockSize    40
#define WidthBlocks  16
#define HeightBlocks 12
//Buttons
#define BTN_H_DROP		SDLK_KP2
#define BTN_S_DROP		SDLK_KP5
#define BTN_ROTATE		SDLK_KP8
#define BTN_MOVE_LEFT	SDLK_KP4
#define BTN_MOVE_RIGHT	SDLK_KP6

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

//					PROTOTYPES
bool inputOutput();

//					GLOBAL CONSTANTS
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
bool refresh=0;

//START  ARRAYS
char area[width][height+2]; //Two hidden rows
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
//these were strings:
int msg        =0;
int disp       =0;
int accesshigh =0;

SDL_Surface *screen=NULL;
SDL_Rect drawrect;

using namespace std;
