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
		/*
		while (ButtonPressed(BTNRIGHT)==false)
			{
			gamespeed=senseButton(gamespeed,false,1,2,false);
			ClearScreen();
			TextOutput(TX,LCD_LINE1,0,0);
			RectOut(0,40-(gamespeed*8),49,8,0);
			Wait(50);
			}
		//TextOutput(TX,LCD_LINE1,"TETRIS",	0);
		while (ButtonPressed(BTNRIGHT)) {}
		while (ButtonPressed(BTNRIGHT)==false)
			{
			gametype=senseButton(gametype,false,1,4,false);
			ClearScreen();
			TextOutput(TX,LCD_LINE1,0,0);
			RectOut(0,40-(gametype*8),49,8,0);
			Wait(50);
			}
		*/
		}
	//TextOutput(TX,LCD_LINE1,"TETRIS",	0);
	//while (ButtonPressed(BTNRIGHT)) {}


	if			(gamespeed==0)
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
	if			(gametype==0)
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



void displayTetromino(int INtet,int INrot, int INlr, int INud, int INdrawMode)
	{
	int tempLR,tempUD;
	for (int i=0; i<4; i++)
		{
		tempLR=INlr+(tet[INtet+INrot][i	])*blksz;
		tempUD=INud+(tet[INtet+INrot][i+4])*blksz;
		if		(INdrawMode==0) RectOut(tempUD,tempLR,blksz,blksz,32);
		else if (INdrawMode==1) RectOut(tempUD,tempLR,blksz,blksz,0);
		else if (INdrawMode==2) CircleOut(tempUD+blksz/2,tempLR+blksz/2,blksz/2-1,32);
		}
	}

void initArrays()
	{
	Uint16 color[8]=
		{
		SDL_MapRGB(screen->format,222,222,222),	//Background
		SDL_MapRGB(screen->format,000,000,255), //ctetI
		SDL_MapRGB(screen->format,000,000,255), //ctetJ
		SDL_MapRGB(screen->format,000,000,255), //ctetL
		SDL_MapRGB(screen->format,000,000,255), //ctetO
		SDL_MapRGB(screen->format,000,000,255), //ctetS
		SDL_MapRGB(screen->format,000,000,255), //ctetT
		SDL_MapRGB(screen->format,000,000,255), //ctetZ
		};
	
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
	showDisp		=0;
	viewDbg			=0;
	gametype		=0;
	gamespeed		=0;
	delaytime		=0;
	lockDelay		=0;
	prevRht			=0;
	prevLft			=0;
	prevDrp			=0;
	prevRot			=0;
	currentPiece	=0;
	currentRotate 	=0;
	tetLR			=0;
	tetUD			=0;
	drop			=0;
	prevWaited		=0;
	speedup			=0;
	score			=0;
	msg				=0;
	disp			=0;
	accesshigh		=0;
}


void resetVars()
	{
	lockDelay		= 0;
	prevRht			= 0;
	prevLft			= 0;
	prevDrp			= 0;
	prevRot			= 0;
	currentRotate	= 0;
	prevWaited		= 0;
	currentRotate	= 0;
	drop			= 0;
	lockDelay		= 0;
	floorKickUsed	= 0;
	tetLR=width/2-2;
	tetUD=height;
	SDL_WM_SetCaption("TETRIS | Score:0 | Joseph Dykstra", NULL);
	}

	
bool gameEnd()
	{
	disp=888;
	inputOutput(0,0,0);
	bool plyagn=false;
	Wait(2500);
	ClearScreen();
	if (highMade) writeHighName(accesshigh,score);
	ClearScreen();
	/*TextOutput(TX,LCD_LINE1,"TETRIS",	0);
	TextOutput(0,LCD_LINE4,StrCat("S:",NumToStr(score)),0);
	TextOutput(0,LCD_LINE5,StrCat("HS:",NumToStr( readHigh(accesshigh) )),0);
	msg=readHighName(accesshigh);
	TextOutput(0,LCD_LINE6,StrCat("N:",msg),0);
	TextOutput(5,LCD_LINE8,"Yes	Again?	No",0);
	until (ButtonPressed(BTNLEFT)==false
		 && ButtonPressed(BTNRIGHT)==false) {}
	until (ButtonPressed(BTNLEFT)==true
		 || ButtonPressed(BTNRIGHT)==true)	{}
	plyagn=ButtonPressed(BTNLEFT)==true;
	until (ButtonPressed(BTNLEFT)==false
		 && ButtonPressed(BTNRIGHT)==false) {}*/
	return plyagn;
	}
	
	
int set()
	{
	int ret=SDL_Init(SDL_INIT_VIDEO);
	if (ret==0)
		{
		//Allow cout
		freopen( "CON", "w", stdout );
		freopen( "CON", "w", stderr );
		cout<<"hi";
		//Graphics
		SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,SDL_DEFAULT_REPEAT_INTERVAL);
		//screen = SDL_SetVideoMode(SCR_WIDTH,SCR_HEIGHT,SCR_BPP,SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_ANYFORMAT);
		screen = SDL_SetVideoMode(SCR_WIDTH,SCR_HEIGHT,SCR_BPP,SDL_SWSURFACE);
		}
	return ret;
	}