/* BEGIN	_ _				__
 *				 |		 /	/	\
 *				 |		/	 |	|
 *				_|_	/		\__/
 *			 ================
 */

bool inputOutput(bool INallowInput, bool INallowOutput, int INwaited)
	{
	bool temppiecemoving=true; //return this
	//refresh the screen: 0=no, 1=piece, 2=score+piece, 3=everything

	SDL_FillRect(screen,NULL,cBack);
	drawrect.h = BlockSize;
	drawrect.w = BlockSize;

//INPUT
//INPUT
	if (INallowInput)
		{
		char btnPressed=0;
		SDL_Event test_event;
		/*while(SDL_PollEvent(&test_event)) //GET INPUT
			{*/
		if (test_event.key.state == SDL_PRESSED)
			btnPressed=test_event.key.keysym.sym;
			/*}*/
	
		if (btnPressed==BTN_H_DROP)
			{
			lockDelay=0;
			drop=dropWHard;
			}
		else if (btnPressed==BTN_S_DROP)
			{
			lockDelay=0;
			drop=dropSoft;
			prevDrp++;
			}
		else
			{
			prevDrp=0;
			if (drop==dropWHard)
				{
				drop=dropHard;
				lockDelay=waitLock;
				}
			else
				drop=0;
			}
		
		if (btnPressed==BTN_ROTATE)
			{
			if (prevRot==0)
				{
				if (rotate())
					{
					lockDelay=0;
					refresh=true;
					currentRotate++;
					if (currentRotate>=4)
						currentRotate=0;
					}
				}
			prevRot++;
			if (prevRot>waitRotateAgain)
				prevRot=0;
			}
		else
			{
			prevRot=0;
			}
		
		if (btnPressed==BTN_MOVE_LEFT)
			{
			prevLft++;
			if ((prevLft>=waitSlowMove || prevLft<0) && move(lft,tetUD))
				{
				lockDelay=0;
				if (prevLft<0)
					prevLft=0;
				else
					prevLft=waitSlowMove-waitFastMove;
				tetLR++;
				refresh=true;
				}
			}
		else
			{
			prevLft=-5;
			}
		
		if (btnPressed==BTN_MOVE_RIGHT)
			{
			prevRht++;
			if ((prevRht>=waitSlowMove || prevRht<0) && move(rht,tetUD))
				{
				lockDelay=0;
				if (prevRht<0)
					prevRht=0;
				else
					prevRht=waitSlowMove-waitFastMove;
				tetLR--;
				refresh=true;
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
		if (drop==dropHard)																									 //HARD DROP
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
					if (lockDelay>=waitLock)
						temppiecemoving=false;
					}
				}
			refresh=true;
			drop=0;
			}
		if ((INwaited%waitGravity<=prevWaited%waitGravity) || drop==dropSoft) //SOFT DROP or GRAVITY
			{
			if (drop==dropSoft)
				score++;
			refresh=true;
			if (move(dwn,tetUD))
				tetUD--;
			else
				lockDelay++;
			if (lockDelay>=waitLock)
				{
				temppiecemoving=false;
				lockDelay=0;
				}
			drop=0;
			}
		prevWaited=INwaited;
		if (score>readHigh(accesshigh))
			{
			writeHigh(accesshigh,score);
			highMade=true;
			}
		}
	return temppiecemoving; //THIS LINE WAS ADDED LATER
	}



void boardDraw(bool INallowDraw)
	{
	if (INallowDraw)											//refresh the screen:
		{		//0=nothing	 //1=piece	 //2=area	 //3=everything
		if		(refresh==1) RectOut(tetUD*blksz,tetLR*blksz,blksz*5,blksz*4,36); //Fill+Invert
		else if (refresh==2) RectOut(0,0,height*blksz,width*blksz,36); //Fill+Invert
		else if (refresh==3) ClearScreen();

/*void snakeDraw()
	{
	SDL_FillRect(screen,NULL,cBack);
	drawrect.h = BlockSize;
	drawrect.w = BlockSize;
	for (int y=0;y<HeightBlocks;y++)
		{
		for (int x=0;x<WidthBlocks;x++)
			{
			if (board[x][y]>0) //Snake
				{
				drawrect.x = x*BlockSize;
				drawrect.y = y*BlockSize;
				SDL_FillRect(screen , &drawrect , cSnake);
				}
			if (board[x][y]<0) //Food
				{
				drawrect.x = x*BlockSize;
				drawrect.y = y*BlockSize;
				SDL_FillRect(screen , &drawrect , cFood);
				}
			}
		}
	SDL_Flip(screen);
	}*/

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
		for (int y=0;y<HeightBlocks;y++)
			{
			for (int x=0;x<WidthBlocks;x++)
				{
				if (area[x][y]>0) //Snake
					{
					drawrect.x = x*BlockSize;
					drawrect.y = y*BlockSize;
					SDL_FillRect(screen, &drawrect , color[area[x][y]]);
					}
				}
			}
		//NEXT PIECES / MESSAGE

		for (i=0; i<previewPieces; i++)
			{							//		tet			rot			 lr					 ud																	draw
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


/*	END	 _ _				__
 *				 |		 /	/	\
 *				 |		/	 |	|
 *				_|_	/		\__/
 *			 ================
 */
