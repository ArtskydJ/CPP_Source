//Tetris
//Joseph Dykstra
//Port started 07-15-2013
//Finished ??-??-2013
#include "C:/SDL/include/SDL/SDL.h"
#include <iostream>
#include <iostream>
#include <ctime>
#include <string>

#include "DefinitionsAndData.cpp"
#include "SmallFunctions.cpp"
#include "InitAndQuit.cpp"
#include "TetrominoManip.cpp"
#include "InputOutputAndDraw.cpp"
//#inlcude "Debug.cpp"


/*Modes:
 *0	normal
 *1	fast
 *2	debug clearFullRows()
 *3	dubug rotation
 *4	debug peiceSetinto()
 *5	debug peiceCreate()
 *6	debug gravity in inputOutput()
 */



int main(int argc, char *argv[])
	{
	int go=set();
	if (go==0)
		{
		int mode=defaultmode;
		srand(std::time(0));
		if (mode==0||mode==1)
			{
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
					alive=piecemoving;					 //can't move down, end the game.
					if (alive) ClearScreen();
					for (int i=0; piecemoving; i++) //waiting
						{
						piecemoving=inputOutput(true,true,true,i);
						SDL_Delay(10);
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
	SDL_Quit();
	return go;
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


Soft Drop							 DONE
Hard Drop							 DONE
Clockwise Rotation			DONE
Right Side Bias				 DONE
Delayed Auto Shift			DONE
Wall kicks							DONE

Allow only 1 floor kick																DELETED (Don't Like)
Allow I wall kicking always.													 DONE
Allow I floor kicking even when not touching ground		DONE

Adhere to SRS guidelines, some ARS guidelines
	http://tetris.wikia.com/wiki/SRS
	http://tetris.wikia.com/wiki/ARS

*/
