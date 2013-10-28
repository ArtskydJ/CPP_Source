//Binary Clock
//Joseph Dykstra
//2012-03-23

#include <iostream>
#include <time.h>
#include <string>
#include "SDL/SDL.h"

#define SCREEN_WIDTH  300
#define SCREEN_HEIGHT 300
#define SCREEN_BPP    32
#define cRed   SDL_MapRGB(screen->format,255,000,000)
#define cBlue  SDL_MapRGB(screen->format,000,255,000)
#define cWhite SDL_MapRGB(screen->format,225,225,225)
//#define color 70

int main(int arc, char *argv[])
  {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_WM_SetCaption("Oh yeah, SDL", NULL);
  SDL_Surface *screen = NULL;
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  if (screen == NULL) return 21;
    //Uint32 color;
    SDL_Rect rectan;
    rectan.x = 100;
    rectan.y = 100;
    rectan.h = 100;
    rectan.w = 100;
    //color = SDL_MapRGB(blu);
    SDL_FillRect(screen , NULL , cBlue);
    //color = SDL_MapRGB(red);
    SDL_FillRect(screen , &rectan , cRed);
    SDL_Flip(screen);
    SDL_Delay(1000);
  SDL_Quit();
  return 0;
  }
